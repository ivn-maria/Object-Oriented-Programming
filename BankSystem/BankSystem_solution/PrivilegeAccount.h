#ifndef BANK_SYSTEM_PRIVILEGEACCOUNT_H
#define BANK_SYSTEM_PRIVILEGEACCOUNT_H

#include "Account.h"

class PrivilegeAccount: public Account
{
    double overdraft;

public:
    PrivilegeAccount();
    PrivilegeAccount(char*, char*, char*, int, double, char*, double);

    void deposit(double ) override;
    bool withdraw(double ) override;
    void display() const override;
    Account* clone() const override;
};

#endif //BANK_SYSTEM_PRIVILEGEACCOUNT_H
