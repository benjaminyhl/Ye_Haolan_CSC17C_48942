/* 
 * File:   Matrix.cpp
 * Author: Haolan Ye (Benjamin)
 * Created on October 10, 2015, 10:06 PM
 * Purpose: Project #1 --- Matrix Calculator
 */

#include "Matrix.h"

//Constructor
Matrix::Matrix(int r, int c, int **a, string nm) {
    row=r;
    col=c;
    name=nm;
    array=a;
}

//Copy constructor
Matrix::Matrix(const Matrix &o) {
    //create rows
    row=o.getRow();
    col=o.getCol();
    name=o.getName();
    array=new int*[row];
    //create columns
    for(int i=0;i<row;i++) {
        array[i]=new int[col];
    }
    for(int i=0;i<row;i++) {
        for(int j=0;j<col;j++) {
            array[i][j]=o.array[i][j];
        }
    } 
}

//Display the matrix
void Matrix::display() const{
    //output the matrix
    for(int i=0;i<row;i++) {
        for(int j=0;j<col;j++) {
            cout<<array[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl<<endl;
}

//Destructor
Matrix::~Matrix() {
    //deallocate memory
    for(int i=0;i<row;i++) {
        delete []array[i];
    }
    delete []array;
}


void Matrix::multiByNum(int n) {
//    int **a;//2-d array of matrix
//    //create rows
//    a=new int*[row];
//    //create columns
//    for(int i=0;i<row;i++) {
//        a[i]=new int[col];
//    }
//    for(int i=0;i<row;i++) {
//        for(int j=0;j<col;j++) {
//            a[i][j]=n*array[i][j];
//        }
//    }
//    Matrix r(row,col,a,"");
//    r.display();
    cout<<"The result of multiplying by "<<n<<":"<<endl;
    for(int i=0;i<row;i++) {
        for(int j=0;j<col;j++) {
            cout<<n*array[i][j]<<" ";
        }
        cout<<endl;
    }
}

//Matrix add a matrix
void Matrix::addMatrix(Matrix a) {
    cout<<"The result of two matrix addition:"<<endl;
    if(row!=a.getRow()||col!=a.getCol()) return;
    else {
        for(int i=0;i<row;i++) {
            for(int j=0;j<col;j++) {
                cout<<array[i][j]+a.array[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}

//Matrix minus a matrix
void Matrix::subtract(Matrix a) {
    cout<<"The result of two matrix subtraction:"<<endl;
    if(row!=a.getRow()||col!=a.getCol()) return;
    else {
        for(int i=0;i<row;i++) {
            for(int j=0;j<col;j++) {
                cout<<array[i][j]-a.array[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}

void Matrix::transpose() {
    cout<<"The transpose is "<<endl;
     for(int i=0;i<col;i++) {
            for(int j=row-1;j>=0;j--) {
                cout<<array[j][i]<<" ";
            }
            cout<<endl;
    }
}
