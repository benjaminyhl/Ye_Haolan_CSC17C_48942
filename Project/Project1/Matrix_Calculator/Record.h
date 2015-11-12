/* 
 * File:   Record.h
 * Author: Haolan Ye (Benjamin)
 * Created on November 12, 2015, 7:00 AM
 */

#ifndef RECORD_H
#define	RECORD_H

#include <iostream>
#include <string>
#include "myVector.h"
using namespace std;

#include "myVector.h"

class Record {
    private:
        MyVector<string> name;
        MyVector<int> corrAns;//count of correct answer
        void init();
        void quickSort();
    public:
        Record() {init();}
        Record(string,int);
        void pushRec(string,int);//push record
        
};

#endif	/* RECORD_H */

