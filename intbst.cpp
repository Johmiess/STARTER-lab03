// intbst.cpp
// Implements class IntBST
// John Yang, 01/29/2026

#include "intbst.h"

#include <iostream>

using std::cout;

IntBST::IntBST() { 
	root = nullptr;
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
    if(root == nullptr){
        Node *p = new Node(value);
        root = p;
        return true;
    }
    if(n == nullptr){
        return false;
    }
    if(n -> info == value){
        return false;
    }
    if( n -> right == nullptr && n -> info < value){
        Node *p = new Node(value);
        n -> right = p;
        n -> right -> parent = n;
        return true;
    }
    if( n->left == nullptr && n -> info > value){
        Node *p = new Node(value);
        n -> left = p;
        n -> left -> parent = n;
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
    cout << n -> info << " ";
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
    cout<< n -> info << " ";
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
    cout << n -> info << " ";
}

// return sum of values in tree
int IntBST::sum() const {
    return sum(root);
}

// recursive helper for sum
int IntBST::sum(Node *n) const {
    if(n == nullptr) return 0;
    return n -> info + sum(n -> left) + sum(n -> right);
    // return 0;

}

// return count of values
int IntBST::count() const {
    return count(root);
}

// recursive helper for count
int IntBST::count(Node *n) const {
    if(n == nullptr) return 0;
    return 1 + count(n -> left) + count(n -> right);
}

// IMPLEMENT THIS FIRST: returns the node for a given value or NULL if none exists
// Parameters:
// int value: the value to be found
// Node* n: the node to start with (for a recursive call)
// Whenever you call this method from somewhere else, pass it
// the root node as "n"
IntBST::Node* IntBST::getNodeFor(int value, Node* n) const{
    if(n == nullptr) return nullptr;
    if(n -> info < value){
        return getNodeFor(value,n->right);
    }
    if(n -> info > value){
        return getNodeFor(value,n->left);
    }
    return n;
}

// returns true if value is in the tree; false if not
bool IntBST::contains(int value) const {
    if(getNodeFor(value, root) != nullptr){
        return true;
    } else {
        return false;
    }
}

// returns the Node containing the predecessor of the given value
IntBST::Node* IntBST::getPredecessorNode(int value) const{
    // 2 ways, either up a couple parent nodes or the right most value in the left subgraph
    Node *p = getNodeFor(value, root);
    if(p == nullptr) return nullptr;
    if(p->left != nullptr){
        Node *target = p -> left;
        while(target->right != nullptr){
            target = target -> right;
        }
        return target;
    }
    Node *child = p;
    Node *parent = p -> parent;
    while(parent != nullptr && parent -> left == child){
        parent = parent -> parent;
        child = child -> parent;
    }
    return parent;
}

// returns the predecessor value of the given value or 0 if there is none
int IntBST::getPredecessor(int value) const{
    Node *p = getPredecessorNode(value);
    if (p != nullptr)return p -> info;
    return 0;
}

// returns the Node containing the successor of the given value
IntBST::Node* IntBST::getSuccessorNode(int value) const{
    Node *p = getNodeFor(value, root);
    if(p == nullptr) return nullptr;
    if(p -> right != nullptr){
        Node *curr = p -> right;
        while(curr -> left != nullptr){
            curr = curr -> left;
        }
        return curr;
    }
    else{
        Node *parent_n = p -> parent;
        Node *child_n = p;
        while(parent_n != nullptr && parent_n -> left != child_n){
            parent_n = parent_n -> parent;
            child_n = child_n -> parent;

        }
        return parent_n;
    }
}

// returns the successor value of the given value or 0 if there is none
int IntBST::getSuccessor(int value) const{
    Node *p = getSuccessorNode(value);
    if(p != nullptr) return p -> info;
    return 0;
}

// deletes the Node containing the given value from the tree
// returns true if the node exist and was deleted or false if the node does not exist
bool IntBST::remove(int value){
     

    Node *p = getNodeFor(value, root);
    if(p == nullptr) return false;
    if(p -> left && p -> right){
        Node *predecessor = getPredecessorNode(value);
        p -> info = predecessor -> info;
        p = predecessor;
    }
    // leaft node simple case
    if(p -> left == nullptr && p -> right == nullptr){
        if(p -> parent != nullptr){
            Node *parent_n = p -> parent;
            if(parent_n -> left == p){
                parent_n -> left = nullptr;
            }
            else {
                parent_n -> right = nullptr;
            }
            delete p;
            return true;
        } else {
            root = nullptr;
            delete p;
            return true;
        }

    }

    if((p -> left == nullptr && p -> right) || (p -> right == nullptr && p->left)){
        Node *child_node = nullptr; 
        if(p -> left != nullptr){
            child_node = p -> left;
        } else {
            child_node = p -> right;
        }
        if(p -> parent != nullptr){
            Node *parent_n = p -> parent;
            if(parent_n -> left == p){
                parent_n -> left = child_node;
                child_node -> parent = parent_n;
            } else {
                parent_n -> right = child_node;
                child_node -> parent = parent_n;
            }
            delete p;
            return true;
        } else {
            root = child_node;
            child_node -> parent = nullptr;
            delete p;
            return true;
        }
    }
    return false;
}
