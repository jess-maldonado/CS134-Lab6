#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include "Student.h"
#include "Classroom.h"

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
	int i, j, largest;
	for (i = 0; i < nStudents; i++)
	{
		largest = i;
		for(j = i+1; j < nStudents; j++) 
		{
			if(StudentArray[j].getAvgScores() > StudentArray[largest].getAvgScores())
			{
				largest = j;
			}
		}
		swap(StudentArray[i], StudentArray[largest]);
	}
	
}

void Classroom::sortLastName()
{
	int i, j, smallest;
	for (i = 0; i < nStudents; i++)
	{
		smallest = i;
		for(j = i+1; j < nStudents; j++) 
		{
			if(StudentArray[j].getLastName() < StudentArray[smallest].getLastName() == 1)
			{
				smallest = j;
			}
		}
		swap(StudentArray[i], StudentArray[smallest]);
	}
}

double Classroom::avgGrade()
{
	double avg = 0;
	for (int i = 0; i < nStudents; i++)
		avg += StudentArray[i].getAvgScores();

	return avg / nStudents;
}

void Classroom::print()
{
	for (int i; i < nStudents; i++)
	{
		StudentArray[i].displayStudent();
	}
}