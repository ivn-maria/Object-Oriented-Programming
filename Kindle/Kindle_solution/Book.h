#ifndef KINDLE_BOOK_H
#define KINDLE_BOOK_H

#include "Page.h"

class Book {
private:
    string author;
    string title;
    vector<pair<string, unsigned>> ratings;
    vector<Page> data;
    vector<pair<string, string>> comments;

    void addRating(unsigned short r, const string& name);

    void write(unsigned pagesCount);
    void displayBook() const;

    void showComments() const;
    void showRates() const;
    void print() const;
    static void displayHelpMenu() ;
public:
    Book() = default;
    Book(const string& author, const string& title);

    void writeToFile(std::ofstream& outFile) const;
    void readFromFile(std::ifstream& inFile);
    double getAverageRating() const;

    friend class Kindle;
};

#endif //KINDLE_BOOK_H
