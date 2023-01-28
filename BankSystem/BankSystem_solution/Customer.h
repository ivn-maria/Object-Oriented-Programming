#ifndef BANK_SYSTEM_CUSTOMER_H
#define BANK_SYSTEM_CUSTOMER_H

#include "Account.h"

class Customer
{
    int id;
    char* name;
    char* address;

    void copyFrom(const Customer&);
    void free();

public:
    Customer();
    Customer(const Customer&);
    Customer(int, char*, char*);
    Customer& operator=(const Customer&);
    ~Customer();

    friend std::ostream& operator<<(std::ostream&, const Customer&);

    int getId() const;
    char* getName() const;
    char* getAddress() const;
};

#endif //BANK_SYSTEM_CUSTOMER_H
