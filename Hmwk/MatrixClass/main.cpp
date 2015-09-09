/* 
 * File:   main.cpp
 * Author: Haolan Ye (Benjamin)
 * Created on September 6, 2015, 6:25 PM
 * Purpose: First Hmwk
 */

#include <iostream>
using namespace std;

#include "Matrix.h"

int main(int argc, char** argv) {
    Matrix<float> first(5);
    first.pntAray();
    cout<<endl<<endl;
    Matrix<int> second(11);
    second.pntAray();
    return 0;
}

