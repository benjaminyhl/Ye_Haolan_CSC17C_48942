/* 
 * File:   main.cpp
 * Author: admin
 *
 * Created on October 7, 2015, 10:25 AM
 */

#include <iostream>
using namespace std;

#include "DbList.h"
#include "Stack.h"
int main(int argc, char** argv) {
//    Stack<int> x;
//    x.append(10);
//    x.append(1000);
//    x.dspList();
//    cout<<endl;
//    Queue<int> y;
//    y.append(1000);
//    y.append(2);
//    y.dspList();
    DbList<int> a;
    a.append(10);
    a.append(100);
    a.prepend(421);
    a.pop();
    a.append(10000);
    a.dspList();
    cout<<"\nReversely display the List: \n";
    a.revDsp();
    return 0;
}

