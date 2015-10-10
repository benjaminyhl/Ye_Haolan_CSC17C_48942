/* 
 * File:   Stack.h
 * Author: admin
 *
 * Created on October 7, 2015, 10:26 AM
 */

#ifndef STACK_H
#define	STACK_H

#include "LnkList.h"

template <class T>
class Stack: public LnkList<T> {
    private:
    public:
        Stack():LnkList<T>() {};
        Stack(int size):LnkList<T>(size) {};
};

template <class T>
class Queue: public LnkList<T> {
    public:
        Queue():LnkList<T>() {};
        Queue(int size):LnkList<T>(size) {};
        void append(T n);
};

template <class T>
void Queue<T>::append(T n) {
//    List *newNode;//node needed to push
//    newNode=new List;
//    //set the new node
//    newNode->value=n;
//    newNode->next=nullptr;
//    //when head is null
//    if(!head) head=newNode;
//    else {
//        newNode->next=head;
//        head=newNode;
//    }
//    size++;
}
#endif	/* STACK_H */

