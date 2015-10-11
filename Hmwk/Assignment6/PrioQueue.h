/* 
 * File:   PrioQueue.h
 * Author: Haolan Ye (Benjamin)
 * Created on October 10, 2015, 1:34 PM
 */

#ifndef PRIOQUEUE_H
#define	PRIOQUEUE_H

#include "PrioList.h"
template<class T>
class PrioQueue:public PrioList<T> {
    private:
    public:
        PrioQueue():PrioList<T>() {};
        void pop();
};

template <class T>
void PrioQueue<T>::pop() {
    if(PrioList<T>::head==nullptr) return;
    else {
        PrioList<T>::temp=PrioList<T>::head;
        PrioList<T>::head=PrioList<T>::head->next;
        delete PrioList<T>::temp;
        PrioList<T>::size--;
    }
}
#endif	/* PRIOQUEUE_H */

