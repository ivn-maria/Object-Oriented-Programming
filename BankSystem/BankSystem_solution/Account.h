#ifndef BANK_SYSTEM_ACCOUNT_H
#define BANK_SYSTEM_ACCOUNT_H

#include <iostream>
using namespace std;

class Account
{
protected:
    enum Type{
        Normal,
        Privilege,
        Savings,
        Unknown
    }type;
private:
   char* username;
   char* password;
   char* iban;
   int Id;
   double amount;
   char* dataOfCreation;

   void copyFrom(const Account&);
   void free();

public:
    Account();
    Account(const Account&);
    Account(char*, char*, char*, int, double, char*);
    Account& operator=(const Account&);
    virtual ~Account() = default;

    friend std::ostream& operator<<(std::ostream&, const Account&);

    void setAmount(double);
    char* getUsername()const;
    char* getIban() const;
    int getId() const;
    double getBalance() const;
    char* getDataOfCreation() const;

    virtual void deposit(double) = 0;
    virtual bool withdraw(double) = 0;
    virtual void display() const = 0;
    virtual Account* clone() const = 0;
};

#endif //BANK_SYSTEM_ACCOUNT_H
