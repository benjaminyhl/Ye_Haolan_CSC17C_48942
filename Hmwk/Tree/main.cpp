/* 
 * File:   main.cpp
 * Author: Haolan Ye (Benjamin)
 * Created on December 1, 2015, 9:13 AM
 */

#include <iostream>
using namespace std;

#include "Tree.h"

int main(int argc, char** argv) {
    Tree t;
    t.insert(10);
    t.insert(8);
    t.insert(12);
    t.insert(13);
    t.insert(9);
    t.insert(4);
    t.insert(1);
    t.insert(2);
    cout<<t.getSize()<<endl;
    t.inPnt();
    t.postPnt();
    t.prePnt();
    return 0;
}

