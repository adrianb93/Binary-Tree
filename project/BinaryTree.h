//
//  BinaryTree.h
//  Assignment 3
//
//  Created by Adrian Brown
//  Student c3145942
//  SENG1120 31 / 10 / 2011
//

#ifndef prjBinaryTree_BinaryTree_h
#define prjBinaryTree_BinaryTree_h

#include "Node.h"

namespace Assignment3
{
    template <typename value_type>
    class BinaryTree
    {
    public:
        // Member variables
        // none
        
        // Constructors
        BinaryTree();
        // Pre-conditions: 
        // Post-conditions: 
        
        ~BinaryTree();
        // Pre-conditions: None
        // Post-conditions: The binary tree is deleted
        
        //////
        // Member functions that mutate data
        void insertValue(value_type* new_data);
        // Pre-conditions: Data to insert
        // Post-conditions: Data inserted into appropriate position in Binary Tree
        
        void removeNode(Node<value_type>* remove_link);
        // Pre-conditions: Pointer to node to remove
        // Post-conditions: Node is removed
        
        void setRoot(Node<value_type>* new_link);
        // Pre-conditions: Pointer to the node to set as the root
        // Post-conditions: Node is set as the root
        
        
        //////
        // Members functions that query data
        
        Node<value_type>* binarySearch(value_type* search_data, Node<value_type>* pointer);
        // Pre-conditions: What to search for
        // Post-conditions: Returns the node it has found
        
        Node<value_type>* getRoot();
        // Pre-conditions: None
        // Post-conditions: Returns the root node
        
        int levelOfNode(Node<value_type>* parent_pointer, Node<value_type>* target_pointer);
        // Pre-conditions: Node to find the level of
        // Post-conditions: Return the level of the node
        
        int treeSize(Node<value_type>* parent_pointer);
        // Pre-conditions: Parent pointer
        // Post-conditions: Size of tree returned after recursivly running
        
        int totalComparisons(Node<value_type>* parent_pointer = NULL);
        // Pre-conditions: Parent pointer
        // Post-conditions: Number of branches returned
        
        string toString(Node<value_type>* parent_pointer, int level);
        // Pre-conditions: None
        // Post-conditions: String interpretation of the class is returned
        
        string toString();
        // Pre-conditions: None
        // Post-conditions: String interpretation of the class is returned
        
    private:
        // Member variables
        Node<value_type>* root;
    };
#include "BinaryTree.template"
}

#endif
