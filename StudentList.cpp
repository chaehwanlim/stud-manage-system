#include "StudentList.h"

StudentList::StudentList() {}

StudentList::StudentList(fstream& file)
{
	string stuInfo[5];
	string oneLine;

	while (getline(file, oneLine)) {	//한 줄을 string형으로 입력받아
		char* oneLine_char = new char[100];
		strcpy_s(oneLine_char, strlen(oneLine.c_str()) + 1, oneLine.c_str());//임시로 char*형 변수에 담는다

		for (int i = 0; i < 5; i++) {	//그 한 줄을 5개의 정보로 분리해 저장
			stuInfo[i] = strtok_s(oneLine_char, "~", &oneLine_char);
		}

		//분리된 정보를 이용해 친구 인스턴스 생성
		Student tempStu(stuInfo[0], stuInfo[1],
			stuInfo[2], stuInfo[3], stuInfo[4]);

		//목록에 친구를 추가
		list.push_back(tempStu);
	}

	//파일 스트림 청소
	//file.clear();
}

//현재 목록의 친구 수를 반환한다.
int StudentList::getNumStu()
{
	return list.size();
}

//리스트에 친구를 추가
void StudentList::append(Student& newOne)
{
	list.push_back(newOne);
}

//친구 한 명을 참조하는 함수
Student& StudentList::getStu(int idx)
{
	return list.at(idx - 1);
}

//친구 한 명 삭제
void StudentList::deleteStu(int idx)
{
	vector<Student>::iterator it = list.begin();
	it += idx - 1;

	list.erase(it, it + 1);
}

//리스트의 친구들을 모두 콘솔에 출력
void StudentList::listAll()
{
	cout.setf(ios::left);	//좌측정렬

	//일정 크기의 칸 지정 후
	cout << "┌---------┬-----------------┬------------┬----------------------┬-----┬---------------┐" << endl;
	cout << "| ";
	cout << setw(MAX_INDEX_DIGITS + 2) << "Index" << "|";
	cout << setw(MAX_NAME_CHAR + 2) << " Name" << "|";
	cout << setw(MAX_ID_DIGITS + 2) << " StudentID" << "|";
	cout << setw(MAX_DEPARTMENT_CHAR + 2) << " Department" << "|";
	cout << setw(MAX_AGE_DIGITS + 2) << " Age" << "|";
	cout << setw(MAX_TEL_DIGITS + 2) << " Tel           |" << endl;
	cout << "├---------┼-----------------┼------------┼----------------------┼-----┼---------------┤" << endl;

	//각 친구들을 콘솔에 출력한다
	for (vector<Student>::iterator it = list.begin(); it != list.end(); it++) {
		cout << "| ";
		cout << setw(MAX_INDEX_DIGITS + 2) << it - list.begin() + 1 << "| ";
		cout << setw(MAX_NAME_CHAR + 1) << it->getName() << "| ";
		cout << setw(MAX_ID_DIGITS + 1) << it->getID() << "| ";
		cout << setw(MAX_DEPARTMENT_CHAR + 1) << it->getDept() << "| ";
		cout << setw(MAX_AGE_DIGITS + 1) << it->getAge() << "| ";
		cout << setw(MAX_TEL_DIGITS + 2) << it->getTel() << "|" << endl;
	}
	cout << "└---------┴-----------------┴------------┴----------------------┴-----┴---------------┘" << endl;
}

//입력된 id가 중복되는지 확인
bool StudentList::ifOverlap(string& idToComp)
{
	for (vector<Student>::iterator ptr = list.begin(); ptr != list.end(); ptr++)
	{
		if (ptr->getID().compare(idToComp) == 0)
			return true;
	}

	return false;	//아니면 false 반환
}

