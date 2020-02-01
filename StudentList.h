#pragma once
#ifndef __STUDENTLIST_H__
#define __STUDENTLIST_H__

#include <vector>	//컨테이너
#include <fstream>	//파일 입출력을 위한 헤더파일
#include <algorithm>//정렬알고리즘
#include "Student.h"
using namespace std;

#define fileName "studentList.txt"

enum ATTR { NAME = 1, ID = 2, DEPT = 3, AGE = 4, TEL = 5, LISTALL = 6 };

class StudentList
{
private:
	//학생들을 담는 Student Container
	vector<Student> list;

public:
	//StudentList의 생성자 
	StudentList();

	StudentList(fstream&);

	//현재 목록의 친구 수를 반환한다.
	int getNumStu();

	//리스트에 친구를 추가
	void append(Student&);

	//친구 한 명을 참조하는 함수
	Student& getStu(int);

	//친구 한 명을 삭제하는 함수
	void deleteStu(int);

	//리스트의 친구들을 모두 콘솔에 출력
	void listAll();

	//입력된 id가 중복되는지 확인
	bool ifOverlap(string&);

	//주어진 커맨드에 따라 친구를 찾아 검색결과 목록에 추가
	void SearchExecution(StudentList&, int command);

	//정렬
	void Sort(int, int);

	//새 친구를 파일에 저장하는 함수
	void SaveNewStu(Student&, fstream&);

	//모든 친구를 파일에 새로 저장
	void SaveAll(fstream&);

	~StudentList();
};

//비교함수
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