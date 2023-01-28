#include"serialize.h"

void getLine(std::istream& outFile, string& str)
{
    str.clear();

    char buff[1024];
    outFile.getline(buff, 1024, '\n');
    size_t len = strlen(buff);
    str = new char[len + 1];

    for (size_t i = 0; i < len; i++)
        str[i] = buff[i];
    str[len] = '\0';
}

void writeString(std::ofstream& outFile, const string& str)
{
    size_t len = str.size();
    outFile.write((const char*)&len, sizeof(int));

    outFile.write(str.c_str(), sizeof(char) * len);
}

string readString(std::ifstream& inFile)
{
    int len = 0;
    inFile.read((char*)&len, sizeof(len));

    char* buff = new char[len + 1];
    inFile.read(buff, sizeof(char) * len);

    buff[len] = '\0';

    string toReturn(buff);

    delete[] buff;

    return toReturn;
}

void writeVector(std::ofstream& outFile, const vector<size_t>& v)
{
    size_t len = v.size();
    outFile.write((const char*)&len, sizeof(int));

    for (const unsigned long & i : v)
        outFile.write((const char*)&i, sizeof(size_t));
}

vector<size_t> readVector(std::ifstream& inFile)
{
    int len = 0;
    inFile.read((char*)&len, sizeof(int));
    vector<size_t> toReturn;
    size_t read = 0;

    for (size_t i = 0; i < len; i++) {
        inFile.read((char*)&read, sizeof(size_t));
        toReturn.push_back(read);
    }

    return toReturn;
}

void writeCommentsToFile(std::ofstream& outFile, const pair<string, string>& p)
{
    writeString(outFile, p.first);
    writeString(outFile, p.second);
}

pair<string, string> readCommentsFromFile(std::ifstream& inFile)
{
    string fst = readString(inFile);
    string snd = readString(inFile);

    return { fst, snd };
}

void writeRatesToFile(std::ofstream& outFile, const pair<string, unsigned>& comments)
{
    writeString(outFile, comments.first);
    outFile.write((const char*)&comments.second, sizeof(comments.second));
}

pair<string, unsigned> readRatesFromFile(std::ifstream& inFile)
{
    string fst = readString(inFile);
    unsigned rate = 0;
    inFile.read((char*)&rate, sizeof(rate));

    return { fst, rate };
}