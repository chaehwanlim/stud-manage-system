#include "Student.h"
#include "StudentList.h"
#include "Menu.h"

//메인함수
//커맨드 라인 실행을 지원합니다.
int main(int argc, char* argv[])
{
	fstream file;

	file.open(fileName, ios::in);

	StudentList sList(file);

	MENU m;

	m.Menu(sList, file);

	file.close();

	cout << "프로그램을 종료합니다." << endl;

	return 0;
}