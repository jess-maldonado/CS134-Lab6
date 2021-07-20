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
    
    classroom.print();

    return 0;
}