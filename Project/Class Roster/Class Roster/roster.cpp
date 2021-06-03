//Requirement filled: B. Create a C++ project in your integrated development environment (IDE) with the following file: roster.cpp
#include <iostream>
#include <string>
#include <sstream>
#include "roster.h"
//Include all libraries needed.

/*
Following Requirements E1 & E2:
1.  Create an array of pointers, classRosterArray, to hold the data provided in the “studentData Table.”
2.  Create a student object for each student in the data table and populate classRosterArray.
	a.  Parse each set of data identified in the “studentData Table.”
	b.  Add each student object to classRosterArray.
*/

Roster::Roster() //The empty constructor sets to default values
{
	this->capacity = 0;
	this->lastIndex = -1; //-1 means empty in this case.
	this->classRosterArray = nullptr;
}

Roster::Roster(int capacity) //Sets max capacity for the roster.
{
	this->capacity = capacity;
	this->lastIndex = -1; //-1 means empty in this case.
	this->classRosterArray = new Student* [capacity]; //this creates the array of pointers to the Students when you eventually create them.
}

void Roster::add(string ID, string fName, string lName, string emailAdd, int sAge, int days1, int days2, int days3, Degree degreeType)
{

	//Make an array to get the days into a cronstruction
	int classDaysArray[Student::numDaySize];
	classDaysArray[0] = days1;
	classDaysArray[1] = days2;
	classDaysArray[2] = days3;

	classRosterArray[lastIndex] = new Student(ID, fName, lName, emailAdd, sAge, classDaysArray, degreeType);

	/*else if (degreeType == Degree::NETWORK) classRosterArray[lastIndex] = new Student(ID, fName, lName, emailAdd, sAge, classDaysArray, degreeType);

	else classRosterArray[lastIndex] = new Student(ID, fName, lName, emailAdd, sAge, classDaysArray, degreeType); */
};

void Roster::parseAdd(string datarow) // Create a student object for each student in the data table and populate classRosterArray. a.  Parse each set of data identified in the “studentData Table.”
//b.  Add each student object to classRosterArray.
{
	if (lastIndex < capacity) {
		lastIndex++;
		int dayArray[Student::numDaySize]; //Temporary array.

		//Parsing through each string in student and delimiting on the comma.
		//Read the ID
		int rhs = datarow.find(",");
		string f1 = datarow.substr(0, rhs);

		//Read the first name of the student
		int lhs = rhs + 1;
		rhs = datarow.find(",", lhs);
		string f2 = datarow.substr(lhs, rhs - lhs);

		//Read the last name of the student
		lhs = rhs + 1;
		rhs = datarow.find(",", lhs);
		string f3 = datarow.substr(lhs, rhs - lhs);

		//Reading the email of the student on allStudentData
		lhs = rhs + 1;
		rhs = datarow.find(",", lhs);
		string f4 = datarow.substr(lhs, rhs - lhs);

		//Reading the age of the students in allStudentData
		//Need to convert age to an int. Use the stoi function.
		lhs = rhs + 1;
		rhs = datarow.find(",", lhs);
		int f5 = stoi(datarow.substr(lhs, rhs - lhs));

		//Read the number of days in the course. NEED TO CONVERT TO INTEGER. Use stoi known as s to i (string to integer).
		lhs = rhs + 1;
		rhs = datarow.find(",", lhs);
		int f6 = stoi(datarow.substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = datarow.find(",", lhs);
		int f7 = stoi(datarow.substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = datarow.find(",", lhs);
		int f8 = stoi(datarow.substr(lhs, rhs - lhs));

		//Reading the email of the student on allStudentData
		lhs = rhs + 1;
		rhs = datarow.find(",", lhs);
		string f9 = datarow.substr(lhs, rhs - lhs);
		Degree f10 = SECURITY;
		if (f9 == "SOFTWARE") {
			f10 = SOFTWARE;
		}
		if (f9 == "NETWORK") {
			f10 = NETWORK;
		}

		add(f1, f2, f3, f4, f5, f6, f7, f8, f10);

	}
}

void Roster::printAll()
{
	//Roll through the array of Students and call print method for each one.
	for (int i = 0; i <= this->lastIndex; i++) (this->classRosterArray)[i]->print();
}

void Roster::remove(string ID) /*Requirement E3b: Removes students from the roster by student ID. 
If the student ID does not exist, the function prints an error message indicating that the student was not found.*/
{
	bool foundID = false;
	for (int i = 0; i <= lastIndex; i++) {
		if (this->classRosterArray[i]->getStudentID() == ID) { //Book is found.
			foundID = true;
			delete this->classRosterArray[i];
			this->classRosterArray[i] = this->classRosterArray[lastIndex];
			cout << "Done!" << endl;
			cout << "" << endl;
			lastIndex--; 
		}
	}
	if (!foundID) { //If the student ID does not exist, the function prints an error message indicating that the student was not found.
		cout << "Sorry! This student ID: " << ID << " is not found." << endl;
	}
}

void Roster::printAverageDaysInCourse(string ID) /* Requirement E3b: public void printAverageDaysInCourse(string studentID)  
that correctly prints a student’s average number of days in the three courses. The student is identified by the studentID parameter. */
{
	bool foundID = false;
	for (int i = 0; i <= lastIndex; i++) {
		if(this->classRosterArray[i]->getStudentID() == ID){
			foundID = true;
			int* d = classRosterArray[i]->getNumDaysComplete();
			cout << "Average number of days in three courses of student ID " << ID << " is " << (d[0] + d[1] + d[2]) / 3 << "\n";
		}
	}
	if (!foundID) cout << "ID not found! \n";
}

void Roster::printInvalidEmails()
{
	for (int i = 0; i <= lastIndex; i++) {
		string varEmail = classRosterArray[i]->getEmailAddress();
		if ((varEmail.find("@") == string::npos || varEmail.find(".") == string::npos) || (varEmail.find(" ") != string::npos)) {
			cout << varEmail << endl;
		}

	}
}

void Roster::printByDegreeProgram(Degree degreeType)
{
	for (int i = 0; i <= lastIndex; i++) {
		if (this->classRosterArray[i]->getDegreePrgrm() == degreeType) this->classRosterArray[i]->print();
	}
}

Student* Roster::getStudent(int num)
{
	return classRosterArray[num];
}

Roster::~Roster()
{
	for (int i = 0; i < numStudents; i++) {
		delete this->classRosterArray[i];
	}
	delete this;
}













