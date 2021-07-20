#include "Student.h"
#include "Classroom.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() 
{	
    Classroom classroom("CSC-134");
    
    classroom.setStudentArray("students.txt");

    classroom.sortGrades();
    cout << "\nStudents sorted by average grade: " << endl;
    cout << setw(15) << left << "Last Name";
    cout << setw(15) << left << "First Name";
    cout << setw(15) << left << "SSN";
    cout << setw(10) << right << "Score 1";
    cout << setw(10) << right << "Score 2";
    cout << setw(10) << right << "Score 3";
    cout << setw(10) << right << "Score 4";
    cout << setw(10) << right << "Average" << endl;
    cout << setw(100) << setfill('-') << "" << setfill(' ') << endl;
    classroom.print();

    classroom.sortLastName();
    cout << "\n\nStudents sorted by last name: " << endl;
    cout << setw(15) << left << "Last Name";
    cout << setw(15) << left << "First Name";
    cout << setw(15) << left << "SSN";
    cout << setw(10) << right << "Score 1";
    cout << setw(10) << right << "Score 2";
    cout << setw(10) << right << "Score 3";
    cout << setw(10) << right << "Score 4";
    cout << setw(10) << right << "Average" << endl;
    cout << setw(100) << setfill('-') << "" << setfill(' ') << endl;
    classroom.print();
    classroom.print();

    cout << "\nThe number of students is: " << classroom.getNStudents() << endl;
    cout << "The average grade is: " << classroom.avgGrade() << endl;

    return 0;
}