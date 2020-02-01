#include "Menu.h"

void MENU::Menu(StudentList& sList, fstream& file)
{
	//메인화면 커맨드와 탈출을 위한 flag 선언
	int mainCmd = 0;
	bool flag = true;

	while ((mainCmd != MAIN::SAVEANDEXIT) && (flag == true))
	{
		system("cls");
		sList.listAll();

		if (mainCmd == 0)
		{
			cout << "1. Insert" << endl;
			cout << "2. Modify" << endl;
			cout << "3. Sort" << endl;
			cout << "4. Search" << endl;
			cout << "5. Delete" << endl;
			cout << "6. Save" << endl;
			cout << "7. Save and Exit" << endl;
			cout << "> ";
			cin >> mainCmd;
			cout << endl;
		}

		switch (mainCmd)
		{
		case MAIN::INSERT:
			Insertion(sList, file);
			break;
		case MAIN::ATTR:
			Modification(sList, file);
			break;
		case MAIN::SORT:
			Sort(sList, file);
			break;
		case MAIN::SEARCH:
			Search(sList);
			break;
		case MAIN::DELETE:
			Deletion(sList, file);
			break;
		case MAIN::SAVE:
			Save(sList, file);
			break;
		case MAIN::SAVEANDEXIT:
			Save(sList, file);
			flag = false;
			break;
		default:
			while ((mainCmd < 1 || mainCmd > 7))
			{
				cout << "올바른 숫자를 입력해주세요. (1-7) ";
				cin >> mainCmd;
			}
		}

		mainCmd = 0;
	}
}

void MENU::Insertion(StudentList& sList, fstream& file)
{
	//입력 버퍼 청소
	cin.ignore(10, '\n');

	//각 항목에 대해 입력받고 조건 부합 여부를 확인한다.
	string tempName("");
	cout << "Name ? ";
	getline(cin, tempName);
	while (tempName.length() > MAX_NAME_CHAR || tempName.length() == 0)
	{
		cout << "Name should not be blank and the maximum input is "
			<< MAX_NAME_CHAR << " characters." << endl;
		cout << "Name ? ";
		getline(cin, tempName);
	}

	string tempID("");
	cout << "Student ID ? ";
	getline(cin, tempID);
	while (tempID.length() > MAX_ID_DIGITS || tempID.length() == 0)
	{
		cout << "Student ID should not be blank and the maximum input is "
			<< MAX_ID_DIGITS << " digits." << endl;
		cout << "Student ID ? ";
		getline(cin, tempID);
	}
	while (sList.ifOverlap(tempID) == true)
	{	//동일한 ID가 있는지 확인한다.
		cout << "Error : Already inserted" << endl;
		cout << "Student ID ? ";
		getline(cin, tempID);
	}

	string tempDept;
	cout << "Department ? ";
	getline(cin, tempDept);
	while (tempDept.length() > MAX_DEPARTMENT_CHAR)
	{
		cout << "Maximum input is " << MAX_DEPARTMENT_CHAR << " characters." << endl;
		cout << "Department ? ";
		getline(cin, tempDept);
	}

	string tempAge;
	cout << "Age ? ";
	getline(cin, tempAge);
	while (tempAge.length() > MAX_AGE_DIGITS)
	{
		cout << "Maximum input is " << MAX_AGE_DIGITS << " digits." << endl;
		cout << "Age ? ";
		getline(cin, tempAge);
	}

	string tempTel;
	cout << "Tel ? ";
	getline(cin, tempTel);
	while (tempTel.length() > MAX_TEL_DIGITS)
	{
		cout << "Maximum input is " << MAX_TEL_DIGITS << " digits." << endl;
		cout << "Tel ? ";
		getline(cin, tempTel);
	}
	cout << endl;

	//새 친구를 생성하고 sList에 추가한다. 또한 파일에도 작성한다.
	Student newStu(tempName, tempID, tempDept, tempAge, tempTel);
	sList.append(newStu);

	sList.SaveNewStu(newStu, file);
}

