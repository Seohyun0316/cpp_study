#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

int main() {

    // ----- 과제 안내 출력 형식 -----
    cout << "==================== \n";
    cout << "학과 : 사이버보안\n";
    cout << "학번 : 2271085\n";
    cout << "이름 : 양서현\n";
    cout << "==================== \n\n";
    // ------------------------------


    string name, address;
    int phone_number;
    ofstream fout("phonebook.xls", ios::app);  // 엑셀 파일을 append 모드로 열기

    if (!fout) {
        cout << "파일 열기 실패!" << endl;
        return 1;
    }

    while (true) {
        cout << "<person information>" << endl;
        cout << "name: ";
        cin >> name;
        if (name == "0") break;  // 이름에 "0" 입력 시 종료

        cout << "address: ";
        cin >> address;
        cout << "phone number: ";
        cin >> phone_number;

        // 엑셀 파일에 입력 정보 저장 (탭으로 구분)
        fout << name << "\t" << address << "\t" << phone_number << "\n";
    }

    fout.close();  // 파일 닫기

    // 파일을 다시 읽기 모드로 열어 저장된 내용 표로 출력
    ifstream fin("phonebook.xls");
    if (!fin) {
        cout << "파일 열기 실패!" << endl;
        return 1;
    }

    // 표 헤더 출력
    cout << left << setw(20) << "Name" << setw(30) << "Address" << setw(15) << "Phone Number" << endl;

    string line;
    while (getline(fin, line)) {
        size_t pos1 = line.find('\t');  // 첫 번째 탭 찾기
        size_t pos2 = line.rfind('\t'); // 마지막 탭 찾기

        if (pos1 != string::npos && pos2 != string::npos && pos1 != pos2) {
            // 탭 기준으로 각 항목 추출
            string name = line.substr(0, pos1);
            string address = line.substr(pos1 + 1, pos2 - pos1 - 1);
            string phone = line.substr(pos2 + 1);

            // 읽은 데이터를 출력
            cout << left << setw(20) << name << setw(30) << address << setw(15) << phone << endl;
        }
    }

    fin.close();  // 파일 닫기

    return 0;
}
