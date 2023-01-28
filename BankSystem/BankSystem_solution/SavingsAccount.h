#ifndef BANK_SYSTEM_SAVINGSACCOUNT_H
#define BANK_SYSTEM_SAVINGSACCOUNT_H

#include "Account.h"

class SavingsAccount: public Account
{
    double interestRate;

public:
    SavingsAccount();
    SavingsAccount(char*, char*, char*, int, double, char*, double);

    void deposit(double) override;
    bool withdraw(double) override;
    void display() const override;
    Account* clone() const override;
};

#endif //BANK_SYSTEM_SAVINGSACCOUNT_H
