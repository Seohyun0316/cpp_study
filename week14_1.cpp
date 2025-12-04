#include <iostream>
#include <fstream>
using namespace std;


int main()
{
	char name[10], dept[20];
	int sid;

	cout << "이름>>";
	cin >> name;
	cout << "학번>>";
	cin >> sid;
	cout << "학과>>";
	cin >> dept;

	ofstream fout("C:\\Users\\didtj\\source\\repos\\CPP\\student.txt.txt");
	if (!fout) {
			cout << "파일 열기 실패";
			return 0;
	}

	fout << name << endl;
	fout << sid << endl;
	fout << dept << endl;

	fout.close();
}

