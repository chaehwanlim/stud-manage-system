#include "Student.h"
#include "StudentList.h"
#include "Menu.h"

//�����Լ�
//Ŀ�ǵ� ���� ������ �����մϴ�.
int main(int argc, char* argv[])
{
	fstream file;

	file.open(fileName, ios::in);

	StudentList sList(file);

	MENU m;

	m.Menu(sList, file);

	file.close();

	cout << "���α׷��� �����մϴ�." << endl;

	return 0;
}