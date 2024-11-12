#include <iostream>

using namespace std;


class Count {
private:
	int count = 1;
public:
	Count(int count) {
		this->count = count;
	}

	void add_count() {
		count++;
	}

	void sub_count() {
		count--;
	}

	int get_count() {
		return count;
	}
};

enum class Operations : char {
	ADD  = '+',
	SUB  = '-',
	SHOW = '=',
	EXIT = 'x'
};


int main() {
	char num;
	cin >> num;
	if (num == static_cast<char>(Operations::ADD)) {
		cout << "yes\n";
	}
}