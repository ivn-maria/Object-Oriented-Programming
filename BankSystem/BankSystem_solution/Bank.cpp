#include "Bank.h"
#include "NormalAccount.h"
#include "PrivilegeAccount.h"
#include "SavingsAccount.h"
#include <fstream>

void Bank::copyFrom(const Bank& other)
{
    name = new char[strlen(other.name) + 1];
    strcpy(name, other.name);

    address = new char[strlen(other.address) + 1];
    strcpy(address, other.address);

    customers = new Customer * [other.countOfCustomers];
    for (size_t i = 0; i < other.countOfCustomers; i++)
        customers[i] = other.customers[i];

    accounts = new Account * [other.countOfAccounts];
    for (size_t i = 0; i < other.countOfAccounts; i++)
        accounts[i] = other.accounts[i]->clone();

    log = new char[strlen(other.log) + 1];
    strcpy(log, other.log);

    countOfCustomers = other.countOfCustomers;
    countOfAccounts = other.countOfAccounts;
}

void Bank::free()
{
    delete[] name;

    delete[] address;

    for (size_t i = 0; i < countOfCustomers; i++)
        delete customers[i];
    delete[] customers;

    for (size_t i = 0; i < countOfAccounts; i++)
        delete accounts[i];
    delete[] accounts;

    delete[] log;
}

void Bank::resizeCustomers()
{
    auto** newCustomers = new Customer*[capacityOfCustomers *= 2];
    for (int i = 0; i < countOfCustomers; i++)
        newCustomers[i] = customers[i];
    delete[] customers;
    customers = newCustomers;
    delete[] newCustomers;
}

void Bank::resizeAccounts()
{
    auto** newAccounts = new Account*[countOfAccounts *= 2];
    for (int i = 0; i < countOfCustomers; i++)
        newAccounts[i] = accounts[i];
    delete[] accounts;
    accounts = newAccounts;
    delete[] newAccounts;
}

void Bank::addAccount(Account*& account)
{
    auto** tempAccounts = new Account* [countOfAccounts + 1];

    if (countOfAccounts >= capacityOfAccounts)
        resizeAccounts();

    int flag = 0;
    for (int i = 0; i < countOfCustomers; i++) {
        if (customers[i]->getId() == account->getId()) {
            if (this->accounts == nullptr)
                tempAccounts[0] = account;
            else {
                for (int j = 0; j < countOfAccounts; j++)
                    tempAccounts[j] = this->accounts[j];
                tempAccounts[countOfAccounts] = account;
            }
            flag = 1;
        }
    }
    if (flag) {
        countOfAccounts++;
        this->accounts = tempAccounts;
    } else cout << "There is not customer with that id!\n";
}

Bank::Bank()
{
    countOfCustomers = 0;
    capacityOfCustomers = 4;
    countOfAccounts = 0;
    capacityOfAccounts = 4;
    name = new char[1];
    name[0] = '\0';
    address = new char[1];
    address[0] = '\0';
    customers = new Customer* [countOfCustomers];
    accounts = new Account* [countOfAccounts];
    log = new char[1];
    log[0] = '\0';
}

Bank::Bank(const Bank& other)
{
    copyFrom(other);
}

Bank::Bank(char* name, char* address)
{
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    this->address = new char[strlen(address) + 1];
    strcpy(this->address, address);
    countOfCustomers = 0;
    capacityOfCustomers = 4;
    countOfAccounts = 0;
    capacityOfAccounts = 4;
    customers = new Customer* [countOfCustomers];
    accounts = new Account* [countOfAccounts];
    this->log = new char[strlen(log) + 1];
    strcpy(this->log, log);
}

Bank& Bank::operator=(const Bank& other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }
    return *this;
}

Bank:: ~Bank()
{
    free();
}

std::ostream& operator<<(std::ostream& ofs, const Bank& bank)
{
    return ofs << "Name: " << bank.name << " Address: " << bank.address << " Number of customers: " <<
        bank.countOfCustomers << " Number of accounts: " << bank.countOfAccounts << endl;
}

char* Bank::getLog()
{
    return log;
}

void Bank::setLog(char* other)
{
    log = new char[strlen(other) + 1];
    log = other;
}

void Bank::exportLog(char* file) {
    std::ofstream outFile(file);
    if (!outFile.is_open())
        cout << "Error!" << endl;
    outFile << log << std::endl;
    outFile.close();
}

void Bank::addCustomer(Customer*& customer) {
    auto** tempCustomers = new Customer* [countOfCustomers + 1];

    for(size_t i = 0; i < countOfCustomers; i++)
        if(customers[i] == customer)
            cout << "Existing customer" << endl;

    if (countOfCustomers >= capacityOfCustomers)
        resizeCustomers();

    if(this->customers == nullptr)
        tempCustomers[0] = customer;
    else
    {
        for (int i = 0; i < countOfCustomers; i++)
            tempCustomers[i] = this->customers[i];

        tempCustomers[countOfCustomers] = customer;
    }
    countOfCustomers++;
    this->customers = tempCustomers;
}

