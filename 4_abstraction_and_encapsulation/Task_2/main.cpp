#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


const string INPUT_FILE{ "in.txt" };
const string OUTPUT_FILE{ "out.txt" };


class Address {
private:
	string city{};
	string street{};
	int house{};
	int apartment{};

public:
	void setAddress(ifstream& f) {
		f >> city;
		f >> street;
		f >> house;
		f >> apartment;
	}

	string getAddress() {
		return city + ", " + street + ", " + to_string(house) + ", " + to_string(apartment) + "\n";
	}

	string getCity() const {
		return city;
	}
};


int main() {
	int numAddresses{};
	ifstream fin{ INPUT_FILE };

	if (!fin.is_open()) {
		cout << "Cant open file: " << INPUT_FILE << endl;
		return 1;
	}
	fin >> numAddresses;

	Address* addressArray = new Address[numAddresses];

	for (size_t i = 0; i < numAddresses; ++i) {
		addressArray[i].setAddress(fin);
	}

	fin.close();

	sort(addressArray, addressArray + numAddresses, [](const Address& a, const Address& b) {
		return a.getCity() < b.getCity();
		});

	ofstream fout{ OUTPUT_FILE };

	if (!fout.is_open()) {
		cout << "Cant open file: " << OUTPUT_FILE << endl;
		return 1;
	}

	fout << numAddresses << endl;

	for (size_t i = 0; i < numAddresses; ++i) {
		fout << addressArray[i].getAddress();
	}

	fout.close();

	delete[] addressArray;
}