//
//  Node.h
//  Assignment 3
//
//  Created by Adrian Brown
//  Student c3145942
//  SENG1120 31 / 10 / 2011
//

#ifndef prjBinaryTree_Node_h
#define prjBinaryTree_Node_h

#include "Student.cpp"

namespace Assignment3
{
    template <typename value_type>
    class Node
    {
        public:
            // Member variables
            // none
            
            // Constructors
            Node(value_type* initial_data = value_type(), Node<value_type>* parent_node = NULL);
            // Pre-conditions: The data to input and node to set as parent
            // Post-conditions: New node is initialised
        
            ~Node();
            // Pre-conditions: None
            // Post-conditions: This node deleted
            
            //////
            // Member functions that mutate data
        
            void setData(value_type* new_data);
            // Pre-conditions: Data to set
            // Post-conditions: Data is set
        
            void setParent(Node<value_type>* new_link);
            // Pre-conditions: Pointer this nodes parent node
            // Post-conditions: Parent set
            
            void setLeft(Node<value_type>* new_link);
            // Pre-conditions: Pointer to node that is less than the value of this node
            // Post-conditions: Pointer to node set as left
       
            void setRight(Node<value_type>* new_link);
            // Pre-conditions: Pointer to node that is greater than the value of this node
            // Post-conditions: Pointer to node set as greater
        
        
            //////
            // Members functions that query data
        
            value_type* getData() const;
            // Pre-conditions: None
            // Post-conditions: Returns the data from this node
        
            Node<value_type>* getParent() const;
            // Pre-conditions: None
            // Post-conditions: Returns pointer to this nodes parent
        
            Node<value_type>* getLeft() const;
            // Pre-conditions: None
            // Post-conditions: Return left pointer
        
            Node<value_type>* getRight() const;
            // Pre-conditions: None
            // Post-conditions: Return right pointer
        
        
        private:
            // Member variables
            value_type *data; // The data to be stored in the node
            Node<value_type> *parent; // Link to parent node
            Node<value_type> *left; // Link to node which value is less than this node
            Node<value_type> *right; // Link to node which value is greater than this node
    };
    #include "Node.template"
}

#endif
