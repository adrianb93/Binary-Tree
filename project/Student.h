//
//  Student.h
//  Assignment 3
//
//  Created by Adrian Brown
//  Student c3145942
//  SENG1120 31 / 10 / 2011
//

#ifndef prjBinaryTree_Student_h
#define prjBinaryTree_Student_h

#include <cstdlib>
#include <sstream>
#include <iostream>
#include <iomanip>
using namespace std;

namespace Assignment3
{
    class Student
    {
    public:
        // Member variables
        // none
        
        // Constructors
        Student(string initial_name = " ", float initial_grade = 0.0);
        // Pre-conditions: Name and grade
        // Post-conditions: New student object is initialised
        
        ~Student();
        // Pre-conditions: None
        // Post-conditions: This object is deleted
        
        //////
        // Member functions that mutate data
        
        void setName(string new_name);
        // Pre-conditions: Name to set
        // Post-conditions: Name is set
        
        void setGrade(float new_grade);
        // Pre-conditions: Grade to set
        // Post-conditions: Grade is set
        
        bool operator <=(Student* left_student);
        // Pre-conditions: A student object left of the argument
        // Post-conditions: Return true or false whether left student is <= to this student
        
        bool operator ==(Student* left_student);
        // Pre-conditions: A student object left of the argument
        // Post-conditions: Return true or false whether left student is == to this student
        
        bool operator <(Student* left_student);
        // Pre-conditions: A student object left of the argument
        // Post-conditions: Return true or false whether left student is < this student
        
        //////
        // Members functions that query data
        
        float getGrade() const;
        // Pre-conditions: None
        // Post-conditions: Returns the data
        
        string getName() const;
        // Pre-conditions: None
        // Post-conditions: Returns the name of the student
        
        string toString();
        // Pre-conditions: None
        // Post-conditions: Returns the string interpretation of this object
                
    private:
        // Member variables
        string *name; // Students name
        float *grade; // The data stored in this class
    };
}

#endif
