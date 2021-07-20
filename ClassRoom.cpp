#include "Classroom.h"
#include <iostream>
#include <fstream>
#include <string>
#include "Student.cpp"

using namespace std;

Classroom::Classroom(string cname)
{
	name = cname;
	nStudents = 0;
}

Classroom::~Classroom()
{
	delete[] Students;
}

int Classroom::getNStudents()
{
	return nStudents;
}

void Classroom::setStudentArray(Student students[], int numStudent) 
{
	StudentArray = students[];
	nStudents = numStudent;
}

Student* Classroom::getStudentArray()
{
	return StudentArray;
}

int Classroom::input(ifstream inFile)
{
	int i = -1;
	string sFirstName, sLastName, ssn;
	double test[4];

	while (inFile >> sLastName >> sFirstName >> ssn >> test[0] >> test[1] >> test[2] >> test[3] || i < 23)
		Students[++i] = new Student(sFirstName, sLastName, ssn, test);

	return i + 1;
}

void Classroom::sortGrades()
{
	for (int i = 1, j; i < this->nStudents; i++)
	{
		j = i;
		while (j > 0 && Students[j - 1].getAvgScores() > Students[j].getAvgScores())
		{
			std::swap(Students[j], Students[j - 1]);
			j--;
		}
	}
}

void Classroom::sortLastName()
{
	for (int i = 1, j; i < this->nStudents; i++)
	{
		j = i;
		while (j > 0 && Students[j - 1].lastName > Students[j].lastName)
		{
			std::swap(Students[j], Students[j - 1]);
			j--;
		}
	}
}

double Classroom::avgGrade()
{
	int avg = 0;

	for (int i; i < nStudents; i++)
		avg += Students[i].getAvgScores();

	return avg / this->nStudents;
}

void Classroom::print()
{
	for (int i; i < nStudents; i++)
	{
		StudentArray[i].displayStudent();
	}
}