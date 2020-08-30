#pragma once
using std::string;
/*Requirement B: Create a C++ project in your integrated development environment (IDE) with the following files:
	•  degree.h
	•  student.h and student.cpp
	•  roster.h and roster.cpp
	•  main.cpp
*/
//Requirement C met: Define an enumerated data type DegreeProgram for the degree programs containing the data type values SECURITY, NETWORK, and SOFTWARE. 
//Note: This information should be included in the degree.h file.

enum Degree {SECURITY, NETWORK, SOFTWARE}; //Types of degrees
static const std::string degreePrgrmTypeStrings[] = {"SECURITY", "NETWORK", "SOFTWARE"}; 
