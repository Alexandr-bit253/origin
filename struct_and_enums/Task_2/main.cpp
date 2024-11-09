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

	cout << "������� ����� �����: ";
	cin >> account.number;

	cout << "������� ��� ���������: ";
	cin >> account.name;

	cout << "������� ������: ";
	cin >> account.balance;

	cout << "������� ����� ������: ";
	cin >> newBalance;

	changeBankAccount(&account, newBalance);

	cout << "��� ����: " << account.name << ", " << account.number << ", " << account.balance << endl;
}