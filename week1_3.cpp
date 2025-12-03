#include <iostream>
#include <string>
using namespace std;

int main() {
    int month;

    cout << "Input month: ";
    if (!(cin >> month)) {
        cout << "입력이 올바르지 않습니다." << endl;
        return 1;
    }

    switch (month) {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        cout << "31 days in month " << month << endl;
        break;
    case 4: case 6: case 9: case 11:
        cout << "30 days in month " << month << endl;
        break;
    case 2:
        cout << "28 days in month " << month << endl;
        break;
    default:
        cout << "잘못된 입력입니다." << endl;
        break;
    }

    return 0;
}

