#include "Student.h"

Student::Student() {}

Student::Student(string& newName, string& newID, string& newDept, string& newAge, string& newTel)
	: name(newName), id(newID), dept(newDept), age(newAge), tel(newTel)
{}

//�ش� �л��� ������ ������ string���� ��ȯ
string Student::toFile()
{
	string output;
	output = name + "~" + id + "~" + dept + "~" + age + "~" + tel + "\n";
	return output;
}

//�ֿܼ� �ڽ��� ������ ����Ѵ�.
void Student::print()
{
	cout.setf(ios::left);	//��������
	cout << setw(MAX_INDEX_DIGITS) << "      |";
	cout << setw(MAX_NAME_CHAR) << name << "|";
	cout << setw(MAX_ID_DIGITS) << id << "|";
	cout << setw(MAX_DEPARTMENT_CHAR) << dept << "|";
	cout << setw(MAX_AGE_DIGITS + 1) << age << "|";
	cout << setw(MAX_TEL_DIGITS) << tel << endl;;
}

//�ڽ��� �Ϻ� ������ ��ȯ�Ѵ�.
string& Student::getName()
{
	return name;
}
string& Student::getID()
{
	return id;
}
string& Student::getDept()
{
	return dept;
}
string& Student::getAge()
{
	return age;
}
string& Student::getTel()
{
	return tel;
}

void Student::setName(const string& tempName)
{
	name = tempName;
}
void Student::setID(const string& tempID)
{
	id = tempID;
}
void Student::setDept(const string& tempDept)
{
	dept = tempDept;
}
void Student::setAge(const string& tempAge)
{
	age = tempAge;
}
void Student::setTel(const string& tempTel)
{
	tel = tempTel;
}

Student::~Student() {}