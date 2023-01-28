#ifndef HEXVIEWER_OPERATIONS_H
#define HEXVIEWER_OPERATIONS_H

#include <iostream>
using namespace std;

bool compare(const char str1[], const char str2[])
{
    int i = 0, check = 0;
    while(str1[i] != '\0' || str2[i] != '\0')
    {
        if(str1[i] != str2[i])
        {
            check = 1;
            break;
        }
        i++;
    }
    if(check == 0)
        return true;
    return false;
}

void operations(HexViewer h)
{
    char choice[20];
    cout << "Choose operation: view, change, remove, add, save ot save_as:" << endl;
    cin >> choice;

    if(compare(choice, "view"))
    {
        h.print();

        operations(h);
    }
    else if(compare(choice, "change"))
    {
        int index;
        cout << "Write which index to change:" << endl;
        cin >> index;

        char value[10];
        cout << "Write to what value to change:" << endl;
        cin >> value;

        h.changeByte(index, value);

        operations(h);
    }
    else if(compare(choice, "remove"))
    {
        h.removeLastByte();
        h.print();

        operations(h);
    }
    else if(compare(choice, "add"))
    {
        char value[10];
        cout << "Write value to add:" << endl;
        cin >> value;

        h.addByte(value);
        h.print();

        operations(h);
    }
    else if(compare(choice, "save"))
    {
        cout << "File saved successfully." << endl;

        operations(h);
    }
    else if(compare(choice, "save_as"))
    {
        char newFile[100];
        cout << "Enter where you want to save the changes:" << endl;
        cin >> newFile;

        h.saveAs(newFile);
        cout << "File saved successfully." << endl;

        operations(h);
    }
}

#endif //HEXVIEWER_OPERATIONS_H
