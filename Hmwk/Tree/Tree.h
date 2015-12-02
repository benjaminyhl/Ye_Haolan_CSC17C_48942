/* 
 * File:   Tree.h
 * Author: admin
 *
 * Created on December 1, 2015, 9:16 AM
 */

#ifndef TREE_H
#define	TREE_H

#include <iostream>
using namespace std;


class Tree {
    private:
       struct Node {
            int value;
            struct Node *left;
            struct Node *right;
            struct Node *parent;
        };
        Node *root;
       int size;      // Actual Size of the array
       void insert(Node *&,Node *&);
    public:      
       Tree();   //Default constructor  
       ~Tree();  // Destructor declaration

       void insert(int);
       void del(int);//delete
       void balance();//balance the tree
       void print() const;
       int getSize() const {return size;} //return size
};

Tree::Tree() {
    root=NULL;
    size=0;
}

Tree::~Tree() {
    
}

void Tree::insert(int n) {
    Node *newNode=new Node;
    newNode->value=n;
    newNode->left=NULL;
    newNode->right=NULL;
    //1st way insert -- recursion
    insert(root,newNode);
    
    //2nd way insert -- not recursion
    
    size++;
}

void Tree::insert(Node *&node, Node*&newNode) {
    if(node==NULL)  node=newNode;
    else if(newNode->value <= node->value) insert(node->left,newNode);
    else insert(node->right,newNode);
}



void Tree::balance() {
    
}

void Tree::del(int n) {
    
}

void Tree::print() const {
    //get the first element
    
    Node *worker=root;
    while(worker->left!=NULL) {
        cout<<"Hel"<<endl;
        worker=worker->left;
    }
    cout<<worker->value<<" ";
//    if(worker->right!=NULL) 
}


#endif	/* TREE_H */

