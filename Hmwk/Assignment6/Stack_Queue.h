/* 
 * File:   Stack.h
 * Author: Haolan Ye (Benjamin)
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
        void pop();
};

template <class T>
void Queue<T>::pop() {
    if(LnkList<T>::head==nullptr) return;
    else {
        LnkList<T>::temp=LnkList<T>::head;
        LnkList<T>::head=LnkList<T>::head->next;
        delete LnkList<T>::temp;
        LnkList<T>::size--;
    }
}
#endif	/* STACK_H */

