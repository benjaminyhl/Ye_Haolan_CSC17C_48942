/* 
 * File:   main.cpp
 * Author: Haolan Ye (Benjamin)
 * Created on December 1, 2015, 9:13 AM
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#include "Tree.h"

int main(int argc, char** argv) {
    //set seed
    srand(static_cast<unsigned int>(time(0)));
    Tree t;
    t.insert(55);
    t.insert(40);
    t.insert(60);
    t.insert(30);
    t.insert(45);
    t.insert(70);
    t.insert(20);
    t.dele(45);
    t.dele(70);
    t.dele(20);
    t.dele(60);
//    t.insert(5);
//    t.insert(25);
//    t.insert(22);
    cout<<t.getSize()<<endl;
    t.inPnt();
    
//    t.postPnt();
//    t.prePnt();
    return 0;
}

