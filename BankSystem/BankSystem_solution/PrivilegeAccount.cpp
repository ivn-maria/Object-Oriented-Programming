#include "PrivilegeAccount.h"

PrivilegeAccount::PrivilegeAccount(): Account()
{
    type = Type::Privilege;
    overdraft = 0;
}

PrivilegeAccount::PrivilegeAccount(char* username, char* password, char* iban, int Id, double amount,
                                   char* dateOfCreation, double overdraft): Account(username, password, iban, Id, amount, dateOfCreation)
{
    type = Type::Privilege;
    this->overdraft = overdraft;
}

void PrivilegeAccount::deposit(double add)
{
    this->setAmount(this->getBalance() + add);
}

bool PrivilegeAccount::withdraw(double sub)
{
    if(this->getBalance() + overdraft < sub)
        return false;
    else
    {
        setAmount(this->getBalance() - sub);
        return true;
    }
}

void PrivilegeAccount::display() const
{
    cout << "Type:: " << this->type << endl;
    cout << "Iban: " << this->getIban() << endl;
    cout << "Id: " << this->getId() << endl;
    cout << "Amount: " << this->getBalance() << endl;
    cout << "Data of creation: " << this->getDataOfCreation() << endl;
}

Account* PrivilegeAccount::clone() const
{
    return new PrivilegeAccount(*this);
}