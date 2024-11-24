#include <iostream>
<<<<<<< HEAD


int main() {

=======
using namespace std;


struct Address {
	string cityName{};
	string street{};
	int houseNumber{};
	int apartmentNumber{};
	long long zipCode{};
};


void printAddress(Address* address) {
	cout << "Город: " << address->cityName << endl;
	cout << "Улица: " << address->street << endl;
	cout << "Номер дома: " << address->houseNumber << endl;
	cout << "Номер квартиры: " << address->apartmentNumber << endl;
	cout << "Индекс: " << address->zipCode << endl;
	cout << endl;
}


int main() {
	setlocale(LC_ALL, "rus");

	Address address1;
	address1.cityName = "Санкт-Петербург";
	address1.street = "Невский проспект";
	address1.houseNumber = 1;
	address1.apartmentNumber = 5;
	address1.zipCode = 346124;

	Address address2;
	address2.cityName = "Смоленск";
	address2.street = "Ленина";
	address2.houseNumber = 17;
	address2.apartmentNumber = 91;
	address2.zipCode = 995731;

	printAddress(&address1);
	printAddress(&address2);
>>>>>>> 1f044ddce4159c3c26889a339bb0e072fd3bfb5a
}