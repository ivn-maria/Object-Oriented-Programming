#ifndef BANK_SYSTEM_NORMALACCOUNT_H
#define BANK_SYSTEM_NORMALACCOUNT_H

#include "Account.h"

class NormalAccount: public Account
{
public:
    NormalAccount();
    NormalAccount(char*, char*, char*, int, double, char*);

    void deposit(double) override;
    bool withdraw(double) override;
    void display() const override;
    Account* clone() const override;
};

#endif //BANK_SYSTEM_NORMALACCOUNT_H
