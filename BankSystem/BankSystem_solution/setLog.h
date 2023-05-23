#ifndef BANKSYSTEM_SETLOG_H
#define BANKSYSTEM_SETLOG_H

#include "Bank.cpp"

char* intToCharArray(int amount)
{
    int size = 0, number = amount;
    while(number != 0)
    {
        number /= 10;
        size++;
    }

    char* output = new char[size + 1];
    for(int i = size - 1; i >= 0; i--)
    {
        output[i] = (char) (48 + amount % 10);
        amount /= 10;
    }

    output[size] = '\0';
    return output;
}

void addCustomerToLog(Bank& bank, char* name, char* address, int ID)
{
    bank.setLog(strcat(bank.getLog(), "Add Customer:\0"));
    bank.setLog(strcat(bank.getLog(), " Name: \0"));
    bank.setLog(strcat(bank.getLog(), name));
    bank.setLog(strcat(bank.getLog(), " Address: \0"));
    bank.setLog(strcat(bank.getLog(), address));
    bank.setLog(strcat(bank.getLog(), " ID: \0"));
    bank.setLog(strcat(bank.getLog(), intToCharArray(ID)));
    bank.setLog(strcat(bank.getLog(), " \n\0"));
}

void deleteCustomerFromLog(Bank& bank, int ID)
{
    bank.setLog(strcat(bank.getLog(), "Delete Customer:\0"));
    bank.setLog(strcat(bank.getLog(), " ID: \0"));
    bank.setLog(strcat(bank.getLog(), intToCharArray(ID)));
    bank.setLog(strcat(bank.getLog(), " \n\0"));
}

void addAccountToLog(Bank& bank, char* username, char* password, char* iban, char* type, int ID)
{
    bank.setLog(strcat(bank.getLog(), "Add Account:\0"));
    bank.setLog(strcat(bank.getLog(), " Username: \0"));
    bank.setLog(strcat(bank.getLog(), username));
    bank.setLog(strcat(bank.getLog(), " Password: \0"));
    bank.setLog(strcat(bank.getLog(), password));
    bank.setLog(strcat(bank.getLog(), " IBAN: \0"));
    bank.setLog(strcat(bank.getLog(), iban));
    bank.setLog(strcat(bank.getLog(), " Type: \0"));
    bank.setLog(strcat(bank.getLog(), type));
    bank.setLog(strcat(bank.getLog(), " ID: \0"));
    bank.setLog(strcat(bank.getLog(), intToCharArray(ID)));
    bank.setLog(strcat(bank.getLog(), " \n\0"));
}

void deleteAccountFromLog(Bank& bank, char* iban)
{
    bank.setLog(strcat(bank.getLog(), "Delete Account:\0"));
    bank.setLog(strcat(bank.getLog(), "IBAN: \0"));
    bank.setLog(strcat(bank.getLog(), iban));
    bank.setLog(strcat(bank.getLog(), " \n\0"));
}

void transferToLog(Bank& bank, double amount, char* iban, char* iban2)
{
    bank.setLog(strcat(bank.getLog(), "Transfer \0"));
    bank.setLog(strcat(bank.getLog(), intToCharArray(amount)));
    bank.setLog(strcat(bank.getLog(), " from \0"));
    bank.setLog(strcat(bank.getLog(), iban));
    bank.setLog(strcat(bank.getLog(), " to \0"));
    bank.setLog(strcat(bank.getLog(), iban2));
    bank.setLog(strcat(bank.getLog(), " \n\0"));
}

void withdrawToLog(Bank& bank, double amount, char* iban)
{
    bank.setLog(strcat(bank.getLog(), "Deposit \0"));
    bank.setLog(strcat(bank.getLog(), intToCharArray(amount)));
    bank.setLog(strcat(bank.getLog(), " to \0"));
    bank.setLog(strcat(bank.getLog(), iban));
    bank.setLog(strcat(bank.getLog(), " \n\0"));
}

#endif //BANKSYSTEM_SETLOG_H
