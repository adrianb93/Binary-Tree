//
//  Student.template
//  Assignment 3
//
//  Created by Adrian Brown
//  Student c3145942
//  SENG1120 31 / 10 / 2011
//

#include "Student.h"

namespace Assignment3
{
        Student::Student(string initial_name, float initial_grade)
        {
            name = new string(initial_name); // Set name
            grade = new float(initial_grade); // Set grade
        }
        
        Student::~Student()
        {
            delete name; // Delete from heap
            delete grade; // Delete from heap
            name = NULL; // Remove pointer
            grade = NULL; // Remove pointer
        }
        
        void Student::setName(string new_name)
        {
            name = new string(new_name); // Set name
        }
        
        void Student::setGrade(float new_grade)
        {
            grade = new float(new_grade); // Set grade
        }

        float Student::getGrade() const
        {
            return *grade; // Return grade
        }
        
        string Student::getName() const
        {
            return *name; // Return name
        }

        bool Student::operator <=(Student* left_student)
        {
            return left_student -> getName() <= getName(); // Return true or false
        }

        bool Student::operator ==(Student* left_student)
        {
            return left_student -> getName() == getName(); // Return true or false
        }

        bool Student::operator <(Student* left_student)
        {
            return left_student -> getName() < getName(); // Return true or false
        }
    
        string Student::toString()
        {
            stringstream ss; // Instanciate a stringstream
            
            ss << getName() + " ("; // Name
            ss << getGrade(); // Float
            ss << ") "; // Close parenthesis
            
            
            string output_this = ss.str(); // Converts stringstream to string
            return output_this; // Return string
        }
}
