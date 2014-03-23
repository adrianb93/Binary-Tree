//
//  Demo.cpp
//  Assignment 3
//
//  Created by Adrian Brown
//  Student c3145942
//  SENG1120 31 / 10 / 2011
//

#include "BinaryTree.h"
using Assignment3::BinaryTree;
using Assignment3::Node;
using Assignment3::Student;

void purgeStudents(BinaryTree<Student>* tree, Node<Student>* parent_pointer = NULL, int min_range = 0, int max_range = 100);
// Pre-condition: Binary tree, Parent pointer, minimum mark and maximum mark range to delete
// Post-condition: All students from the tree under the parent node are removed if the were in range of the marks

int rangeCount(int min_range, int max_range, Node<Student>* parent_pointer);
// Pre-condition: Minimum mark and maximum mark range to tally
// Post-condition: All students under the parent node are tallied if the were in range of the marks

double totalGradesCount(Node<Student>* parent_pointer);
// Pre-condition: Parent node
// Post-condition: All students under the parent node are tallied if the were in range of the marks

int main()
{
    cout << endl << "-----------------------------------------------------------------------------------------------" << endl
                 << "                           THIS IS THE BEGINING OF THE PROGRAM" << endl
                 << "-----------------------------------------------------------------------------------------------" << endl; // Divider
    
    ///////////////////////////////////////////
    // Q1)
    // ASK FOR SEED
    int seed;
    cout << "Enter a seed for random shuffle and grades: ";
    cin >> seed; // Input seed value
    srand(seed); // Random number based on seed inputed
    
    ///////////////////////////////////////////
    // Q2)
    // Make tree
    BinaryTree<Student>* binary_tree = new BinaryTree<Student>;
    
    ///////////////////////////////////////////
    // Q3)
    // Add names and score (0-100)
    Student* student_list[] = 
    {
        new Student("Adam", rand() %101),new Student("Adrian", rand() %101),
        new Student("Alexander", rand() %101),new Student("Andrew", rand() %101),
        new Student("Ashley", rand() %101),new Student("Benjammin", rand() %101),
        new Student("Bradley", rand() %101),new Student("Brobie", rand() %101),
        new Student("Callan", rand() %101),new Student("Callum", rand() %101),
        
        new Student("Cameron", rand() %101),new Student("Chris", rand() %101),
        new Student("Damian", rand() %101),new Student("David", rand() %101),
        new Student("Dillon", rand() %101),new Student("Dylan", rand() %101),
        new Student("Ethan", rand() %101),new Student("Frederick", rand() %101),
        new Student("Hong", rand() %101),new Student("Hugh", rand() %101),
        
        new Student("Jackson", rand() %101),new Student("Jacob", rand() %101),
        new Student("James", rand() %101),new Student("Jared", rand() %101),
        new Student("Jodi", rand() %101),new Student("Jonathan", rand() %101),
        new Student("Joshua", rand() %101),new Student("Julius", rand() %101),
        new Student("Kelly", rand() %101),new Student("Kenias", rand() %101),
        
        new Student("KiSoon", rand() %101),new Student("Lance", rand() %101),
        new Student("Liam", rand() %101),new Student("Madison", rand() %101),
        new Student("Magdalena", rand() %101),new Student("Marcus", rand() %101),
        new Student("Mark", rand() %101),new Student("Melanie", rand() %101),
        new Student("Min", rand() %101),new Student("Mitchell", rand() %101),
        
        new Student("Nicholas", rand() %101),new Student("Ryan", rand() %101),
        new Student("Sang", rand() %101),new Student("Shane", rand() %101),
        new Student("Simon", rand() %101),new Student("Thomas", rand() %101),
        new Student("Timothy", rand() %101),new Student("Trent", rand() %101),
        new Student("Troy", rand() %101),new Student("Zaanif", rand() %101)
    };
    
    int array_size = sizeof student_list / sizeof(student_list[0]); // Calculates the size of the array
    
    for (int i = 0; i < array_size; i++) // Shuffle the student list
    {
        int chosen_student = rand() % array_size; // Choose any of the students in the array
        Student* temp = student_list[chosen_student]; // Back up that chosen student (Swap step 1)
        student_list[chosen_student] = student_list[i]; // Chosen student now is first student (Swap step 2)
        student_list[i] = temp; // First student now is chosen student (Swap step 3)
    }

    for (int i = 0; i < array_size; i++) // Insert all students in the array
    {
        binary_tree -> insertValue(student_list[i]); // Insert to tree
    }
    
    ///////////////////////////////////////////
    // Q4)
    // Print all students and grades
    cout << endl << binary_tree -> toString() << endl; // Print tree
    
    ///////////////////////////////////////////
    // Q5)
    // Print count of >=85
    cout << rangeCount(85, 100, binary_tree -> getRoot()) << " students had a mark greater or equal to 85." << endl; // Print range count
    
    ///////////////////////////////////////////
    // Q6)
    // Print average grade
    double average = totalGradesCount(binary_tree -> getRoot()) / binary_tree -> treeSize(binary_tree -> getRoot()); // Store average
    cout << "The average student mark is " << fixed << setprecision(2) << average << endl; // Print average
    
    ///////////////////////////////////////////
    // Q7)
    // Amount of comparisons made / students (average comparisons)
    double comparisions = binary_tree -> totalComparisons(binary_tree -> getRoot()); // Count of comparisons
    int total_students = binary_tree -> treeSize(binary_tree -> getRoot()); // Total students (Used for questions 7, 8 and 9)
    
    cout << "The average amount of comparisons for all students is "<< fixed << setprecision(2) 
         << comparisions / total_students << endl; // Print comparison average
    
    ///////////////////////////////////////////
    // Q8) 
    // Delete students who got < 50, print all their names and show average grade
    cout << endl << "Purging students who had a mark < 50" << endl;
    purgeStudents(binary_tree, binary_tree -> getRoot(), 0, 49); // Purge students from provided tree who got < 50
    cout << binary_tree -> toString() << endl; // Print tree
    average = totalGradesCount(binary_tree -> getRoot()) / binary_tree -> treeSize(binary_tree -> getRoot()); // Store average
    cout << "The average student mark is " << fixed << setprecision(2) << average << endl; // Print average matk
    
    ///////////////////////////////////////////
    // Q9)
    // Amount of comparisons made / students (average comparisons)
    comparisions = binary_tree -> totalComparisons(binary_tree -> getRoot()); // Count of comparisons
    total_students = binary_tree -> treeSize(binary_tree -> getRoot()); // Total students
    cout << "The average amount of comparisons for all students is "<< fixed << setprecision(2) 
    << comparisions / total_students << endl << endl; // Print comparison average
    
    ///////////////////////////////////////////
    // Clean up)
    // Memory management
    delete binary_tree; // Delete all data within the tree
    binary_tree = NULL; // Remove link
    
    array_size = sizeof student_list / sizeof(student_list[0]); // Gets size of the array
    for (int i = 0; i < array_size; i++)
    {
        // All nodes and student data in the array have already been deleted
        student_list[i] = NULL; // Remove link
    }
    
    return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////
// Side note)
// THESE FUNCTIONS INCLUDED HERE TO MAINTAIN A GENERIC FORMAT IN BINARYTREE, AND NODE TEMPLATES
void purgeStudents(BinaryTree<Student>* tree, Node<Student>* parent_pointer, int min_range, int max_range)
{
    
    // Left node
    if (parent_pointer -> getLeft() != NULL) // Left contains a child
    {
        purgeStudents(tree, parent_pointer -> getLeft(), min_range, max_range); // Query left
    }
    
    // Right node
    if (parent_pointer -> getRight() != NULL) // Right contains a child
    {
        purgeStudents(tree, parent_pointer -> getRight(), min_range, max_range); // Query right
    }
    
    // Current node
    if (parent_pointer -> getData() -> getGrade() >= min_range && parent_pointer -> getData() -> getGrade() <= max_range) // In range
    {
        tree -> removeNode(parent_pointer); // Remove current node, and shift childeren up to this node
    }
}

int rangeCount(int min_range, int max_range, Node<Student>* parent_pointer)
{
    int result = 0; // Count of matching results
    
    // Current
    if (parent_pointer != NULL) // Provided pointer is not NULL
    {
        if (parent_pointer -> getData() -> getGrade() >= min_range && parent_pointer -> getData() -> getGrade() <= max_range) // In range
        {
            result++; // Increment counter
        }
    }
    
    // Left
    if (parent_pointer -> getLeft() != NULL) // Left contains a child
    {
        result += rangeCount(min_range, max_range, parent_pointer -> getLeft()); // Query left
    }
    
    // Right
    if (parent_pointer -> getRight() != NULL) // Right contains a child
    {
        result += rangeCount(min_range, max_range, parent_pointer -> getRight()); // Query right
    }
    return result;
}

double totalGradesCount(Node<Student>* parent_pointer)
{
    double result = 0; // Count of all grades
    
    // Current
    if (parent_pointer != NULL) // Pointer provided is not NULL
    {
        result += parent_pointer -> getData() -> getGrade(); // Add grade to total result
    }
    
    // Left
    if (parent_pointer -> getLeft() != NULL) // Left contains a child
    {
        result += totalGradesCount(parent_pointer -> getLeft()); // Query left
    }
    
    // Right
    if (parent_pointer -> getRight() != NULL) // Right contains a child
    {
        result += totalGradesCount(parent_pointer -> getRight()); // Query right
    }
    return result;
}
