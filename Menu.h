#pragma once
#ifndef __MENU_H__
#define __MENU_H__

#include "StudentList.h"
using namespace std;

//Menu �Լ����� ����� ������ ����
namespace MAIN
{
	enum command { INSERT = 1, ATTR = 2, SORT = 3, SEARCH = 4, DELETE = 5, SAVE = 6, SAVEANDEXIT = 7 };
}

class MENU
{
public:

	//�޴�ȭ���� ��Ÿ���� ������� Ŀ�ǵ带 �Է¹޴� �Լ�
	void Menu(StudentList&, fstream&);

	//�޴�1��. ���
	void Insertion(StudentList&, fstream&);

	//�޴�2��. ����
	void Modification(StudentList&, fstream&);

	//�޴�3��. ����
	void Sort(StudentList&, fstream&);

	//�޴�4��. �˻�
	void Search(StudentList&);

	//�޴�5��. ����
	void Deletion(StudentList&, fstream&);

	//�޴�6��. ����
	void Save(StudentList&, fstream&);
};

#endif