#include "Student.cpp"

class Classroom
{
public:
	Classroom(std::string cname, std::ifstream inFile);
	~Classroom();
	int input(std::ifstream inFile);
	void sort();
	double avgGrade();
	void print();
	int getNStudents();

private:
	Student* Students{ new Student[24] };
	const string name;
	int nStudents;
};