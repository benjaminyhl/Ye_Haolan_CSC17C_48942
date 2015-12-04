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
        };
        Node *root;
       int size;      // Actual Size of the array
       void insert(Node *&,Node *&);
       void balance();//balance the tree
       void preOrder(Node *);
       void inOrder(Node *);
       void postOrder(Node *);
       void printNode(Node *);
       void clean(Node *);
    public:      
       Tree();   //Default constructor  
       ~Tree();  // Destructor declaration
       void insert(int);
       void del(int);//delete
       void prePnt(); //print out tree with pre-order
       void inPnt(); //print out tree with in-order
       void postPnt(); //print out tree with post-order
       int getSize() const {return size;} //return size
};

Tree::Tree() {
    root=NULL;
    size=0;
}

Tree::~Tree() {
    clean(root);
}

void Tree::clean(Node *node) {
    if(node!=NULL) {
//        cout<<"clean "<<node->value<<endl;
        clean(node->left);
        clean(node->right);
        delete node;
    }
}

void Tree::insert(int n) {
    Node *newNode=new Node;
    newNode->value=n;
    newNode->left=NULL;
    newNode->right=NULL;
    //1st way insert -- recursion
    insert(root,newNode);
    size++;
}

void Tree::insert(Node *&node, Node*&newNode) {
    if(node==NULL)  node=newNode;
    else if(newNode->value <= node->value) 
        insert(node->left,newNode);
    else insert(node->right,newNode);
}



void Tree::balance() {
    
}

void Tree::del(int n) {
    
}

void Tree::printNode(Node *node) {
    cout<<node->value<<" ";
}

void Tree::preOrder(Node *node) {
    if(node!=NULL) {
        printNode(node);
        preOrder(node->left);
        preOrder(node->right);
    }
} 

void Tree::inOrder(Node *node) {
    if(node!=NULL) {
        inOrder(node->left);
        printNode(node);
        inOrder(node->right);
    }
}

void Tree::postOrder(Node *node) {
    if(node!=NULL) {
        postOrder(node->left);
        postOrder(node->right);
        printNode(node);
    }
}

void Tree::prePnt() {
    cout<<"Print with pre-order:  ";
    preOrder(root); //pre-order output
    cout<<endl;
}

void Tree::inPnt() {
    cout<<"Print with in-order:   ";
    inOrder(root);  //in-order output
    cout<<endl;
}

void Tree::postPnt() {
    cout<<"Print with post-order: ";
    postOrder(root);//post-order output
    cout<<endl;
}

#endif	/* TREE_H */

