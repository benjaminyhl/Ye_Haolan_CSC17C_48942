/* 
 * File:   Record.cpp
 * Author: Haolan Ye (Benjamin)
 * Created on November 12, 2015, 7:00 AM
 */

#include <fstream>

#include "Record.h"

Record::Record(string s, int n) {
    init();
    pushRec(s,n);
}

//destructor
Record::~Record() {
    //output the updated record to the file
}

void Record::pushRec(string s, int n) {
    name.push_back(s);
    corrAns.push_back(n);
    quickSort(name,corrAns,0,name.size());
}

//Quick sort
void Record::quickSort(vector<string> nm, vector<int> cr, int beg, int end) {
    int p;
    if(beg<end) {
        p=pivot(nm,cr,beg,end);
        quickSort(nm,cr,beg,p-1);
        quickSort(nm,cr,p+1,end);
    }
}

int Record::pivot(vector<string> nm,vector<int> cr, int beg, int end) {
    int p=beg;
    int pivotValue=cr[beg];
    for(int i=beg+1;i<=end;i++) {
        if(cr[i]<=pivotValue) {
            p++;
            swap(cr[i],cr[p]);
            swap(nm[i],nm[p]);
        }
    }
    swap(cr[beg],cr[p]);
    swap(nm[beg],nm[p]);
    return p;
}

void Record::init() {
    fstream inFile("Record.txt",ios::in);
    string s;
    int size,n;
    if(!inFile.fail()) {
        inFile>>size;
        for(int i=0;i<size;i++) {
            inFile>>s;
            inFile>>n;
            name.push_back(s);
            corrAns.push_back(n);
        }
    }
    inFile.close();
}
