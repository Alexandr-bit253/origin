#include <iostream>
#include <windows.h>
#include <string>
using namespace std;


struct BankAcccount {
	long long number{};
	std::string name{};
	float balance{};
};


void changeBankAccount(BankAcccount* account, float newBalance) {
	account->balance = newBalance;
}


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	BankAcccount account;
	float newBalance{};

	cout << "¬ведите номер счЄта: ";
	cin >> account.number;

	cout << "¬ведите им€ владельца: ";
	cin >> account.name;

	cout << "¬ведите баланс: ";
	cin >> account.balance;

	cout << "¬ведите новый баланс: ";
	cin >> newBalance;

	changeBankAccount(&account, newBalance);

	cout << "¬аш счЄт: " << account.name << ", " << account.number << ", " << account.balance << endl;
}