//주어진 커맨드에 따라 친구를 찾아 검색결과 목록에 추가
void StudentList::SearchExecution(StudentList& Result, int command)
{
	//입력 버퍼 청소
	cin.ignore(10, '\n');

	string keyword;	//찾을 keyword를 담는 변수

	switch (command)
	{
	case NAME:
		cout << "Name keyword? ";
		getline(cin, keyword);	//keyword 입력받기
		for (vector<Student>::iterator it = list.begin(); it != list.end(); it++)
		{	//목록 전체를 탐색	
			if (it->getName().compare(keyword) == 0)
			{	//키워드와 동일한 항목을 가졌을때 
				Result.append(*it);	//해당 친구를 찾기결과목록에 추가
			}
		}
		break;

	case ID:
		cout << "ID keyword? ";
		getline(cin, keyword);
		for (vector<Student>::iterator it = list.begin(); it != list.end(); it++)
		{	//목록 전체를 탐색	
			if (it->getID().compare(keyword) == 0)
			{	//키워드와 동일한 항목을 가졌을때 
				Result.append(*it);	//해당 친구를 찾기결과목록에 추가
			}
		}
		break;

	case DEPT:
		cout << "Department name keyword? ";
		getline(cin, keyword);
		for (vector<Student>::iterator it = list.begin(); it != list.end(); it++)
		{	//목록 전체를 탐색	
			if (it->getDept().compare(keyword) == 0)
			{	//키워드와 동일한 항목을 가졌을때 
				Result.append(*it);	//해당 친구를 찾기결과목록에 추가
			}
		}
		break;

	case AGE:
		cout << "Age keyword? ";
		getline(cin, keyword);
		for (vector<Student>::iterator it = list.begin(); it != list.end(); it++)
		{	//목록 전체를 탐색	
			if (it->getAge().compare(keyword) == 0)
			{	//키워드와 동일한 항목을 가졌을때 
				Result.append(*it);	//해당 친구를 찾기결과목록에 추가
			}
		}
		break;

	case TEL:
		cout << "Telephone keyword? ";
		getline(cin, keyword);
		for (vector<Student>::iterator it = list.begin(); it != list.end(); it++)
		{	//목록 전체를 탐색	
			if (it->getTel().compare(keyword) == 0)
			{	//키워드와 동일한 항목을 가졌을때 
				Result.append(*it);	//해당 친구를 찾기결과목록에 추가
			}
		}
		break;

	default:
		cout << "올바르게 입력해주세요.";
	}

	//sort(list.begin(), list.end(), Student::compareByNameAsc);

	cout << endl;
	cout << "- Search Result -" << endl;

}

void StudentList::Sort(int mode, int by)
{
	if (by == 1) //Ascending 오름차순
	{
		switch (mode)
		{
		case NAME:
			sort(list.begin(), list.end(), compareByNameAsc);
			break;
		case ID:
			sort(list.begin(), list.end(), compareByIDAsc);
			break;
		case DEPT:
			sort(list.begin(), list.end(), compareByDeptAsc);
			break;
		case AGE:
			sort(list.begin(), list.end(), compareByAgeAsc);
			break;
		case TEL:
			sort(list.begin(), list.end(), compareByTelAsc);
			break;
		}
	}
	else //Descending 내림차순
	{
		switch (mode)
		{
		case NAME:
			sort(list.begin(), list.end(), compareByNameDesc);
			break;
		case ID:
			sort(list.begin(), list.end(), compareByIDDesc);
			break;
		case DEPT:
			sort(list.begin(), list.end(), compareByDeptDesc);
			break;
		case AGE:
			sort(list.begin(), list.end(), compareByAgeDesc);
			break;
		case TEL:
			sort(list.begin(), list.end(), compareByTelDesc);
			break;
		}
	}
}

void StudentList::SaveNewStu(Student& newStudent, fstream& output)
{
	output.close();
	output.open(fileName, ios::app);
	output << newStudent.toFile();	//새 학생의 정보를 한 줄로 파일에 작성
}

void StudentList::SaveAll(fstream& output)
{
	output.close();
	output.open(fileName, ios::out);
	for (vector<Student>::iterator it = list.begin(); it != list.end(); it++)
	{
		output << it->toFile();
	}

	cout << "Save Complete" << endl;
}

//정렬함수
bool compareByNameAsc(Student& a, Student& b)
{
	return (a.getName() < b.getName());
}
bool compareByNameDesc(Student& a, Student& b)
{
	return (a.getName() > b.getName());
}
bool compareByIDAsc(Student& a, Student& b)
{
	return (a.getID() < b.getID());
}
bool compareByIDDesc(Student& a, Student& b)
{
	return (a.getID() > b.getID());
}
bool compareByDeptAsc(Student& a, Student& b)
{
	return (a.getDept() < b.getDept());
}
bool compareByDeptDesc(Student& a, Student& b)
{
	return (a.getDept() > b.getDept());
}
bool compareByAgeAsc(Student& a, Student& b)
{
	return (a.getAge() < b.getAge());
}
bool compareByAgeDesc(Student& a, Student& b)
{
	return (a.getAge() > b.getAge());
}
bool compareByTelAsc(Student& a, Student& b)
{
	return (a.getTel() < b.getTel());
}
bool compareByTelDesc(Student& a, Student& b)
{
	return (a.getTel() > b.getTel());
}

StudentList::~StudentList() {}

