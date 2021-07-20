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
	void setStudentArray(string);
	Student* getStudentArray();
	void sortGrades();
	void sortLastName();
	double avgGrade();
	void print();
	int getNStudents();
	string getName();

private:
	Student* StudentArray = new Student[24]();
	string name = "Default";
	int nStudents = 0;
};

#endif