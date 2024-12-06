#include <iostream>

using namespace std;


int function(std::string str, int forbidden_length) {
	int str_len = str.size();
	if (str_len == forbidden_length) {
		throw "Вы ввели слово запретной длины! До свидания\n";
	}
	return str_len;
}


int main() {
	system("chcp 1251");

	int forbidden_length{};
	string word{};

	cout << "Введите запретную длину: ";
	cin >> forbidden_length;

	while (true) {
		cout << "Введите слово: ";
		cin >> word;
		try {
			cout << "Длина слова \"" << word << "\" равна " 
				<< function(word, forbidden_length) << endl;
		}
		catch(const char* error_message) {
			cout << error_message << endl;
			break;
		}
	}
}