void MENU::Modification(StudentList& sList, fstream& file)
{
	int idxToModify = 0;
	int modifyCmd = 0;
	int yesOrNo = 2;
	bool flag = false;
	bool flag2 = false;

	string modifyTo = "";

	cout << "- Modify -" << endl;
	//cout << "Current studentlist..." << endl;
	//sList.listAll(); cout << endl;
	while (flag == false)
	{
		flag2 = false;
		while (flag2 == false)
		{
			cout << "Enter the index of student you want to modify..." << endl;
			cout << "(Back to Main Menu : 0)" << endl;
			cout << "> ";
			cin >> idxToModify;

			if (idxToModify == 0)
			{
				flag = true;
				flag2 = true;
				continue;
			}

			if (idxToModify < 0 || idxToModify > sList.getNumStu())
				continue;

			cout << endl;
			cout << "Select the number to modify..." << endl;
			cout << "0. Back to main menu" << endl;
			cout << "1. Name" << endl;
			cout << "2. ID" << endl;
			cout << "3. Department" << endl;
			cout << "4. Age" << endl;
			cout << "5. Telephone" << endl;
			cout << "> ";
			cin >> modifyCmd;

			if (modifyCmd == 0)
			{
				flag = true;
				flag2 = true;
				continue;
			}

			if (modifyCmd < 1 || modifyCmd > 5)
				continue;

			//정보가 모두 올바르게 입력됐으므로 flag를 바꿈
			flag2 = true;
		}
		cout << endl;

		//입력 버퍼 청소
		cin.ignore(10, '\n');

		switch (modifyCmd)
		{
		case NAME:
			cout << "Enter a name you want to modify..." << endl << "> ";
			getline(cin, modifyTo);
			while (modifyTo.length() > MAX_NAME_CHAR || modifyTo.length() == 0)
			{
				cout << "Name should not be blank and the maximum input is "
					<< MAX_NAME_CHAR << " characters." << endl;
				cout << "Name ? ";
				getline(cin, modifyTo);
			}
			cout << endl << "Do you really want to modify?" << endl;
			cout << "Change : " << sList.getStu(idxToModify).getName() << " -> " << modifyTo << endl;
			cout << "(Yes : 1, No : 0) ";
			cin >> yesOrNo;
			if (yesOrNo == 1)
			{
				sList.getStu(idxToModify).setName(modifyTo);
				flag = true;
			}
			break;

		case ID:
			cout << "Enter a student id you want to modify..." << endl << "> ";
			getline(cin, modifyTo);
			while (modifyTo.length() > MAX_ID_DIGITS || modifyTo.length() == 0)
			{
				cout << "Student ID should not be blank and the maximum input is "
					<< MAX_ID_DIGITS << " digits." << endl;
				cout << "Student ID ? ";
				getline(cin, modifyTo);
			}
			while (sList.ifOverlap(modifyTo) == true)
			{	//동일한 ID가 있는지 확인한다.
				cout << "Error : Already inserted" << endl;
				cout << "Student ID ? ";
				getline(cin, modifyTo);
			}
			cout << endl << "Do you really want to modify?" << endl;
			cout << "Change : " << sList.getStu(idxToModify).getID() << " -> " << modifyTo << endl;
			cout << "(Yes : 1, No : 0) ";
			cin >> yesOrNo;
			if (yesOrNo == 1)
			{
				sList.getStu(idxToModify).setID(modifyTo);
				flag = true;
			}
			break;

		case DEPT:
			cout << "Enter a department you want to modify..." << endl << "> ";
			getline(cin, modifyTo);
			while (modifyTo.length() > MAX_DEPARTMENT_CHAR)
			{
				cout << "Maximum input is " << MAX_DEPARTMENT_CHAR << " characters." << endl;
				cout << "Department ? ";
				getline(cin, modifyTo);
			}
			cout << endl << "Do you really want to modify?" << endl;
			cout << "Change : " << sList.getStu(idxToModify).getDept() << " -> " << modifyTo << endl;
			cout << "(Yes : 1, No : 0) ";
			cin >> yesOrNo;
			if (yesOrNo == 1)
			{
				sList.getStu(idxToModify).setDept(modifyTo);
				flag = true;
			}
			break;

		case AGE:
			cout << "Enter age you want to modify..." << endl << "> ";
			getline(cin, modifyTo);
			while (modifyTo.length() > MAX_AGE_DIGITS)
			{
				cout << "Maximum input is " << MAX_AGE_DIGITS << " digits." << endl;
				cout << "Age ? ";
				getline(cin, modifyTo);
			}
			cout << endl << "Do you really want to modify?" << endl;
			cout << "Change : " << sList.getStu(idxToModify).getAge() << " -> " << modifyTo << endl;
			cout << "(Yes : 1, No : 0) ";
			cin >> yesOrNo;
			if (yesOrNo == 1)
			{
				sList.getStu(idxToModify).setAge(modifyTo);
				flag = true;
			}
			break;

		case TEL:
			cout << "Enter a telephone number you want to modify..." << endl << "> ";
			getline(cin, modifyTo);
			while (modifyTo.length() > MAX_TEL_DIGITS)
			{
				cout << "Maximum input is " << MAX_TEL_DIGITS << " digits." << endl;
				cout << "Tel ? ";
				getline(cin, modifyTo);
			}
			cout << endl << "Do you really want to modify?" << endl;
			cout << "Change : " << sList.getStu(idxToModify).getTel() << " -> " << modifyTo << endl;
			cout << "(Yes : 1, No : 0) ";
			cin >> yesOrNo;
			if (yesOrNo == 1)
			{
				sList.getStu(idxToModify).setTel(modifyTo);
				flag = true;
			}
			break;

		}
	}
}

