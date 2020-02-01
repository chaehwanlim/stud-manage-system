#pragma once
#ifndef __MENU_H__
#define __MENU_H__

#include "StudentList.h"
using namespace std;

//Menu 함수에서 사용할 열거형 변수
namespace MAIN
{
	enum command { INSERT = 1, ATTR = 2, SORT = 3, SEARCH = 4, DELETE = 5, SAVE = 6, SAVEANDEXIT = 7 };
}

class MENU
{
public:

	//메뉴화면을 나타내고 사용자의 커맨드를 입력받는 함수
	void Menu(StudentList&, fstream&);

	//메뉴1번. 등록
	void Insertion(StudentList&, fstream&);

	//메뉴2번. 수정
	void Modification(StudentList&, fstream&);

	//메뉴3번. 정렬
	void Sort(StudentList&, fstream&);

	//메뉴4번. 검색
	void Search(StudentList&);

	//메뉴5번. 삭제
	void Deletion(StudentList&, fstream&);

	//메뉴6번. 저장
	void Save(StudentList&, fstream&);
};

#endif