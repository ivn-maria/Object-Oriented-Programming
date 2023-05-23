#ifndef KINDLE_PAGE_H
#define KINDLE_PAGE_H

#include <iostream>
#include <fstream>
#include <vector>
#include "serialize.h"
using namespace std;

class Page {
private:
    vector<string> lines;

    void write(unsigned linesCount);
    void displayPage() const;

    void writeToFile(std::ofstream& outFile) const;
    void readFromFile(std::ifstream& inFile);

    friend class Book;
};

#endif //KINDLE_PAGE_H
