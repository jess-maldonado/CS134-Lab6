#ifndef Student_H
#define Student_H

#include <string>

using namespace std;

class Student
{
    public:
        Student();
        Student(string, string, string, double[4]);
        ~Student();
        string getFirstName();
        void setFirstName(string);
        string getLastName();
        void setLastName(string);
        string getSSN();
        void setSSN(string);
        double getAvgScores();
        void setScores(double[4]);
        double* getScores();
        void displayStudent();
        static int numStudents;
        static int getNumStudents();

    private:
        string firstName = "";
        string lastName = "";
        string ssn = "";
        double scores[4] = {0};
        double calcAverage(double[]);
};

#endif