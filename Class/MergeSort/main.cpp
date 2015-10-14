/* 
 * File:   main.cpp
 * Author: admin
 *
 * Created on October 10, 2015, 11:26 PM
 */

#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;

int *fill(int);
void print(int *,int,int);
int *merge(int *,int,int *,int);
int *mergeSort(int *,int,int);
int main(int argc, char** argv) {
    int size=20;
    int pl=5;
    srand(static_cast<unsigned int>(time(0)));
    int *a=fill(size);
    int *b=fill(2*size);
    cout<<"Array a: "<<endl;
    print(a,size,pl);
    cout<<"Array b: "<<endl;
    print(b,2*size,pl);
    cout<<endl<<"After Merge: "<<endl;
    
    int *m=merge(a,size,b,size*2);
    print(m,size+size*2,pl);
    delete []a;
    delete []b;
    delete []m;
    return 0;
}

int *fill(int n) {
    int *a=new int[n];
    for(int i=0;i<n;i++) {
        a[i]=i;
    }
    return a;
}

void print(int *a,int n,int pl) {
    for(int i=0;i<n;i++) {
        cout<<a[i]<<" ";
        if(i%pl==(pl-1)) cout<<endl;
    }
}

int *merge(int *a,int s1,int *b,int s2) {
    int *r=new int[s1+s2];
    int cntf=0,cnts=0;
    for(int i=0;i<s1+s2;i++) {
        if(cntf==s1) {
            r[i]=b[cnts++];
        } else if(cnts==s2) {
            r[i]=a[cntf++];
        } else if(a[cntf]<b[cnts]) { 
            r[i]=a[cntf++];
        } else {
            r[i]=b[cnts++];
        }
    }
    return r;
}

int *mergeSort(int *a,int beg,int end) {
    
}