#include <iostream>
#include <fstream>
using namespace std;

int main() {

    // ----- 과제 안내 출력 형식 -----
    cout << "==================== \n";
    cout << "학과 : 사이버보안\n";
    cout << "학번 : 2271085\n";
    cout << "이름 : 양서현\n";
    cout << "==================== \n\n";
    // ------------------------------


    int num;
    ofstream fout("number.dat", ios::binary);  // 바이너리 파일로 쓰기 위한 스트림 생성

    if (!fout) {
        cout << "파일 열기 실패!" << endl;
        return 1;
    }

    // 사용자 입력 반복
    cout << "Input numbers to write (negative number to stop):" << endl;
    while (true) {
        cin >> num;
        if (num < 0) break;  // 음수 입력 시 종료
        fout.write(reinterpret_cast<char*>(&num), sizeof(num));  // 바이너리 파일에 정수 저장
    }
    fout.close();  // 파일 닫기

    // 바이너리 파일 읽기
    ifstream fin("number.dat", ios::binary);
    if (!fin) {
        cout << "파일 열기 실패!" << endl;
        return 1;
    }

    // 새로운 바이너리 파일에 2배 값 저장
    ofstream fout2("number2.dat", ios::binary);
    if (!fout2) {
        cout << "새 파일 열기 실패!" << endl;
        return 1;
    }

    int doubled_num;
    while (fin.read(reinterpret_cast<char*>(&num), sizeof(num))) {
        doubled_num = num * 2;  // 값을 2배로 계산
        fout2.write(reinterpret_cast<char*>(&doubled_num), sizeof(doubled_num));  // 새로운 파일에 2배 값 저장
    }

    fin.close();  // 파일 닫기
    fout2.close();  // 새로운 파일 닫기

    // 두 번째 바이너리 파일 읽고 출력
    ifstream fin2("number2.dat", ios::binary);
    if (!fin2) {
        cout << "파일 열기 실패!" << endl;
        return 1;
    }

    cout << "\nDoubled Result:" << endl;
    while (fin2.read(reinterpret_cast<char*>(&doubled_num), sizeof(doubled_num))) {
        cout << doubled_num << endl;  // 2배 계산된 값 출력
    }

    fin2.close();  // 파일 닫기

    return 0;
}
