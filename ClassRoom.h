#ifndef Classroom_H
#define Classroom_H

#include "Student.h"
#include <string>

using namespace std;

class Classroom
{
public:
	Classroom();
	Classroom(string);
	~Classroom();
	void setStudentArray(Student*, int);
	Student* getStudentArray();
	void sortGrades();
	void sortLastName();
	double avgGrade();
	void print();
	int getNStudents();
	string getName();

private:
	Student* StudentArray;
	string name = "Default";
	int nStudents;
};

#endif