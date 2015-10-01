/* 
 * File:   LnkList.h
 * Author: Haolan Ye (Benjamin)
 * Created on September 24, 2015, 10:54 AM
 */

#ifndef LNKLIST_H
#define	LNKLIST_H

#include <iostream>
using namespace std;

template <class T>
class LnkList {
    private:
        struct List {
            T value;
            struct List *next;
        };
        List *head;
        int size;
    public:
        LnkList() {head=nullptr;size=0;}
        LnkList(const LnkList &);
        ~LnkList();
        void extr(T);
        void prepend(T);
        void append(T);
        void insertAfter(T,T);
        void insertBefore(T,T);
        void dspList() const;
        T &operator[](const int &);
        int getSize() const {return size;}
        void subError();
    
};

//Constructor
template <class T>
LnkList<T>::LnkList(const LnkList &lnk) {
    if(lnk.head==nullptr) head=nullptr;
    List *node1=new List;
    List *node2=new List;
    node1=head;
    node2=lnk.head;
    while(node2!=nullptr) {
        
    }
}

//Destructor
template <class T>
LnkList<T>::~LnkList() {
    List *node;
    List *nextNode;
    if(head!=nullptr) {
    node=head;
    //loop to delete the pointer
        do {
            //get the next node
            nextNode=node->next;
            //delete the current node
            delete node;
            node=nextNode;//point to the next one
        }while(node!=nullptr);
    }
}

//push the node containing value n to the end
template <class T>
void LnkList<T>::append(T n) {
    List *node;
    List *newNode;//node needed to push
    newNode=new List;
    //set the new node
    newNode->value=n;
    newNode->next=nullptr;
    //when head is null
    if(head==nullptr) head=newNode;
    else {
        node=head;
        //loop to the last node
        while(node->next)
            node=node->next;
        node->next=newNode;
    }    
    size++;
}

//insert a number n before number a 
template <class T>
void LnkList<T>::insertBefore(T n,T a) {
    List *newNode;//node needed to push
    List *node;
    newNode=new List;
    //set the new node
    newNode->value=n;
    newNode->next=nullptr; 
    if(head==nullptr) return;
    else if(head->value==a) {
            newNode->next=head;
            head=newNode;
    } else {
        node=head;
        while(node->next!=nullptr&&node->next->value!=a) {
            node=node->next;
        } 
        if(node->next!=nullptr&&node->next->value==a) {
            newNode->next=node->next;
            node->next=newNode;
            size++;
        }
    }
}

//insert a number n after number a 
template <class T>
void LnkList<T>::insertAfter(T n,T a) {
    List *newNode;//node needed to push
    List *node;
    newNode=new List;
    //set the new node
    newNode->value=n;
    newNode->next=nullptr; 
    if(head==nullptr) return;
    node=head;
    while(node->next!=nullptr&&node->value!=a) {
        node=node->next;
    } 
    if(node->value==a) {
        newNode->next=node->next;
        node->next=newNode;
        size++;
    }
    
}


//push the node containing value n at the beginning
template <class T>
void LnkList<T>::prepend(T n) {
    List *newNode;//node needed to push
    newNode=new List;
    //set the new node
    newNode->value=n;
    newNode->next=nullptr;
    //when head is null
    if(!head) head=newNode;
    else {
        newNode->next=head;
        head=newNode;
    }
    size++;
}

//delete a node that contains value n
template <class T>
void LnkList<T>::extr(T n) {
    List *node;
    List *preNode;//previous node
    if(head==nullptr) return;
    if(head->value==n) {
        node=head->next;
        //set the first node to the next to head
        delete head;
        head=node;
    } else {
        node=head;
        //loop until node is null or the value n
        do {
            preNode=node;
            node=node->next;
        } while(node!=nullptr&&node->value!=n);
        //if node is not null
        if(node!=nullptr) {
            preNode->next=node->next;
            delete node;
            size--;
        }
    }
}

//Output all node of Linked List
template <class T>
void LnkList<T>::dspList() const {
    List *node;
    node=head;
    //output the Linked List
    while(node) {
        cout<<node->value<<endl;
        node=node->next;
    } 
}

template <class T>
T &LnkList<T>::operator[](const int &sub) {
   if (sub < 0||sub >=size)
      subError();
   List *node=head;
   for(int i=0;i<sub;i++) {
       node=node->next;
   }
   return node->value;
}

// subError function. Displays an error message and         
// terminates the program when a subscript is out of range. 
template <class T>
void LnkList<T>::subError() {
   cout << "ERROR: Subscript out of range.\n";
   exit(EXIT_FAILURE);
}

#endif	/* LNKLIST_H */

