#include "HexViewer.h"

size_t getFileSize(std::ifstream& f)
{
    size_t currentPos = f.tellg();
    f.seekg(0, std::ios::end);
    size_t size = f.tellg();
    f.seekg(currentPos);

    return size;
}

HexViewer::HexViewer(const char* fileName)
{
    ifstream file(fileName, std::ios::binary);
    if (!file.is_open())
    {
        size = 0;
        data = nullptr;
        return;
    }
    size_t bytesCount = getFileSize(file);
    data = new unsigned char[bytesCount];

    file.read((char*)data, bytesCount);
    size = bytesCount;
}

size_t HexViewer::getSize() const
{
    return size;
}

unsigned char convertSymbolToNumber(char symbol)
{
    if (symbol >= '0' && symbol <= '9')
        return symbol - '0';
    else if (symbol >= 'A' && symbol <= 'Z')
        return symbol - 'A' + 10;
    return '\0';
}

void resize(unsigned char*& data, size_t& size, size_t newSize)
{
    auto* newDataArr = new unsigned char[newSize];

    size_t minSize = std::min(size, newSize);
    for (unsigned i = 0; i < minSize; i++)
        newDataArr[i] = data[i];

    delete[] data;
    data = newDataArr;
    size = newSize;
}

void HexViewer::addByte(const char* byteStr)
{
    if (strlen(byteStr) != 2)
        return;
    unsigned char currentByte = 16*convertSymbolToNumber(byteStr[0]) + convertSymbolToNumber(byteStr[1]);
    resize(data, size, size + 1);
    data[size - 1] = currentByte;
}

void HexViewer::removeLastByte()
{
    if (size == 0)
        return;
    resize(data, size, size - 1);

}

void HexViewer::changeByte(size_t index, const char* byteStr)
{
    if (index >= size || strlen(byteStr) != 2)
        return;

    unsigned char currentByte = convertSymbolToNumber(byteStr[1]) + 16 * convertSymbolToNumber(byteStr[0]);
    data[index] = currentByte;
}

void HexViewer::saveAs(const char* fileName) const
{
    ofstream file(fileName, std::ios::binary);

    if (!file.is_open())
        return;
    file.write((const char*)data, size);
}

void convertToHex(unsigned char byte, char* byteHex)
{
    char symbols[] = { '0','1', '2', '3', '4', '5', '6','7',
                       '8','9', 'A', 'B', 'C', 'D', 'E', 'F' };
    byteHex[2] = '\0';
    byteHex[1] = symbols[byte % 16];
    byteHex[0] = symbols[(byte / 16) % 16];
}

bool isLetter(char ch)
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

void HexViewer::print() const
{
    for (unsigned i = 0; i < size; i++)
    {
        char byteHex[3];
        convertToHex(data[i], byteHex);
        cout << byteHex << " ";
    }
    cout << std::endl;
    for (unsigned i = 0; i < size; i++)
    {
        if (isLetter(data[i]))
            cout << data[i];
        else
            cout << ".";
        cout << "  ";
    }
    cout << endl;
}

HexViewer::~HexViewer()
{
    delete[] data;
}
