#pragma once
#include <string>
#include <iostream>
#include "degree.h"

using namespace std;

/*Following requirement D1: Create the class Student in the files student.h and student.cpp, which includes each of the following variables:
student ID, first name, last name, email address, age, array of number of days to complete each course, degree program. */
class Student { //Class of a student

	private:
		//Private data members
		string StudentID;
		string FirstName;
		string LastName;
		string EmailAddress;
		int StudentAge;
		int* NumDaysComplete; //Array size will be 3.
		Degree DegreePrgrm; //the enumarated value: SECURITY, SOFTWARE or NETWORK



	public:
		//Public member functions
		const static int numDaySize = 3;
		Student(); //Empty Constructor
		Student(string ID, string fName, string lName, string emailAdd, int sAge, int days[], Degree degreeType);


		/*Following requirement D2: Create each of the following functions in the Student class.
		 an accessor (i.e., getter) for each instance variable from part D1, a mutator(i.e., setter) for each instance variable from part D1
		 All external accessand changes to any instance variables of the Student class must be done using accessorand mutator functions
		 Constructor using all of the input parameters provided in the table
		 print() to print specific student data */


		//Get (Accessor) functions for each instance field
		string getStudentID();
		string getFirstName();
		string getLastName();
		string getEmailAddress();
		int getStudentAge();
		int* getNumDaysComplete(); //days will be an array of 3
		Degree getDegreePrgrm();

		

		//Set (Mutator) Functions
		void setStudentID(string ID);
		void setFirstName(string fName);
		void setLastName(string lName);
		void setEmailAddress(string emailAdd);
		void setStudentAge(int sAge);
		void setNumDaysComplete(int days[]); //Number of days will be an array size of 3 because it is the number of days to complete 3 courses.
		void setDegreePrgrm(Degree degreeType);
		void print(); // print() to print specific student data

		//the destructor
		~Student();


};