void MENU::Sort(StudentList& sList, fstream& file)
{
	int mode = 0, by = 0;
	bool flag = false;

	cout << "- Sort -" << endl;
	cout << "0. Back to main menu" << endl;
	cout << "1. Sort by name" << endl;
	cout << "2. Sort by student ID (10 numbers)" << endl;
	cout << "3. Sort by department name" << endl;
	cout << "4. Sort by Age" << endl;
	cout << "5. Sort by Telephone" << endl;
	cout << "> ";
	cin >> mode;

	while (mode < 0 || mode > 5)
	{
		cout << "Enter the right command(1-6): ";
		cin >> mode;
	}

	if ((1 <= mode) && (mode <= 5))
	{
		cout << "Ascending(1)? or Descending(2)? " << endl;
		cout << "(Back to main menu : 0)" << endl;
		cout << "> ";
		cin >> by;

		while (by < 0 || by > 2)
		{
			cout << "Enter the right command(0-2): ";
			cin >> by;
		}

		if (by != 0)
			sList.Sort(mode, by);
	}

}

void MENU::Search(StudentList& sList)
{
	StudentList Result;
	int searchCmd = 0;

	cout << "- Search -" << endl;
	cout << "0. Back to main menu" << endl;
	cout << "1. Search by name" << endl;
	cout << "2. Search by student ID (10 numbers)" << endl;
	cout << "3. Search by department name" << endl;
	cout << "4. Search by Age" << endl;
	cout << "5. Search by Telephone" << endl;
	cout << "6. List ALL" << endl << endl;
	cout << "> ";
	cin >> searchCmd;

	while (searchCmd < 0 || searchCmd > 6)
	{
		cout << "Enter the right command(1-6): ";
		cin >> searchCmd;
	}

	if ((1 <= searchCmd) && (searchCmd <= 5))
	{
		//찾기
		sList.SearchExecution(Result, searchCmd);
		Result.Sort(1, 1);
		Result.listAll();
	}
	else if (searchCmd == 6)
	{
		sList.listAll();
	}

}

void MENU::Deletion(StudentList& sList, fstream& file)
{
	int idxToDel = 0;
	int yesOrNo = 2;
	bool flag = false;

	cout << "- Delete -" << endl;

	while (flag == false)
	{
		cout << "Enter the index of student you want to delete..." << endl;
		cout << "(Back to main menu : 0)" << endl;
		cout << "> ";
		cin >> idxToDel;
		if ((idxToDel < 0) || (idxToDel > sList.getNumStu()))
			continue;

		cout << "Do you really want to delete the student?" << endl;
		cout << "Delete Subject..." << endl;
		cout << setw(MAX_INDEX_DIGITS) << "Index" << "|";
		cout << setw(MAX_NAME_CHAR) << "Name" << "|";
		cout << setw(MAX_ID_DIGITS) << "StudentID" << "|";
		cout << setw(MAX_DEPARTMENT_CHAR) << "Department" << "|";
		cout << setw(MAX_AGE_DIGITS + 1) << "Age" << "|";
		cout << setw(MAX_TEL_DIGITS) << "Tel" << endl;

		cout << setw(MAX_INDEX_DIGITS) << idxToDel;
		sList.getStu(idxToDel).print();

		cout << "(Yes : 1, No : 0)" << endl;
		cout << "> ";
		cin >> yesOrNo;
		if (yesOrNo)
		{
			sList.deleteStu(idxToDel);
			flag = true;
		}
	}
}

void MENU::Save(StudentList& sList, fstream& file)
{
	sList.SaveAll(file);
}