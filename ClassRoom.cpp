#include "Classroom.h"
#include <iostream>
#include <fstream>
#include <string>
#include "Student.h"


using namespace std;


Classroom::Classroom()
{
	nStudents = 0;
}

Classroom::Classroom(string cname)
{
	name = cname;
	nStudents = 0;
}

Classroom::~Classroom()
{
	delete[] StudentArray;
	nStudents = 0;
	name = "";
}

int Classroom::getNStudents()
{
	return nStudents;
}

void Classroom::setStudentArray(Student* students, int numStudent) 
{
	StudentArray = students;
	nStudents = numStudent;
}

Student* Classroom::getStudentArray()
{
	return StudentArray;
}

string Classroom::getName()
{
	return name;
}

// int Classroom::input(ifstream inFile)
// {
// 	int i = -1;
// 	string sFirstName, sLastName, ssn;
// 	double test[4];

// 	while (inFile >> sLastName >> sFirstName >> ssn >> test[0] >> test[1] >> test[2] >> test[3] || i < 23)
// 		StudentArray[++i] = new Student(sFirstName, sLastName, ssn, test);

// 	return i + 1;
// }

void Classroom::sortGrades()
{
	for (int i = 1, j; i < this->nStudents; i++)
	{
		j = i;
		while (j > 0 && StudentArray[j - 1].getAvgScores() > StudentArray[j].getAvgScores())
		{
			std::swap(StudentArray[j], StudentArray[j - 1]);
			j--;
		}
	}
}

void Classroom::sortLastName()
{
	for (int i = 1, j; i < this->nStudents; i++)
	{
		j = i;
		while (j > 0 && StudentArray[j - 1].getLastName() > StudentArray[j].getLastName())
		{
			std::swap(StudentArray[j], StudentArray[j - 1]);
			j--;
		}
	}
}

double Classroom::avgGrade()
{
	int avg = 0;

	for (int i; i < nStudents; i++)
		avg += StudentArray[i].getAvgScores();

	return avg / this->nStudents;
}

void Classroom::print()
{
	for (int i; i < nStudents; i++)
	{
		StudentArray[i].displayStudent();
	}
}