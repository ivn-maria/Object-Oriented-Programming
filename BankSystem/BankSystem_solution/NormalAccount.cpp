#include "NormalAccount.h"

NormalAccount::NormalAccount():Account()
{
    type = Type::Normal;
}

NormalAccount::NormalAccount(char* username, char* password, char* iban, int Id, double amount, char* dateOfCreation)
        : Account(username, password, iban, Id, amount, dateOfCreation)
{
    type = Type::Normal;
}

void NormalAccount::deposit(double add)
{
    this->setAmount(this->getBalance() + add);
}

bool NormalAccount::withdraw(double sub)
{
    if(this->getBalance() >= sub) {
        this->setAmount(this->getBalance() - sub);
        return true;
    } else return false;
}

void NormalAccount::display() const
{
    cout << "Type:: " << this->type << endl;
    cout << "Iban: " << this->getIban() << endl;
    cout << "Id: " << this->getId() << endl;
    cout << "Amount: " << this->getBalance() << endl;
    cout << "Data of creation: " << this->getDataOfCreation() << endl;
}

Account* NormalAccount::clone() const
{
    return new NormalAccount(*this);
}