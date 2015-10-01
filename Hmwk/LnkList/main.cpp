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
    LnkList<int> a;
    LnkList<int> b(a);
    b.append(4);
    b.dspList();
//    a.append(4);
//    a.append(6);
//    a.append(10);
//    a.prepend(100);
//    cout<<"At first: "<<endl;
//    a.dspList();
//    cout<<"Size is "<<a.getSize()<<endl;
//    cout<<endl<<endl;
//    a.extr(10);
//    a.dspList();
//    cout<<"Value: "<<a[0]<<endl;
//    cout<<"Size is "<<a.getSize()<<endl;
//    a.prepend(2);
//    a.extr(10);
//    a.insertBefore(200,4);
    //LnkList b(a);
    //cout<<"Here is B: "<<endl;
    //b.dspList();
    
    return 0;
}

