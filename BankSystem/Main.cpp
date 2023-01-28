#include<iostream>
#include "Bank.h"
#include "Constants.h"
#include "NormalAccount.h"
#include "PrivilegeAccount.h"
#include "SavingsAccount.h"
#pragma warning (disable:4996)

using namespace std;

void Menu() {
	cout << "1. Edit" << endl;
	cout << "\ta.Customer" << endl;
	cout << "   \t\ti.Add new customer" << endl;
	cout << "   \t\tii.Delete customer" << endl;
	cout << "	b.Account" << endl;
	cout << "   \t\ti.Add new account" << endl;
	cout << "   \t\tii.Delete account" << endl;
	cout << "2. List" << endl;
	cout << "	a.List all customers" << endl;
	cout << "	b.List all accounts" << endl;
	cout << "	c.List customer account" << endl;
	cout << "	d.List log" << endl;
	cout << "3. Action" << endl;
	cout << "	a.Withdraw from account" << endl;
	cout << "	b.Deposit to account" << endl;
	cout << "	c.Transfer" << endl;
	cout << "   \td.Export log to file" << endl;
	cout << "4. Display info for the bank" << endl;
	cout << "5. Show Menu" << endl;
	cout << "6. Quit" << endl;
}

void Interface() {

	cout << "Enter bank's name: ";
	char* BankName = new char[MAX_NAME_SIZE];
	cin.getline(BankName, MAX_NAME_SIZE);

	cout << "Enter bank's address: ";
	char* BankAddress = new char[MAX_ADDRESS_SIZE];
	cin.getline(BankAddress, MAX_ADDRESS_SIZE);

	cout << "Enter bank's Interest rate: ";
	char* interestRate = new char[MAX_RATE_SIZE];
	cin.getline(interestRate, MAX_RATE_SIZE);
	double InterestRate = atof(interestRate);

	cout << "Enter bank's Overdraft: ";
	char* OverDraft = new char[MAX_TYPE_AMOUNT_SIZE];
	cin.getline(OverDraft, MAX_TYPE_AMOUNT_SIZE);
	double Over = atof(OverDraft);


	Bank bank(BankName,BankAddress,InterestRate,Over);

	Menu();

	do {
		cout << "\nEnter the number of the action you want\n";
		char* num = new char[MAX_NUM_SYMBOL_SIZE];
		cin.getline(num, MAX_NUM_SYMBOL_SIZE);

		if (strcmp(num, "1") == 0) {
			cout << "Enter a/b\n";
			char* symbol = new char[MAX_NUM_SYMBOL_SIZE];
			cin.getline(symbol, MAX_NUM_SYMBOL_SIZE);

			if (strcmp(symbol, "a") == 0) {
				cout << "Enter i/ii\n";
				char* operation = new char[MAX_OPERATION_SIZE];
				cin.getline(operation, MAX_OPERATION_SIZE);

				if (strcmp(operation, "i") == 0) {
					cout << "Enter name: ";
					char* Name = new char[MAX_NAME_SIZE];
					cin.getline(Name, MAX_NAME_SIZE);

					cout << "Enter address: ";
					char* Address = new char[MAX_ADDRESS_SIZE];
					cin.getline(Address, MAX_ADDRESS_SIZE);

					cout << "Enter ID number: ";
					char* id = new char[MAX_ID_IBAN_SIZE];
					cin.getline(id, MAX_ID_IBAN_SIZE);
					int Num = atoi(id);

					Customer customer(Num, Name, Address);
					if (bank.addCustomer(customer)) {
						cout << "You successfully added new customer!\n";
					}
					else {
						cout << "This customer already existed\n";
					}
					bank.addCreatedCustomersToLog(Name, Address);

					delete[] id;
					delete[] Address;
					delete[] Name;
				}
				else if (strcmp(operation, "ii") == 0) {
					cout << " Enter the name of the customer you want to delete: ";
					char* name = new char[MAX_NAME_SIZE];
					cin.getline(name, MAX_NAME_SIZE);

					if (bank.deleteCustomer(name)) {
						cout << "You successfully deleted this customer!\n";
					}
					else {
						cout << "There is not such customer!\n";
					}
					bank.addDeletedCustomersToLog(name);
					delete[] name;
				}
				delete[] operation;
			}
			else if (strcmp(symbol, "b") == 0) {
				cout << "Enter i/ii\n";
				char* operation = new char[MAX_OPERATION_SIZE];
				cin.getline(operation, MAX_OPERATION_SIZE);

				if (strcmp(operation, "i") == 0) {
					cout << "Enter the type of account (Normal/Saving/Privilige)\n";
					char* Type = new char[MAX_TYPE_AMOUNT_SIZE];
					cin.getline(Type, MAX_TYPE_AMOUNT_SIZE);

					if (strcmp(Type, "Normal") == 0) {
						cout << "User: ";
						char* user = new char[MAX_NAME_SIZE];
						cin.getline(user, MAX_NAME_SIZE);

						cout << "Pass: ";
						char* pass = new char[MAX_PASS_SIZE];
						cin.getline(pass, MAX_PASS_SIZE);

						cout << "Iban: ";
						char* iban = new char[MAX_ID_IBAN_SIZE];
						cin.getline(iban, MAX_ID_IBAN_SIZE);

						cout << "User's id: ";
						char* id = new char[MAX_ID_IBAN_SIZE];
						cin.getline(id, MAX_ID_IBAN_SIZE);
						int Id = atoi(id);

						cout << "Amount: ";
						char* amount = new char[MAX_TYPE_AMOUNT_SIZE];
						cin.getline(amount, MAX_TYPE_AMOUNT_SIZE);
						double Amount = atof(amount);

						cout << "Date of creation: ";
						char* Date = new char[MAX_DATE_SIZE];
						cin.getline(Date, MAX_DATE_SIZE);

						if (bank.AddNormalAccount(user, pass, iban, Id, Amount, Date)) {
							cout << "You successfully created Normal account!\n";
						}
						
						bank.addCreatedAccountToLog(Type, user, iban);
						delete[] user;
						delete[] pass;
						delete[] iban;
						delete[] id;
						delete[] amount;
						delete[] Date;
					}
					else if (strcmp(Type, "Saving") == 0) {
						cout << "User: ";
						char* user = new char[MAX_NAME_SIZE];
						cin.getline(user, MAX_NAME_SIZE);

						cout << "Pass: ";
						char* pass = new char[MAX_PASS_SIZE];
						cin.getline(pass, MAX_PASS_SIZE);

						cout << "Iban: ";
						char* iban = new char[MAX_ID_IBAN_SIZE];
						cin.getline(iban, MAX_ID_IBAN_SIZE);

						cout << "User's id: ";
						char* id = new char[MAX_ID_IBAN_SIZE];
						cin.getline(id, MAX_ID_IBAN_SIZE);
						int Id = atoi(id);

						cout << "Amount: ";
						char* amount = new char[MAX_TYPE_AMOUNT_SIZE];
						cin.getline(amount, MAX_TYPE_AMOUNT_SIZE);
						double Amount = atof(amount);

						cout << "Date of creation: ";
						char* Date = new char[MAX_DATE_SIZE];
						cin.getline(Date, MAX_DATE_SIZE);

						double Rate = bank.GetBankRate();

						if (bank.AddSavingAccount(user, pass, iban, Id, Amount, Date, Rate)) {
							cout << "You successfully created Savings account!\n";
						}
						bank.addCreatedAccountToLog(Type, user, iban);

						delete[] user;
						delete[] pass;
						delete[] iban;
						delete[] id;
						delete[] amount;
						delete[] Date;
					}
					else if (strcmp(Type, "Privilige") == 0) {
						cout << "User: ";
						char* user = new char[MAX_NAME_SIZE];
						cin.getline(user, MAX_NAME_SIZE);

						cout << "Pass: ";
						char* pass = new char[MAX_PASS_SIZE];
						cin.getline(pass, MAX_PASS_SIZE);

						cout << "Iban: ";
						char* iban = new char[MAX_ID_IBAN_SIZE];
						cin.getline(iban, MAX_ID_IBAN_SIZE);

						cout << "User's id: ";
						char* id = new char[MAX_ID_IBAN_SIZE];
						cin.getline(id, MAX_ID_IBAN_SIZE);
						int Id = atoi(id);

						cout << "Amount: ";
						char* amount = new char[MAX_TYPE_AMOUNT_SIZE];
						cin.getline(amount, MAX_TYPE_AMOUNT_SIZE);
						double Amount = atof(amount);

						cout << "Date of creation: ";
						char* Date = new char[MAX_DATE_SIZE];
						cin.getline(Date, MAX_DATE_SIZE);

						double Over = bank.GetBankOverdraft();

						if (bank.AddPrivilegeAccount(user, pass, iban, Id, Amount, Date, Over)) {
							cout << "You successfully created Privilige account!\n";
						}
					
						bank.addCreatedAccountToLog(Type, user, iban);
						delete[] user;
						delete[] pass;
						delete[] iban;
						delete[] id;
						delete[] amount;
						delete[] Date;
					}
					delete[] Type;
				}
				else if (strcmp(operation, "ii") == 0) {

					cout << "Enter the index of the account you want to delete: ";
					int idx;
					cin >> idx;

					if (bank.deleteAccount(idx)) {
						cout << "Successfully deleted!\n";
					}
				}
				delete[] operation;
			}
			delete[] symbol;
		}
		else if (strcmp(num, "2") == 0) {
			cout << "Enter a/b/c/d\n";
			char* symbol = new char[MAX_NUM_SYMBOL_SIZE];
			cin.getline(symbol, MAX_NUM_SYMBOL_SIZE);

			if (strcmp(symbol, "a") == 0) {
				bank.listCustomers();
			}
			else if (strcmp(symbol, "b") == 0) {
				bank.listAccounts();
			}
			else if (strcmp(symbol, "c") == 0) {
				cout << " Enter the name of the customer whose accounts you want: ";
				char* name = new char[MAX_NAME_SIZE];
				cin.getline(name, MAX_NAME_SIZE);

				if (bank.listCustomerAccount(name)) {
					cout << "Successfully loaded.\n";
				}
				else {
					cout << "There is not such account!\n";
				}
				delete[] name;
			}
			else if (strcmp(symbol, "d") == 0) {
				bank.ListLog();
			}
			delete[] symbol;
		}
		else if (strcmp(num, "3") == 0) {
			cout << "Enter a/b/c/d\n";
			char* symbol = new char[MAX_NUM_SYMBOL_SIZE];
			cin.getline(symbol, MAX_NUM_SYMBOL_SIZE);

			if (strcmp(symbol, "a") == 0) {
				cout << "Enter iban of the account: ";
				char* iban = new char[MAX_ID_IBAN_SIZE];
				cin.getline(iban, MAX_ID_IBAN_SIZE);

				cout << "Enter sum: ";
				char* sum = new char[MAX_TYPE_AMOUNT_SIZE];
				cin.getline(sum, MAX_TYPE_AMOUNT_SIZE);
				double Sum = atof(sum);

				if (bank.WithdrawFromAccount(iban, Sum)) {
					cout << "Successfully executed!\n";
				}
				else {
					cout << "Invalid operation!\n";
				}
				bank.addWithdrawToLog(iban, sum);
	            delete[] iban;
				delete[] sum;
			}
			else if (strcmp(symbol, "b") == 0) {
				cout << "Enter iban of the account: ";
				char* iban = new char[MAX_ID_IBAN_SIZE];
				cin.getline(iban, MAX_ID_IBAN_SIZE);

				cout << "Enter sum: ";
				char* sum = new char[MAX_TYPE_AMOUNT_SIZE];
				cin.getline(sum, MAX_TYPE_AMOUNT_SIZE);
				double Sum = atof(sum);

				if (bank.DepositToAccount(iban, Sum)) {
					cout << "Successfully executed\n";
				}
				else {
					cout << "Invalid operation!\n";
				}
				bank.addDepositToLog(iban, sum);
				delete[] iban;
				delete[] sum;
			}
			else if (strcmp(symbol, "c") == 0) {
				cout << "Enter the Iban of first account: ";
				char* iban1 = new char[MAX_ID_IBAN_SIZE];
				cin.getline(iban1, MAX_ID_IBAN_SIZE);

				cout << "Enter the Iban of second account: ";
				char* iban2 = new char[MAX_ID_IBAN_SIZE];
				cin.getline(iban2, MAX_ID_IBAN_SIZE);

				cout << "Enter sum: ";
				char* sum = new char[MAX_TYPE_AMOUNT_SIZE];
				cin.getline(sum, MAX_TYPE_AMOUNT_SIZE);
				double Sum = atof(sum);

				if (bank.transfer(iban1, iban2, Sum)) {
					cout << "Successfully transfered!\n";
				}
				else {
					cout << "Invalid operation!\n";
				}
				bank.addTransfersToLog(iban1, iban2, sum);

				delete[] iban1;
				delete[] iban2;
				delete[] sum;
			}
			else if (strcmp(symbol,"d")==0) {
				cout << "Enter file name: ";
				char* FileName = new char[MAX_FILE_NAME];
				cin >> FileName;
				ofstream file(FileName);
				if (!file.is_open()) {
					cout << "Error while opening the file! ";
					return;
				}

				bank.SaveLogToFile(file);
				cout << "You successfully saved into " << FileName << endl;
				file.close();
				delete[] FileName;
			}
			delete[] symbol;
		}
		else if (strcmp(num, "4") == 0) {
			bank.DisplayBank();
		}
		else if (strcmp(num, "5") == 0) {
		    Menu();
		}
		else if (strcmp(num, "6") == 0) {	
		    break;
		}

		delete[] num;
	} while (true);

	delete[] BankName;
	delete[] BankAddress;
	delete[] OverDraft;
	delete[] interestRate;
}


int main()
{
	Interface();

	return 0;
}