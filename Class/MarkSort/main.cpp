/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on September 16, 2015, 9:01 AM
 * Purpose:  Example Linear Search/Mark Sort
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//User Libraries

//Global Constants

//Function Prototypes
void filAray(int [],int);
void prntAry(int [],int,int);
int linSrch(int[],int,int);
void markSrt(int [],int,int&,int&,int&,int&);
void bubSrt(int [],int,int&,int&,int&,int&);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    //Declare variables
    const int SIZE=400;
    int array[SIZE];
    //Fill the array
    filAray(array,SIZE);
    //Print the array
    //prntAry(array,SIZE,10);
    //Sort the Array
    int eq,//Total number of equalities
        lop,//Total number of logical operations
        lsa,//Total number of add/sub operations
        add;//Total number of addressing operations
    bubSrt(array,SIZE,eq,lop,lsa,add);
    //Print again
    //prntAry(array,SIZE,10);
    //Find something
    cout<<"Size of the array to sort = "<<SIZE<<endl;
    cout<<"Total number of equalities = "<<eq<<endl;
    cout<<"Total number of logical operations = "<<lop<<endl;
    cout<<"Total number of add/sub operations = "<<lsa<<endl;
    cout<<"Total number of addressing operations = "<<add<<endl;
    cout<<"Total number of operations = "<<eq+lop+lsa+add<<endl;
    //Exit Stage Right!
    return 0;
}

int linSrch(int a[],int n,int val){
    for(int i=0;i<n;i++){
        if(a[i]==val)return i;
    }
    return -1;
}

void markSrt(int a[],int n,int &eq, int &lop, int &lsa, int &add){
    //Set the counters = 0
    eq=lop=lsa=add=0;
    eq++;
    for(int pos=0;pos<n-1;pos++){
        lop++;lsa+=2;eq++;
        for(int lst=pos+1;lst<n;lst++){
            lop+=2;lsa+=2;add+=2;
            if(a[pos]>a[lst]){
                int temp=a[pos];
                a[pos]=a[lst];
                a[lst]=temp;
                add+=4;eq+=3;
            }
        }
    }
}

void bubSrt(int a[],int n,int &eq, int &lop, int &lsa, int &add) {
    //Set the counters = 0
    eq=lop=lsa=add=0;
    eq++;
    bool swap;
    do {
        eq++;
        swap=false;
        lsa++;eq++;
        for(int i=0;i<n-1;i++) {
        lop+=2;lsa+=3;add+=2;    
            if(a[i]>a[i+1]) {
                int temp=a[i];
                a[i]=a[i+1];
                a[i+1]=temp;
                swap=true;
                add+=4;
                eq+=4;
            }
        }
        
    }while(swap);
}

void prntAry(int a[],int n,int perLine){
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
        if(i%perLine==perLine-1)cout<<endl;
    }
    cout<<endl;
}

void filAray(int a[],int n){
    for(int i=0;i<n;i++){
        a[i]=rand();
    }
}