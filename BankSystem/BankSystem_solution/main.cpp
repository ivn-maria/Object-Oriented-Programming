#include "setLog.h"

int main()
{
    char bankName[20], bankAddress[20];
    cout << "Bank name: "; cin >> bankName; cout << endl;
    cout << "Bank address: "; cin >> bankAddress; cout << endl;
    Bank bank(bankName, bankAddress);

    while(true)
    {
        char operation[20];
        cout << "Choose operation: addCustomer, deleteCustomer, addAccount, deleteAccount, listCustomers, listAccounts, "
                "listCustomerAccount, exportLog, transfer, deposit, withdraw, display, displayAccount, getAccountBalance"
                ", quit" << endl;
        cin >> operation; cout << endl;
        if (strcmp(operation, "addCustomer") == 0)
        {
            int ID; char name[50], address[20];
            cout << "ID: "; cin >> ID; cout << endl;
            cout << "Name: "; cin >> name; cout << endl;
            cout << "Address: "; cin >> address; cout << endl;
            auto* customer = new Customer(ID, name, address);
            bank.addCustomer(customer);

            addCustomerToLog(bank, name, address, ID);
        }
        if (strcmp(operation, "deleteCustomer") == 0)
        {
            int ID;
            cout << "ID: "; cin >> ID; cout << endl;
            bank.deleteCustomer(ID);

            deleteCustomerFromLog(bank, ID);
        }
        if (strcmp(operation, "addAccount") == 0)
        {
            int ID; char username[20], password[20], iban[10], type[10]; double amount; char dateOfCreation[11];
            cout << "ID: "; cin >> ID; cout << endl;
            cout << "Username: "; cin >> username; cout << endl;
            cout << "Password: "; cin >> password; cout << endl;
            cout << "IBAN: "; cin >> iban; cout << endl;
            cout << "Type: "; cin >> type; cout << endl;
            cout << "Amount: "; cin >> amount; cout << endl;
            cout << "Date of creation: "; cin >> dateOfCreation; cout << endl;

            if(strcmp(type, "Normal") == 0) {
                Account* account = new NormalAccount(username, password, iban, ID, amount, dateOfCreation);
                bank.addNormalAccount(username, password, iban, ID, amount, dateOfCreation);
                delete account;
            }
            else if(strcmp(type, "Savings") == 0)
            {
                double rate;
                cout << "Rate: "; cin >> rate; cout << endl;
                Account* account = new SavingsAccount(username, password, iban, ID, amount, dateOfCreation, rate);
                bank.addSavingsAccount(username, password, iban, ID, amount, dateOfCreation, rate);
                delete account;
            }
            else if(strcmp(type, "Privilege") == 0)
            {
                double over;
                cout << "Overdraft: "; cin >> over; cout << endl;
                Account* account = new PrivilegeAccount(username, password, iban, ID, amount, dateOfCreation, over);
                bank.addPrivilegeAccount(username, password, iban, ID, amount, dateOfCreation, over);
                delete account;
            }

            addAccountToLog(bank, username, password, iban, type, ID);
        }
        if (strcmp(operation, "deleteAccount") == 0)
        {
            char iban[10];
            cout << "IBAN: "; cin >> iban; cout << endl;
            bank.deleteAccount(iban);

            deleteAccountFromLog(bank, iban);
        }
        if (strcmp(operation, "listCustomers") == 0)
            bank.listCustomers();
        if (strcmp(operation, "listAccounts") == 0)
            bank.listAccounts();
        if (strcmp(operation, "listCustomerAccount") == 0)
        {
            int ID;
            cout << "ID: "; cin >> ID; cout << endl;
            bank.listCustomerAccount(ID);
        }
        if (strcmp(operation, "exportLog") == 0)
        {
            char *file = new char;
            cout << "File: "; cin >> file; cout << endl;
            bank.exportLog(file);
            delete file;
        }
        if (strcmp(operation, "transfer") == 0)
        {
            int amount; char *iban = new char; char *iban2 = new char;
            cout << "Amount: "; cin >> amount; cout << endl;
            cout << "From IBAN: "; cin >> iban; cout << endl;
            cout << "To IBAN: "; cin >> iban2; cout << endl;
            bank.transfer(amount, iban, iban2);

            transferToLog(bank, amount, iban, iban2);

            delete iban;
            delete iban2;
        }
        if (strcmp(operation, "deposit") == 0)
        {
            int amount; char *iban = new char;
            cout << "Amount: "; cin >> amount; cout << endl;
            cout << "IBAN: "; cin >> iban; cout << endl;
            bank.depositTo(iban, amount);

            withdrawToLog(bank, amount, iban);

            delete iban;
        }
        if (strcmp(operation, "withdraw") == 0) {
            int amount; char *iban = new char;
            cout << "Amount: "; cin >> amount; cout << endl;
            cout << "IBAN: "; cin >> iban; cout << endl;
            bank.withdrawFrom(iban, amount);
            delete iban;
        }
        if (strcmp(operation, "display") == 0)
            bank.display();
        if (strcmp(operation, "displayAccount") == 0)
        {
            char *iban = new char;
            cout << "IBAN: "; cin >> iban; cout << endl;
            bank.findAccountByIBAN(iban)->display();
            delete iban;
        }
        if (strcmp(operation, "getAccountBalance") == 0)
        {
            char *iban = new char;
            cout << "IBAN: "; cin >> iban; cout << endl;
            cout << bank.findAccountByIBAN(iban)->getBalance();
            delete iban;
        }
        if (strcmp(operation, "quit") == 0)
            break;
    }

    return 0;
}