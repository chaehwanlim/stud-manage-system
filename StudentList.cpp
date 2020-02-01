#include "StudentList.h"

StudentList::StudentList() {}

StudentList::StudentList(fstream& file)
{
	string stuInfo[5];
	string oneLine;

	while (getline(file, oneLine)) {	//�� ���� string������ �Է¹޾�
		char* oneLine_char = new char[100];
		strcpy_s(oneLine_char, strlen(oneLine.c_str()) + 1, oneLine.c_str());//�ӽ÷� char*�� ������ ��´�

		for (int i = 0; i < 5; i++) {	//�� �� ���� 5���� ������ �и��� ����
			stuInfo[i] = strtok_s(oneLine_char, "~", &oneLine_char);
		}

		//�и��� ������ �̿��� ģ�� �ν��Ͻ� ����
		Student tempStu(stuInfo[0], stuInfo[1],
			stuInfo[2], stuInfo[3], stuInfo[4]);

		//��Ͽ� ģ���� �߰�
		list.push_back(tempStu);
	}

	//���� ��Ʈ�� û��
	//file.clear();
}

//���� ����� ģ�� ���� ��ȯ�Ѵ�.
int StudentList::getNumStu()
{
	return list.size();
}

//����Ʈ�� ģ���� �߰�
void StudentList::append(Student& newOne)
{
	list.push_back(newOne);
}

//ģ�� �� ���� �����ϴ� �Լ�
Student& StudentList::getStu(int idx)
{
	return list.at(idx - 1);
}

//ģ�� �� �� ����
void StudentList::deleteStu(int idx)
{
	vector<Student>::iterator it = list.begin();
	it += idx - 1;

	list.erase(it, it + 1);
}

//����Ʈ�� ģ������ ��� �ֿܼ� ���
void StudentList::listAll()
{
	cout.setf(ios::left);	//��������

	//���� ũ���� ĭ ���� ��
	cout << "��---------��-----------------��------------��----------------------��-----��---------------��" << endl;
	cout << "| ";
	cout << setw(MAX_INDEX_DIGITS + 2) << "Index" << "|";
	cout << setw(MAX_NAME_CHAR + 2) << " Name" << "|";
	cout << setw(MAX_ID_DIGITS + 2) << " StudentID" << "|";
	cout << setw(MAX_DEPARTMENT_CHAR + 2) << " Department" << "|";
	cout << setw(MAX_AGE_DIGITS + 2) << " Age" << "|";
	cout << setw(MAX_TEL_DIGITS + 2) << " Tel           |" << endl;
	cout << "��---------��-----------------��------------��----------------------��-----��---------------��" << endl;

	//�� ģ������ �ֿܼ� ����Ѵ�
	for (vector<Student>::iterator it = list.begin(); it != list.end(); it++) {
		cout << "| ";
		cout << setw(MAX_INDEX_DIGITS + 2) << it - list.begin() + 1 << "| ";
		cout << setw(MAX_NAME_CHAR + 1) << it->getName() << "| ";
		cout << setw(MAX_ID_DIGITS + 1) << it->getID() << "| ";
		cout << setw(MAX_DEPARTMENT_CHAR + 1) << it->getDept() << "| ";
		cout << setw(MAX_AGE_DIGITS + 1) << it->getAge() << "| ";
		cout << setw(MAX_TEL_DIGITS + 2) << it->getTel() << "|" << endl;
	}
	cout << "��---------��-----------------��------------��----------------------��-----��---------------��" << endl;
}

//�Էµ� id�� �ߺ��Ǵ��� Ȯ��
bool StudentList::ifOverlap(string& idToComp)
{
	for (vector<Student>::iterator ptr = list.begin(); ptr != list.end(); ptr++)
	{
		if (ptr->getID().compare(idToComp) == 0)
			return true;
	}

	return false;	//�ƴϸ� false ��ȯ
}

//�־��� Ŀ�ǵ忡 ���� ģ���� ã�� �˻���� ��Ͽ� �߰�
void StudentList::SearchExecution(StudentList& Result, int command)
{
	//�Է� ���� û��
	cin.ignore(10, '\n');

	string keyword;	//ã�� keyword�� ��� ����

	switch (command)
	{
	case NAME:
		cout << "Name keyword? ";
		getline(cin, keyword);	//keyword �Է¹ޱ�
		for (vector<Student>::iterator it = list.begin(); it != list.end(); it++)
		{	//��� ��ü�� Ž��	
			if (it->getName().compare(keyword) == 0)
			{	//Ű����� ������ �׸��� �������� 
				Result.append(*it);	//�ش� ģ���� ã������Ͽ� �߰�
			}
		}
		break;

	case ID:
		cout << "ID keyword? ";
		getline(cin, keyword);
		for (vector<Student>::iterator it = list.begin(); it != list.end(); it++)
		{	//��� ��ü�� Ž��	
			if (it->getID().compare(keyword) == 0)
			{	//Ű����� ������ �׸��� �������� 
				Result.append(*it);	//�ش� ģ���� ã������Ͽ� �߰�
			}
		}
		break;

	case DEPT:
		cout << "Department name keyword? ";
		getline(cin, keyword);
		for (vector<Student>::iterator it = list.begin(); it != list.end(); it++)
		{	//��� ��ü�� Ž��	
			if (it->getDept().compare(keyword) == 0)
			{	//Ű����� ������ �׸��� �������� 
				Result.append(*it);	//�ش� ģ���� ã������Ͽ� �߰�
			}
		}
		break;

	case AGE:
		cout << "Age keyword? ";
		getline(cin, keyword);
		for (vector<Student>::iterator it = list.begin(); it != list.end(); it++)
		{	//��� ��ü�� Ž��	
			if (it->getAge().compare(keyword) == 0)
			{	//Ű����� ������ �׸��� �������� 
				Result.append(*it);	//�ش� ģ���� ã������Ͽ� �߰�
			}
		}
		break;

	case TEL:
		cout << "Telephone keyword? ";
		getline(cin, keyword);
		for (vector<Student>::iterator it = list.begin(); it != list.end(); it++)
		{	//��� ��ü�� Ž��	
			if (it->getTel().compare(keyword) == 0)
			{	//Ű����� ������ �׸��� �������� 
				Result.append(*it);	//�ش� ģ���� ã������Ͽ� �߰�
			}
		}
		break;

	default:
		cout << "�ùٸ��� �Է����ּ���.";
	}

	//sort(list.begin(), list.end(), Student::compareByNameAsc);

	cout << endl;
	cout << "- Search Result -" << endl;

}

void StudentList::Sort(int mode, int by)
{
	if (by == 1) //Ascending ��������
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
	else //Descending ��������
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
	output << newStudent.toFile();	//�� �л��� ������ �� �ٷ� ���Ͽ� �ۼ�
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

//�����Լ�
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

