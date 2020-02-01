#pragma once
#ifndef __STUDENT_H__
#define __STUDENT_H__

#include <iostream>	//기본 입출력
#include <string>	//문자열을 다루기 위한 헤더파일(STL)
#include <iomanip>	//콘솔 표시 시 간격 조절을 위한 헤더파일
using namespace std;

//Student의 속성들의 최대 글자수 제한
#define MAX_INDEX_DIGITS 6
#define MAX_NAME_CHAR 15
#define MAX_ID_DIGITS 10
#define MAX_DEPARTMENT_CHAR 20
#define MAX_AGE_DIGITS 3
#define MAX_TEL_DIGITS 12

class Student {
private:
	//학생의 속성을 담는 변수
	string name;
	string id;
	string dept;
	string age;
	string tel;

public:
	//Student 생성자
	Student();
	Student(string&, string&, string&, string&, string&);

	//해당 학생의 정보를 한줄의 string으로 변환
	string toFile();

	//해당 학생의 정보를 콘솔로 출력
	void print();

	//해당 학생의 일부 정보를 반환하기 위한 함수
	string& getName();
	string& getID();
	string& getDept();
	string& getAge();
	string& getTel();

	//학생 정보 수정
	void setName(const string&);
	void setID(const string&);
	void setDept(const string&);
	void setAge(const string&);
	void setTel(const string&);

	//여러 가지 비교 함수
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

	//소멸자
	~Student();
};



#endif