void Bank::deleteCustomer(int ID)
{
    Customer* customer = findCustomerByID(ID);
    auto** tempCustomers = new Customer* [countOfCustomers - 1];

    if(countOfCustomers == 1) {
        tempCustomers[0] = nullptr;
        countOfCustomers--;
    }
    else
    {
        for (size_t i = 0; i < countOfCustomers; i++)
            if (customers[i] == customer) {
                tempCustomers[i] = customers[i];
                countOfCustomers--;
            }
    }
    this->customers = tempCustomers;

    for(size_t i = 0; i < countOfAccounts; i++)
        if (accounts[i]->getId() == ID)
            this->deleteAccount(accounts[i]->getIban());
}

void Bank::addNormalAccount(char* username, char* password, char* iban, int ID, double amount, char* dateOfCreation)
{
    Account* account = new NormalAccount(username, password, iban, ID, amount, dateOfCreation);
    addAccount(account);
}

void Bank::addPrivilegeAccount(char* username, char* password, char* iban, int ID, double amount, char* dateOfCreation,
                               double overdraft)
{
    Account* account = new PrivilegeAccount(username, password, iban, ID, amount, dateOfCreation, overdraft);
    addAccount(account);
}

void Bank::addSavingsAccount(char* username, char* password, char* iban, int ID, double amount, char* dateOfCreation,
                             double interestRate)
{
    Account* account = new SavingsAccount(username, password, iban, ID, amount, dateOfCreation, interestRate);
    addAccount(account);
}

void Bank::deleteAccount(char* iban)
{
    Account* account = findAccountByIBAN(iban);
    auto** tempAccounts = new Account* [countOfAccounts - 1];

    if(countOfAccounts == 1) {
        tempAccounts[0] = nullptr;
        countOfAccounts--;
    }
    else
    {
        for (int i = 0; i < countOfAccounts; i++)
            if (this->accounts[i] == account)
                tempAccounts[i] = this->accounts[i + 1];
        countOfAccounts--;
    }
    this->accounts = tempAccounts;
}

void Bank::listCustomers()
{
    if(countOfCustomers != 0) {
        for (size_t i = 0; i < countOfCustomers; i++)
            std::cout << *customers[i] << std::endl;
        std::cout << std::endl;
    }
}

void Bank::listAccounts()
{
    if(countOfAccounts != 0) {
        for (size_t i = 0; i < countOfAccounts; i++) {
            std::cout << *accounts[i] << std::endl;
        }
        std::cout << std::endl;
    }
}

void Bank::listCustomerAccount(int ID)
{
    Account** accounts_ = findAccountByID(ID);
    for(int i = 0; i < countOfAccounts; i++)
        if(accounts_[i] != nullptr)
          std::cout << *accounts_[i] << std::endl;
    std::cout << std::endl;
}

bool Bank::transfer(double amount, char* fromIBAN, char* toIBAN)
{
    for(size_t i = 0; i < countOfAccounts; i++)
        if(strcmp(accounts[i]->getIban(), fromIBAN) == 0) {
            if (accounts[i]->withdraw(amount)) {
                for (size_t j = 0; j < countOfAccounts; j++)
                    if (strcmp(accounts[j]->getIban(), toIBAN) == 0)
                        accounts[j]->deposit(amount);
            }
            else return false;
        }
    return true;
}

bool Bank::withdrawFrom(char* iban, double sum)
{
    for (int i = 0; i < countOfAccounts; i++)
        if (strcmp(accounts[i]->getIban(), iban) == 0)
            if (accounts[i]->withdraw(sum))
                return true;
    return false;
}

bool Bank::depositTo(char* iban, double sum)
{
    for (int i = 0; i < countOfAccounts; i++)
        if (strcmp(accounts[i]->getIban(), iban) == 0) {
            accounts[i]->deposit(sum);
            return true;
        }
    return false;
}

void Bank::display() const
{
    cout << *this << endl;
}

Customer* Bank::findCustomerByID(int ID)
{
    for(int i = 0; i < countOfCustomers; i++)
        if(customers[i]->getId() == ID)
            return customers[i];
    return nullptr;
}

Account** Bank::findAccountByID(int ID)
{
    int temp = 0;
    auto** accounts_ = new Account*();
    for(int i = 0; i < countOfAccounts; i++)
        for(int j = temp; j < countOfAccounts; j++)
            if (accounts[j]->getId() == ID)
            {
                accounts_[j] = accounts[i];
                temp = j;
            }


    return accounts_;
}

Account* Bank::findAccountByIBAN(const char* iban)
{
    for(int i = 0; i < countOfAccounts; i++)
        if(accounts[i]->getIban() == iban)
            return accounts[i];
    return nullptr;
}

