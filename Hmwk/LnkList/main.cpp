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
    LnkList a;
    a.push(4);
    a.push(6);
    a.push(10);
    a.dspList();
    cout<<endl<<endl;
    a.dele(4);
    a.dele(0);
    a.dspList();
    
    return 0;
}

