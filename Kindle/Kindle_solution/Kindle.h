#ifndef KINDLE_KINDLE_H
#define KINDLE_KINDLE_H

#include "User.h"

class Kindle {
private:
    vector<Book> lib;
    vector<User> users;

    int findBookIndex(const string& name) const;
    int findUserIndex(const string& name) const;

    static bool userReadTheBook(const User& currentUser, int bookIndex) ;

    bool existUser(const string& userName) const;

    void readBookDialog(User& reader);
    void writeBookDialog(User& writer);

    void rateBookDialog(const User& rater);
    void commentOnBookDialog(const User& commenter);

    void displayCommentsDialog() const;
    void displayRatesDialog() const;

    void displayLoginDialog();
    void displaySignupDialog();
    void displayUserDialog(User& currentUser);

    void saveFileDialog() const;
    void readFileDialog();

    void viewBooks() const;
    static void showHelpDialog() ;

    void saveToFile(const char* filePath) const;
    void readFromFile(const char* filePath);
public:
    void display();
};

#endif //KINDLE_KINDLE_H
