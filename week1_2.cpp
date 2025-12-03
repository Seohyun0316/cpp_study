#include <iostream>
#include <string>
using namespace std;

int main() {
    int month;

    cout << "Input month: ";
    cin >> month;

    // 31일인 월
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        cout << "31 days in month " << month;

    // 2월
    else if (month == 2)
        cout << "28 days in month 2";

    // 30일인 월
    else if (month == 4 || month == 6 || month == 9 || month == 11)
        cout << "30 days in month " << month;


    return 0;
}
