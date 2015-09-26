/* 
 * File:   LnkList.cpp
 * Author: Haolan Ye (Benjamin)
 * Created on September 24, 2015, 10:54 AM
 */

#include "LnkList.h"
using namespace std;

//Destructor
LnkList::~LnkList() {
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
void LnkList::push(int n) {
    List *node;
    List *newNode;//node needed to push
    newNode=new List;
    //set the new node
    newNode->value=n;
    newNode->next=nullptr;
    //when head is null
    if(!head) head=newNode;
    else {
        node=head;
        //loop to the last node
        while(node->next)
            node=node->next;
        node->next=newNode;
    }
}

//delete a node that contains value n
void LnkList::dele(int n) {
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
        }
    }
}

//Output all node of Linked List
void LnkList::dspList() const {
    List *node;
    node=head;
    //output the Linked List
    while(node) {
        cout<<node->value<<endl;
        node=node->next;
    } 
}