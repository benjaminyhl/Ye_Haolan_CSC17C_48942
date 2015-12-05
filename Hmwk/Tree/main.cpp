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
    t.insert(50);
    t.insert(40);
    t.insert(30);
    t.insert(20);
    t.insert(10);
    t.insert(35);
    t.insert(60);
    t.insert(70);
    t.insert(45);
//    cout<<t.getSize()<<endl;
    t.inPnt();
//    t.postPnt();
//    t.prePnt();
    return 0;
}

