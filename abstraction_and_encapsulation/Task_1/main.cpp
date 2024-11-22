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
};


int main() {
	ifstream fin{ INPUT_FILE };
	int numOfAddr;

	if (fin.is_open()) {
		fin >> numOfAddr;
	}
	else {
		cout << "Cant open file: " << INPUT_FILE << endl;
		return 1;
	}

	Address* addrListP = new Address[numOfAddr];

	for (size_t i = 0; i < numOfAddr; ++i) {
		addrListP[i].setAddress(fin);
	}

	fin.close();

	ofstream fout{ OUTPUT_FILE };
	if (!fout.is_open()) {
		cout << "Cant open file: " << OUTPUT_FILE << endl;
		return 1;
	}

	fout << numOfAddr << endl;

	for (int i = numOfAddr - 1; i >= 0; --i) {
		fout << addrListP[i].getAddress();
	}

	fout.close();

	delete[] addrListP;
}