#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#define GREEN   "\033[32m"
#define BOLDGREEN   "\033[1m\033[32m"
#define RESET   "\033[0m"
#include "Roster.h"
using namespace std;

int main() {
	//Requirement F1: Print out to the screen, via your application, the course title, the programming language used, your WGU student ID, and your name.
	cout << GREEN << "Class Roster Project" << RESET << endl;
	cout << GREEN << "This project was written in C++ and created by" << BOLDGREEN << " DuckyMomo" << RESET << endl;
	cout << endl;

	const string allStudentData[numStudents] =
	{
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,rickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Ducky,Momo,DuckyMomo@momo.net,18,30,50,25,SOFTWARE", //Requirement A: Modify the “studentData Table” to include your personal information as the last item.
	};

	Roster* classRoster = new Roster(numStudents); //Making the repository. Requirement F2: Create an instance of the Roster class called classRoster.
	cout << "Parsing data and adding students" << endl;
	for (int i = 0; i < numStudents; i++){
		classRoster->parseAdd(allStudentData[i]); //Requirement F3: Add each student to classRoster.
	}

	/*
	F4 Requirement:
	Convert the following pseudo code to complete the rest of the  main() function:
	classRoster.printAll();
	classRoster.printInvalidEmails();
	loop through classRosterArray and for each element:
	classRoster.printAverageDaysInCourse(current_object's student id);
	classRoster.printByDegreeProgram(SOFTWARE);
	classRoster.remove("A3");
	classRoster.printAll();
	classRoster.remove("A3");
	expected: the above line should print a message saying such a student with this ID was not found.
	*/


	cout << "All done.\n";
	cout << endl;

	cout << BOLDGREEN << "ID   First Name  Last Name   Email                    Age   Days      Degree program\n" << RESET;
	classRoster->printAll(); 
	cout << endl;

	cout << BOLDGREEN << "Invalid email addresses:\n" << RESET;
	classRoster->printInvalidEmails(); 
	cout << endl;

	cout << BOLDGREEN << "Average Days Spent in Course:" <<  RESET;
	cout << endl; 
	for (int i = 0; i < 5; i++) {
		classRoster->printAverageDaysInCourse(classRoster->getStudent(i)->getStudentID());
	}

	cout << endl;

	cout << BOLDGREEN << "All the students within the program who have Software degrees:" << RESET << endl;
	cout << BOLDGREEN << "ID   First Name  Last Name   Email                    Age   Days      Degree program\n" << RESET;
	classRoster->printByDegreeProgram(Degree::SOFTWARE);
	cout << endl;

	cout << BOLDGREEN << "Removing A3:\n" << RESET; 
	classRoster->remove("A3");

	cout << BOLDGREEN << "Printing all student IDs WIHTOUT A3:\n" << RESET;
	cout << BOLDGREEN << "ID   First Name  Last Name   Email                    Age   Days      Degree program\n" << RESET;
	classRoster->printAll();
	cout << endl;

	cout << BOLDGREEN "Removing A3:\n" << RESET; 
	classRoster->remove("A3");
	cout << endl;

	system("pause"); //Needed only to hold console window up.
	return 0; //All done!
}
