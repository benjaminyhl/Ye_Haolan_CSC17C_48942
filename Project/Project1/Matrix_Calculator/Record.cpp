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

void Record::pushRec(string s, int n) {
    
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
            name.push(s);
            corrAns.push(n);
        }
    }
    inFile.close();
}