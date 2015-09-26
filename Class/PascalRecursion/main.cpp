/* 
 * File:   main.cpp
 * Author: admin
 *
 * Created on September 23, 2015, 8:27 PM
 */

#include <iostream>
using namespace std;

//Global Constants


int coeff(int,int,int &);

int main(int argc, char** argv) {
    //declare variables
    int nRows=4;
    int nCalls=0;
    for(int row=1;row<=nRows;row++) {
        for(int col=1;col<=row;col++) {
            cout<<coeff(row,col,nCalls)<<" ";
        }
        cout<<endl;
    }
    cout<<"Number of Call: "<<nCalls<<endl;
    return 0;
}

int coeff(int r,int c,int &n) {
    if(r<1||c<1) return 0;
    if(c==1||r==c) return 1;
    int n1=0,n2=0;
    int x=coeff(r-1,c-1,n1)+coeff(r-1,c,n2);
    n=n1+n2+2;
    return x;
}