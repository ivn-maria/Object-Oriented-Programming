#ifndef XMLFMI_PARSE_H
#define XMLFMI_PARSE_H

int parseInt(const char charArray[])
{
    int i = 0, data = 0;

    while(true)
    {
        if(charArray[i] == '\0')
            break;

        data = data * 10 + (charArray[i] - '0');
        i++;
    }

    return data;
}

double parseDouble(const char charArray[])
{
    bool commaFound = false;
    int result = 0, i = 0, length = 1;

    while(true)
    {
        if(charArray[i] == '\0')
            break;

        if(charArray[i] == '.')
        {
            commaFound = true;
            i++;
            continue;
        }

        if(commaFound)
            length *= 10;

        result = result * 10 + (charArray[i] - '0');
        i++;
    }

    return (double) result / length;
}

#endif //XMLFMI_PARSE_H
