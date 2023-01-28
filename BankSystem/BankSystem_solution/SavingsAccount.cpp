#include "SavingsAccount.h"

SavingsAccount::SavingsAccount()
{
    type = Type::Savings;
    interestRate = 0;
}

SavingsAccount::SavingsAccount(char* username, char* password, char* iban, int Id, double amount, char* dateOfCreation,
                               double interestRate): Account(username, password, iban, Id, amount, dateOfCreation)
{
    type = Type::Savings;
    this->interestRate = interestRate;
}

void SavingsAccount::deposit(double add)
{
    this->setAmount(this->getBalance() + add);
}

bool SavingsAccount::withdraw(double)
{
    return false;
}

void SavingsAccount::display() const
{
    cout << "Type: " << this->type << endl;
    cout << "Iban: " << this->getIban() << endl;
    cout << "Id: " << this->getId() << endl;
    cout << "Amount: " << this->getBalance() << endl;
    cout << "Data of creation: " << this->getDataOfCreation() << endl;
}

Account* SavingsAccount::clone() const
{
    return new SavingsAccount(*this);
}