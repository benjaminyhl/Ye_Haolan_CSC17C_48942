/* 
 * File:   main.cpp
 * Author: Haolan Ye (Benjamin)
 * Created on September 24, 2015, 10:54 AM
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries
#include "LnkList.h"

int main(int argc, char** argv) {
    //Call constructor
    LnkList<int> a;
    //append 4 numbers to the list
//    a.append(4);
    a.append(6);
    a.append(10);
    a.append(10);
//    a.prepend(100);
    //output the list after appending
    cout<<"After appending..."<<endl;
    cout<<"Linked List A: "<<endl;
    a.dspList();
    //output the size
    cout<<"Now, size of A is "<<a.getSize()<<endl;
    
    
    cout<<endl<<endl;
    //extract
    a.extr(10);
    //output the list after appending
    cout<<"After extract 10..."<<endl;
    cout<<"Linked List A: "<<endl;
    a.dspList();
    //output the size
    cout<<"Now, size of A is "<<a.getSize()<<endl;
//    //output the first value
//    cout<<"First Value of A: "<<a[0]<<endl;
//    
//    //prepend 2
//    a.prepend(2);
//    cout<<"After prepending 2..."<<endl;
//    cout<<"Linked List A: "<<endl;
//    a.dspList();
//    
//    //copy List A to B
//    LnkList<int> b(a);
//    //insert number 200 before number 4
//    a.insertBefore(200,4);
//    
//    cout<<"Here is B: "<<endl;
//    b.dspList();
//    b.append(100000);
//    cout<<endl<<"Here is B again: "<<endl;
//    b.dspList();
    return 0;
}

