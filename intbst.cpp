// intbst.cpp
// Implements class IntBST
// John Yang, 01/29/2026

#include "intbst.h"

#include <iostream>

using std::cout;

IntBST::IntBST() { 
	root = new Node(0);
}

// destructor deletes all nodes
IntBST::~IntBST() {
    clear(root);
}

// recursive helper for destructor
void IntBST::clear(Node *n) {
    if(n == nullptr) return;
    if(n -> left != nullptr){
    clear(n->left);
    }
    if(n -> right != nullptr){
    clear(n->right);
    }
    delete n; 
}

// insert value in tree; return false if duplicate
bool IntBST::insert(int value) {
    return insert(value, root);
}


// recursive helper for insert (assumes n is never 0)
bool IntBST::insert(int value, Node *n) {
    if(n == nullptr){
        return false;
    }
    if(n -> info == value){
        return false;
    }
    if(root -> info == 0){
        Node *p = new Node(value);
        root = p;
    }
    if( n -> right == nullptr && n -> info < value){
        Node *p = new Node(value);
        n -> right = p;
        return true;
    }
    if( n->left == nullptr && n -> info > value){
        Node *p = new Node(value);
        n -> left = p;
        return true;
    }
    if(n->info < value){
        return insert(value, n->right);    
    }else{
        return insert(value, n->left);
    }
}

// print tree data pre-order
void IntBST::printPreOrder() const {
    printPreOrder(root);
}

// recursive helper for printPreOrder()
void IntBST::printPreOrder(Node *n) const {
    if(n == nullptr) return;
    cout << n -> info;
    printPreOrder(n->left);
    printPreOrder(n->right);
}

// print tree data in-order, with helper
void IntBST::printInOrder() const {
    printInOrder(root);
}
void IntBST::printInOrder(Node *n) const {
    if(n == nullptr) return;
    printInOrder(n->left);
    cout<< n -> info;
    printInOrder(n->right);
}

// prints tree data post-order, with helper
void IntBST::printPostOrder() const {
    printPostOrder(root);
}

void IntBST::printPostOrder(Node *n) const {
    if (n == nullptr) return;
    printPostOrder(n->left);
    printPostOrder(n->right);
    cout << n -> info;
}

// return sum of values in tree
int IntBST::sum() const {
    return -1; // REPLACE THIS NON-SOLUTION
}

// recursive helper for sum
int IntBST::sum(Node *n) const {
    return -1; // REPLACE THIS NON-SOLUTION
}

// return count of values
int IntBST::count() const {
    return -1; // REPLACE THIS NON-SOLUTION
}

// recursive helper for count
int IntBST::count(Node *n) const {
    return -1; // REPLACE THIS NON-SOLUTION
}

// IMPLEMENT THIS FIRST: returns the node for a given value or NULL if none exists
// Parameters:
// int value: the value to be found
// Node* n: the node to start with (for a recursive call)
// Whenever you call this method from somewhere else, pass it
// the root node as "n"
IntBST::Node* IntBST::getNodeFor(int value, Node* n) const{
    return NULL; // REPLACE THIS NON-SOLUTION
}

// returns true if value is in the tree; false if not
bool IntBST::contains(int value) const {
    return false; // REPLACE THIS NON-SOLUTION
}

// returns the Node containing the predecessor of the given value
IntBST::Node* IntBST::getPredecessorNode(int value) const{
    return NULL; // REPLACE THIS NON-SOLUTION
}

// returns the predecessor value of the given value or 0 if there is none
int IntBST::getPredecessor(int value) const{
    return -1; // REPLACE THIS NON-SOLUTION
}

// returns the Node containing the successor of the given value
IntBST::Node* IntBST::getSuccessorNode(int value) const{
    return NULL; // REPLACE THIS NON-SOLUTION
}

// returns the successor value of the given value or 0 if there is none
int IntBST::getSuccessor(int value) const{
    return -1; // REPLACE THIS NON-SOLUTION
}

// deletes the Node containing the given value from the tree
// returns true if the node exist and was deleted or false if the node does not exist
bool IntBST::remove(int value){
    return false; // REPLACE THIS NON-SOLUTION
}
