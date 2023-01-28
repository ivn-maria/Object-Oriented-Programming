#ifndef HW1_1_HEXVIEWER_H
#define HW1_1_HEXVIEWER_H

#include <iostream>
#include <fstream>
using namespace std;

class HexViewer
{
    unsigned char* data;
    size_t size;

public:
    explicit HexViewer(const char* fileName);

    HexViewer(const HexViewer&) = default;
    HexViewer& operator=(const HexViewer&) = delete;

    size_t getSize() const;

    void addByte(const char* byte);
    void removeLastByte();
    void changeByte(size_t index, const char* byte);

    void saveAs(const char* fileName) const;

    void print() const;
    ~HexViewer();
};

#endif //HW1_1_HEXVIEWER_H
