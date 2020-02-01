#pragma once
#ifndef __STUDENTLIST_H__
#define __STUDENTLIST_H__

#include <vector>	//�����̳�
#include <fstream>	//���� ������� ���� �������
#include <algorithm>//���ľ˰���
#include "Student.h"
using namespace std;

#define fileName "studentList.txt"

enum ATTR { NAME = 1, ID = 2, DEPT = 3, AGE = 4, TEL = 5, LISTALL = 6 };

class StudentList
{
private:
	//�л����� ��� Student Container
	vector<Student> list;

public:
	//StudentList�� ������ 
	StudentList();

	StudentList(fstream&);

	//���� ����� ģ�� ���� ��ȯ�Ѵ�.
	int getNumStu();

	//����Ʈ�� ģ���� �߰�
	void append(Student&);

	//ģ�� �� ���� �����ϴ� �Լ�
	Student& getStu(int);

	//ģ�� �� ���� �����ϴ� �Լ�
	void deleteStu(int);

	//����Ʈ�� ģ������ ��� �ֿܼ� ���
	void listAll();

	//�Էµ� id�� �ߺ��Ǵ��� Ȯ��
	bool ifOverlap(string&);

	//�־��� Ŀ�ǵ忡 ���� ģ���� ã�� �˻���� ��Ͽ� �߰�
	void SearchExecution(StudentList&, int command);

	//����
	void Sort(int, int);

	//�� ģ���� ���Ͽ� �����ϴ� �Լ�
	void SaveNewStu(Student&, fstream&);

	//��� ģ���� ���Ͽ� ���� ����
	void SaveAll(fstream&);

	~StudentList();
};

//���Լ�
bool compareByNameAsc(Student&, Student&);
bool compareByNameDesc(Student&, Student&);
bool compareByIDAsc(Student&, Student&);
bool compareByIDDesc(Student&, Student&);
bool compareByDeptAsc(Student&, Student&);
bool compareByDeptDesc(Student&, Student&);
bool compareByAgeAsc(Student&, Student&);
bool compareByAgeDesc(Student&, Student&);
bool compareByTelAsc(Student&, Student&);
bool compareByTelDesc(Student&, Student&);

#endif