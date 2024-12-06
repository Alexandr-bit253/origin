#include <iostream>
using namespace std;


enum class Months {
	january = 1,
	february,
	march,
	april,
	may,
	june,
	july,
	august,
	september,
	october,
	november,
	december
};


int main() {
	setlocale(LC_ALL, "rus");

	int number{};

	while (true) {
		cout << "������� ����� ������: ";
		cin >> number;

		if (number == 0) break;

		switch (static_cast<Months>(number))
		{
		case Months::january:    cout << "������" << endl; break;
		case Months::february:   cout << "�������" << endl; break;
		case Months::march:      cout << "����" << endl; break;
		case Months::april:      cout << "������" << endl; break;
		case Months::may:        cout << "���" << endl; break;
		case Months::june:       cout << "����" << endl; break;
		case Months::july:       cout << "����" << endl; break;
		case Months::august:     cout << "������" << endl; break;
		case Months::september:  cout << "��������" << endl; break;
		case Months::october:    cout << "�������" << endl; break;
		case Months::november:   cout << "������" << endl; break;
		case Months::december:   cout << "�������" << endl; break;
		default:                 cout << "������������ �����!" << endl; break;
		}
	}

	std::cout << "�� ��������" << std::endl;
}