/* 
 * File:   main.cpp
 * Author: admin
 *
 * Created on October 7, 2015, 7:50 PM
 */

#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

double rtan(double);
int *fill(int);
void prntAry(int *,int,int);
int rmax(int *,int,int);

int main(int argc, char** argv) {
//    for(float rad=-1;rad<=1;rad+=0.1) {
//        cout<<"Percentage error in recursion tangent = "<<(tan(rad)-rtan(rad))/tan(rad)*100<<endl;
//    }
    srand(static_cast<unsigned int>(time(0)));
    int size=100;
    int perline=10;
    int *a=fill(size);
    prntAry(a,100,perline);
    cout<<"The max number is "<<rmax(a,0,size)<<endl;
    delete []a;
    
    return 0;
}

double rtan(double x) {
    double tol=1e-10;
    if(abs(x)<tol) return x;
    double a=rtan(x/2);
    return 2*a/(1-a*a);
}

int *fill(int n) {
    int *a=new int[n];
    for(int i=0;i<n;i++) {
        a[i]=rand()%90+10;
    }
    return a;
}

void prntAry(int *a,int n,int pl) {
    cout<<endl;
    for(int i=0;i<n;i++) {
        cout<<a[i]<<" ";
        if(i%pl==(pl-1)) cout<<endl;
    }
}

int rmax(int *a,int beg,int end) {
    if(end-beg<=1) return a[beg];
    int half=(end+beg)/2;
    int m1=rmax(a,beg,half);
    int m2=rmax(a,half,end);
    return (m1<m2?m2:m1);
}