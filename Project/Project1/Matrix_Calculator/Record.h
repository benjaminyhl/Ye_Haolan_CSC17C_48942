/* 
 * File:   Record.h
 * Author: Haolan Ye (Benjamin)
 * Created on November 12, 2015, 7:00 AM
 */

#ifndef RECORD_H
#define	RECORD_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Record {
    private:
        vector<string> name;
        vector<int> corrAns;//count of correct answer
        void init();
        void quickSort(vector<string> &,vector<int> &,int,int);
        int pivot(vector<string> &,vector<int> &,int,int);
        template <class T>
        void swap(T &a,T &b) {
            T temp=a;
            a=b;
            b=temp;
        }
        
    public:
        Record() {init();}
        Record(string,int);
        ~Record();
        void pushRec(string,int);//push record
        void disRec();//display record
        
};

#endif	/* RECORD_H */

