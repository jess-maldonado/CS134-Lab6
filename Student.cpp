#include "Student.h"
#include <iomanip>
#include <iostream>
using namespace std;

int Student::numStudents = 0;
Student::Student()
{
    numStudents++;
}

Student::Student(string first, string last, string ssn, double scores[4])
{
    firstName = first;
    lastName = last;
    ssn = ssn;
    scores = scores;
    numStudents++;
}

Student::~Student()
{
    numStudents--;
}

string Student::getFirstName()
{
    return firstName;
}

void Student::setFirstName(string name)
{
    firstName = name;
}

string Student::getLastName()
{
    return lastName;
}

void Student::setLastName(string name)
{
    lastName = name;
}

string Student::getSSN()
{
    return ssn;
}

void Student::setSSN(string num)
{
    ssn = num;
}

double* Student::getScores()
{
    return Student::scores;
}

void Student::setScores(double scores[4])
{
    scores = scores;   
}

double Student::getAvgScores()
{
    double total = 0;
    for(int i = 0; i < 4; i++)
    {
        total += scores[i];
    }
    return total / 4;
}

int Student::getNumStudents()
{
    return numStudents;
}

void Student::displayStudents() 
{
    cout << fixed << setprecision(1);
    cout << setw(20) << left << lastName;
    cout << setw(20) << left << firstName;
    cout << setw(20) << left << ssn;
    
    for(int i = 0; i < 4; i++)
    {
        cout << setw(10) << right << scores[i];
    };
    cout << setw(10) << right << getAvgScores();
}
