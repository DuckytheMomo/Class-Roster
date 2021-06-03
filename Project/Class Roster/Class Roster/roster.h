#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include "student.h"
using namespace std;

const int numStudents = 5;


class Roster {
public:
	/*Requirement of E3: Define the following functions:
	a.  public void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram)
		that sets the instance variables from part D1 and updates the roster.
	b.  public void remove(string studentID)  that removes students from the roster by student ID. If the student ID does not exist, 
		the function prints an error message indicating that the student was not found.
	c. public void printAll() that prints a complete tab-separated list of student data in the provided format: A1 [tab] First Name: John [tab] Last Name: Smith [tab] Age: 20 
		[tab]daysInCourse: {35, 40, 55} Degree Program: Security. The printAll() function should loop through all the students in classRosterArray and call the print() function for each student.
	d.  public void printAverageDaysInCourse(string studentID)  that correctly prints a student’s average number of days in the three courses. The student is identified by the studentID parameter.
	e.  public void printInvalidEmails() that verifies student email addresses and displays all invalid email addresses to the user.
	Note: A valid email should include an at sign ('@') and period ('.') and should not include a space (' ').
	f.  public void printByDegreeProgram(DegreeProgram degreeProgram) that prints out student information for a degree program specified by an enumerated type.
	*/
	int lastIndex;
	int capacity;
	Student** classRosterArray;
	Roster();
	Roster(int capacity);
	Student* getStudent(int num);
	void add(string ID, string fName, string lName, string emailAdd, int sAge, int days1, int days2, int days3, Degree degreeType); /*Requirement E3.a
	public void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, 
	int daysInCourse3, DegreeProgram degreeprogram)  that sets the instance variables from part D1 and updates the roster. */
	void parseAdd(string datarow);
	void printAll();
	void remove(string ID); //Don't forget to come back to here. Switch bool to void if needed.
	void printAverageDaysInCourse(string ID);
	void printInvalidEmails(); //verifies student email addresses and displays all invalid email addresses to the user.
	void printByDegreeProgram(Degree degreeType); //prints out student information for a degree program specified by an enumerated type.
	
	~Roster();
};