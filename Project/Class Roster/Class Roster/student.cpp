#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

#include "student.h"

Student::Student() { 
	//Empty constructor will set all to default values
	this->StudentID = "";
	this->FirstName = "";
	this->LastName = "";
	this->EmailAddress = "";
	this->StudentAge = 0;
	//Creates a new array dynamically - destructor must get rid of or dispose of it!
	this->NumDaysComplete = new int[numDaySize];
	for (int i = 0; i < numDaySize; i++) this->NumDaysComplete[i] = 0;
	this->DegreePrgrm = SECURITY;
	
}

Student::Student(string ID, string fName, string lName, string emailAdd, int sAge, int days[], Degree degreeType) //Full constructor
{
	this->StudentID = ID;
	this->FirstName = fName;
	this->LastName = lName;
	this->EmailAddress = emailAdd;
	this->StudentAge = sAge;
	this->NumDaysComplete = new int[numDaySize];
	for (int i = 0; i < 3; i++) this->NumDaysComplete[i] = days[i];
	this->DegreePrgrm = degreeType;

}


//All getters
string Student::getStudentID()
{
	return StudentID;
}

string Student::getFirstName()
{
	return FirstName;
}

string Student::getLastName()
{
	return LastName;
}

string Student::getEmailAddress()
{
	return EmailAddress;
}

int Student::getStudentAge()
{
	return StudentAge;
}

int* Student::getNumDaysComplete()
{
	return NumDaysComplete;
}

Degree Student::getDegreePrgrm()
{
	return DegreePrgrm;
}

//All setters
void Student::setStudentID(string ID)
{
	StudentID = ID;
}

void Student::setFirstName(string fName)
{
	FirstName = fName;
}

void Student::setLastName(string lName)
{
	LastName = lName;
}

void Student::setEmailAddress(string emailAdd)
{
	EmailAddress = emailAdd;
}

void Student::setStudentAge(int sAge)
{
	StudentAge = sAge;
}

void Student::setNumDaysComplete(int days[])
{
	this->NumDaysComplete = new int[numDaySize];
	for (int i = 0; i < 3; i++)
		this->NumDaysComplete[i] = days[i];
}

void Student::setDegreePrgrm(Degree degreeType)
{
	this->DegreePrgrm = degreeType;
}

//Print the info of students except the degree type.
void Student::print()
{
	cout << left << setw(5) << StudentID; 
	cout << left << setw(12) << FirstName;
	cout << left << setw(12) << LastName;
	cout << left << setw(25) << EmailAddress;
	cout << left << setw(6) << StudentAge;
	cout << left << setw(3) << NumDaysComplete[0];
	cout << left << setw(3) << NumDaysComplete[1];
	cout << left << setw(4) << NumDaysComplete[2];
	cout << left << setw(9) << degreePrgrmTypeStrings[(int)getDegreePrgrm()];
	cout << endl;
}

Student::~Student()
{
	if (NumDaysComplete != nullptr) {
		delete[] NumDaysComplete;
		NumDaysComplete = nullptr;
	}
}
