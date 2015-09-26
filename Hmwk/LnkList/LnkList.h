/* 
 * File:   LnkList.h
 * Author: Haolan Ye (Benjamin)
 * Created on September 24, 2015, 10:54 AM
 */

#ifndef LNKLIST_H
#define	LNKLIST_H

#include <iostream>

class LnkList {
    private:
        struct List {
            int value;
            struct List *next;
        };
        List *head;
    public:
        LnkList() {head=nullptr;}
        ~LnkList();
        void push(int);
        void dele(int);
        void dspList() const;
    
};

#endif	/* LNKLIST_H */

