#include "Account.h"

void Account::copyFrom(const Account& other)
{
    type = other.type;
    username = new char[strlen(other.username) + 1];
    strcpy(username, other.username);
    password = new char[strlen(other.password) + 1];
    strcpy(password, other.password);
    iban = new char[strlen(other.iban) + 1];
    strcpy(iban, other.iban);
    Id = other.Id;
    amount = other.amount;
    dataOfCreation = new char[strlen(other.dataOfCreation) + 1];
    strcpy(dataOfCreation, other.dataOfCreation);
}

void Account::free()
{
    delete[] username;
    delete[] password;
    delete[] iban;
    delete[] dataOfCreation;
}

Account::Account()
{
    type = Type::Unknown;
    username = new char[1];
    username[0] = '\0';
    password = new char[1];
    password[0] = '\0';
    iban = new char[1];
    iban[0] = '\0';
    Id = 0;
    amount = 0;
    dataOfCreation = new char[1];
    dataOfCreation[0] = '\0';
}

Account::Account(const Account& other)
{
    copyFrom(other);
}

Account::Account(char* username, char* password, char* iban, int Id, double amount, char* dataOfCreation)
{
    this->username = new char[strlen(username) + 1];
    strcpy(this->username, username);
    this->password = new char[strlen(password) + 1];
    strcpy(this->password, password);
    this->iban = new char[strlen(iban) + 1];
    strcpy(this->iban, iban);
    this->Id = Id;
    this->amount = amount;
    this->dataOfCreation = new char[strlen(dataOfCreation) + 1];
    strcpy(this->dataOfCreation, dataOfCreation);
}

Account& Account::operator=(const Account& other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }
    return *this;
}

std::ostream& operator<<(std::ostream& ofs, const Account& account) {

    return ofs << "Type: " << account.type << ", Username: " << account.username << ", Password: " << account.password
               << ", Iban: " << account.iban << ", Id: " << account.Id << ", Amount: " << account.amount <<
               ", DataOfCreation: " << account.dataOfCreation << std:: endl;
}

void Account::setAmount(double newAmount)
{
    amount = newAmount;
}

char* Account::getUsername() const
{
    return username;
}

char* Account::getIban() const
{
    return iban;
}

int Account::getId() const
{
    return Id;
}

double Account::getBalance() const
{
    return amount;
}

char* Account::getDataOfCreation() const
{
    return dataOfCreation;
}