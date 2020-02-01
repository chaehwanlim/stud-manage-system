#pragma once
#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <iostream>	//�⺻ �����
#include <string>	//���ڿ��� �ٷ�� ���� �������(STL)
#include <iomanip>	//�ܼ� ǥ�� �� ���� ������ ���� �������
using namespace std;

//Student�� �Ӽ����� �ִ� ���ڼ� ����
#define MAX_INDEX_DIGITS 6
#define MAX_NAME_CHAR 15
#define MAX_ID_DIGITS 10
#define MAX_DEPARTMENT_CHAR 20
#define MAX_AGE_DIGITS 3
#define MAX_TEL_DIGITS 12

class Student {
private:
	//�л��� �Ӽ��� ��� ����
	string name;
	string id;
	string dept;
	string age;
	string tel;

public:
	//Student ������
	Student();
	Student(string&, string&, string&, string&, string&);

	//�ش� �л��� ������ ������ string���� ��ȯ
	string toFile();

	//�ش� �л��� ������ �ַܼ� ���
	void print();

	//�ش� �л��� �Ϻ� ������ ��ȯ�ϱ� ���� �Լ�
	string& getName();
	string& getID();
	string& getDept();
	string& getAge();
	string& getTel();

	//�л� ���� ����
	void setName(const string&);
	void setID(const string&);
	void setDept(const string&);
	void setAge(const string&);
	void setTel(const string&);

	//���� ���� �� �Լ�
	friend bool compareByNameAsc(Student&, Student&);
	friend bool compareByNameDesc(Student&, Student&);
	friend bool compareByIDAsc(Student&, Student&);
	friend bool compareByIDDesc(Student&, Student&);
	friend bool compareByDeptAsc(Student&, Student&);
	friend bool compareByDeptDesc(Student&, Student&);
	friend bool compareByAgeAsc(Student&, Student&);
	friend bool compareByAgeDesc(Student&, Student&);
	friend bool compareByTelAsc(Student&, Student&);
	friend bool compareByTelDesc(Student&, Student&);

	//�Ҹ���
	~Student();
};



#endif