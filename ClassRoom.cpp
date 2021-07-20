#include "Classroom.h"
#include <iostream>
#include <fstream>
#include <string>
#include "Student.h"


using namespace std;

Classroom::Classroom(string cname)
{
	name = cname;
}

Classroom::~Classroom()
{
	delete []StudentArray;
	nStudents = 0;
	name = "";
}

int Classroom::getNStudents()
{
	return nStudents;
}

void Classroom::setStudentArray(string file) 
{
	ifstream inFile;
    string first, last, ssn;
    double test[4];
    int i = 0;
	inFile.open(file);

	while (inFile >> last >> first >> ssn >> test[0] >> test[1] >> test[2] >> test[3])
    {
        StudentArray[i] = Student(first, last, ssn, test);
        i++;
    }

	nStudents = i;
}

Student* Classroom::getStudentArray()
{
	return StudentArray;
}

string Classroom::getName()
{
	return name;
}

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