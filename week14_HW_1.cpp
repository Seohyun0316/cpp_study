#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string name, address;
    int phone_number;
    ofstream fout("phonebook.xls", ios::app);  // 엑셀 파일을 append 모드로 열기

    if (!fout) {
        cout << "파일 열기 실패!" << endl;
        return 1;
    }

    while (true) {
        cout << "name: ";
        cin >> name;
        if (name == "0") break;  // 이름에 "0" 입력 시 종료

        cout << "address: ";
        cin >> address;
        cout << "phone number: ";
        cin >> phone_number;

        // 엑셀 파일에 입력 정보 저장
        fout << "<person information>\n";
        fout << "name: " << name << "\n";
        fout << "address: " << address << "\n";
        fout << "phone number: " << phone_number << "\n";
        fout << "<person information>\n";
    }

    fout.close();  // 파일 닫기

    // 파일을 다시 읽기 모드로 열어 저장된 내용 출력
    ifstream fin("phonebook.xls");
    if (!fin) {
        cout << "파일 열기 실패!" << endl;
        return 1;
    }

    cout << "\n저장된 내용은 다음과 같습니다:\n";
    string line;
    while (getline(fin, line)) {
        cout << line << endl;
    }

    fin.close();  // 파일 닫기

    return 0;
}
