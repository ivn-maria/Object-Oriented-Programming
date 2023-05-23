#include "Customer.h"

void Customer::copyFrom(const Customer& other)
{
    id = other.id;
    name = new char[strlen(other.name) + 1];
    strcpy(name, other.name);
    address = new char[strlen(other.address) + 1];
    strcpy(address, other.address);
}

void Customer::free()
{
    delete[] name;
    delete[] address;
}

Customer::Customer()
{
    id = 0;
    name = new char[1];
    name[0] = '\0';
    address = new char[1];
    address[0] = '\0';
}

Customer::Customer(const Customer& other)
{
    id = other.id;
    name = new char[strlen(other.name) + 1];
    strcpy(name, other.name);
    address = new char[strlen(other.address) + 1];
    strcpy(address, other.address);
    copyFrom(other);
}

Customer::Customer(int id, char* name, char* address)
{
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    this->address = new char[strlen(address) + 1];
    strcpy(this->address, address);
    this->id = id;
}

Customer& Customer::operator=(const Customer& other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }
    return *this;
}

Customer:: ~Customer()
{
    free();
}

std::ostream& operator<<(std::ostream& ofs, const Customer& customer)
{
    return ofs << "id: " << customer.id << " Name: " << customer.name << " Address: " << customer.address << endl;
}

int Customer::getId() const
{
    return id;
}

char* Customer::getName() const
{
    return name;
}

char* Customer::getAddress() const
{
    return address;
}