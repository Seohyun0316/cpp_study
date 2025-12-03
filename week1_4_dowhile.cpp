#include <iostream>
#include <string>
using namespace std;

int main() {
    int month;

    do {
        cout << "Input month (Input 0 to finish): ";
        cin >> month;

        // 월에 따른 날짜 출력
        switch (month) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            cout << "31 days in month " << month << endl;
            break;
        case 2:
            cout << "28 days in month " << month << endl;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            cout << "30 days in month " << month << endl;
            break;
        case 0:
            cout << "Finished." << endl;
            break;
        default:
            cout << "Wrong input" << endl;
            break;
        }
    } while (month != 0);  // month가 0이 아니면 계속 반복

    return 0;
}
