#include "Page.h"

void Page::write(unsigned linesCount)
{
    if (linesCount > 26)
        linesCount = 26;


    for (size_t i = 0; i < linesCount; i++)
    {
        std::cout << i + 1 << " ";
        lines.emplace_back();
        getline(std::cin, lines[i]);
    }
}

void Page::displayPage() const
{
    for (const auto & line : lines)
        std::cout << line << std::endl;
}

void Page::writeToFile(std::ofstream& outFile) const
{
    size_t len = lines.size();
    outFile.write((const char*)&len, sizeof(len));

    for (size_t i = 0; i < len; i++)
        writeString(outFile, lines[i]);
}

void Page::readFromFile(std::ifstream& inFile)
{
    size_t len = 0;
    inFile.read((char*)&len, sizeof(len));

    for (size_t i = 0; i < len; i++) {
        string s = readString(inFile);
        lines.push_back(std::move(s));
    }
}
