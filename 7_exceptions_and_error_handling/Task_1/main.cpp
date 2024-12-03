#include <iostream>

using namespace std;


int function(std::string str, int forbidden_length) {
	int str_len = str.size();
	if (str_len == forbidden_length) {
		throw "�� ����� ����� ��������� �����! �� ��������\n";
	}
	return str_len;
}


int main() {
	system("chcp 1251");

	int forbidden_length{};
	string word{};

	cout << "������� ��������� �����: ";
	cin >> forbidden_length;

	while (true) {
		cout << "������� �����: ";
		cin >> word;
		try {
			cout << "����� ����� \"" << word << "\" ����� " 
				<< function(word, forbidden_length) << endl;
		}
		catch(const char* error_message) {
			cout << error_message << endl;
			break;
		}
	}
}