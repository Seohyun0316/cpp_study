#include <iostream>
using namespace std;

int main() {
    int num;

    while (true) {
        cout << "정수 입력(범위: 0 ~ 10, 음수 입력시 종료): ";
        cin >> num;

        // 음수 입력 시 종료
        if (num < 0) {
            cout << "Finished" << endl;
            break;  // 음수 입력 시 종료
        }

        // 범위 체크
        if (num > 10) {
            cout << "0 ~ 10까지 입력입니다." << endl;
            continue;  // 잘못된 입력이 들어오면 다시 입력 받기
        }

        // 0이 입력되면 종료
        if (num == 0) {
            cout << "0! = 1" << endl;
            continue;  // 0일 경우 1을 출력하고 다시 반복
        }

        // 팩토리얼 계산
        int factorial = 1;
        for (int i = 1; i <= num; i++) {
            factorial *= i;
        }

        // 팩토리얼 출력
        cout << num << "! = ";
        for (int i = num; i > 0; i--) {
            cout << i;
            if (i != 1) {
                cout << " X ";
            }
        }
        cout << " = " << factorial << endl;
    }

    return 0;
}
