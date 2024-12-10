#include <iostream>

using namespace std;


int main()
{
    system("chcp 1251");

    string name{};

    cout << "Введите имя: ";
    cin >> name;

    cout << "Здравствуйте, " << name << "!" << endl;

    return 0;
}
