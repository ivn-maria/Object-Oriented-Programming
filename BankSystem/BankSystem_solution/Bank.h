#ifndef BANK_SYSTEM_BANK_H
#define BANK_SYSTEM_BANK_H

#include "Customer.h"

class Bank
{
    char* name;
    char* address;
    Customer** customers;
    Account** accounts;
    char* log;

    int countOfCustomers;
    int capacityOfCustomers;
    int countOfAccounts;
    int capacityOfAccounts;

    void copyFrom(const Bank&);
    void free();

    void resizeCustomers();
    void resizeAccounts();

    void addAccount(Account*&);

public:
    Bank();
    Bank(const Bank&);
    Bank(char*, char*);
    Bank& operator=(const Bank&);
    ~Bank();

    friend std::ostream& operator<<(std::ostream&, const Bank&);

    char* getLog();
    void setLog(char*);
    void exportLog(char*);

    void addCustomer(Customer*&);
    void deleteCustomer(int);
    void addNormalAccount(char*, char*, char*, int, double, char*);
    void addPrivilegeAccount(char*, char*, char*, int, double, char*, double);
    void addSavingsAccount(char*, char*, char*, int, double, char*, double);
    void deleteAccount(char*);

    void listCustomers();
    void listAccounts();
    void listCustomerAccount(int);

    bool transfer(double, char*, char*);
    bool withdrawFrom(char*, double);
    bool depositTo(char*, double);
    void display() const;

    Customer* findCustomerByID(int ID);
    Account** findAccountByID(int ID);
    Account* findAccountByIBAN(const char* iban);
};

#endif //BANK_SYSTEM_BANK_H


