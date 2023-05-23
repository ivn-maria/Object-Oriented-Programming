#ifndef KINDLE_USER_H
#define KINDLE_USER_H

#include "Book.h"
using namespace std;

class User {
private:
    string name;
    string password;
    vector<size_t> indexesOfBooksRead;
    vector<size_t> indexesOfBooksWritten;

    friend class Kindle;
public:
    User() = default;
    User(const string& pName, const string& pPassword);

    void writeToFile(std::ofstream& outFile) const;
    void readFromFile(std::ifstream& inFile);

    string getName() const;
};

#endif //KINDLE_USER_H
