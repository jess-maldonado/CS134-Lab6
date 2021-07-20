#include "Student.cpp"
#include <string>

using namespace std;

class Classroom
{
public:
	Classroom(string cname);
	~Classroom();
	void setStudents();
	Student[] getStudents();
	void sortGrades();
	void sortLastName();
	double avgGrade();
	void print();
	int getNStudents();

private:
	Student* StudentArray[24];
	const string name;
	int nStudents;
};