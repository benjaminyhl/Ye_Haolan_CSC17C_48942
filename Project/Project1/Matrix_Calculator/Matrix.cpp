/* 
 * File:   Matrix.cpp
 * Author: Haolan Ye (Benjamin)
 * Created on October 10, 2015, 10:06 PM
 * Purpose: Project #1 --- Matrix Calculator
 */

#include "Matrix.h"
#include <cmath>

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

//Destructor
Matrix::~Matrix() {
    
    //deallocate memory
    for(int i=0;i<row;i++) {
        delete []array[i];
    }
    delete []array;
    cout<<"Matrix destructor"<<endl;
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

void Matrix::multiByNum(int n) {
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
        for(int j=0;j<row;j++) {
            cout<<array[j][i]<<" ";
        }
        cout<<endl;
    }
}

void Matrix::multiByMat(Matrix o) {
    if(this->col!=o.getRow()) {
        cout<<"Invalid operation"<<endl;
        cout<<"Number of columns in the first matrix should be \n";
        cout<<"Equal to the number of rows in the second matrix"<<endl;
        return;
    } else {
        int **a;//2-d array of matrix
        //create rows
        a=new int*[this->row];
        //create columns
        for(int i=0;i<this->row;i++) {
            a[i]=new int[o.col];
        }
        for(int i=0;i<this->row;i++) {
            for(int j=0;j<o.col;j++) {
                a[i][j]=0;
                for(int k=0;k<this->col;k++) {
                    a[i][j]+=array[i][k]*o.array[k][j];//keep doing
                }
            }
        }
        Matrix r(row,col,a,"");
        r.display();
    }
}

void Matrix::determinant() {
    int d=0;
    if(col!=row||col<1||row<1) {
        cout << "ERROR:Cannot Get determinant.\n";
        return;
    } else if(col==1&&col==1) {
        d=array[0][0];
    } else if(col==2&&col==2) {
        d=array[0][0]*array[1][1]-array[0][1]*array[1][0];
    } else {
        int **temp;//2-d array of matrix
        //create rows
        int tRow=row-1;
        int tCol=col-1;
        temp=new int*[tRow];
        //create columns
        for(int i=0;i<tRow;i++) {
            temp[i]=new int[tCol];
            for(int j=0;j<tCol;j++) {
                temp[i][j]=0;
            }
        }
        int c=0,
            r=0;
        for(int i=0;i<row;i++) {
            c=r=0;
            for(int j=1;j<row;j++) {
                for(int k=0;k<col;k++) {
                    if(k==i) continue;
                    temp[c][r]=array[j][k];
                    r++;
                    if(r==(row-1)) {
                        c++;
                        r=0;
                    }
                }
            }
            
//            t=pow(-1,i)*array[0][i]*determinant(temp,tRow);
//            cout<<"This : "<<t<<endl;
//            d+=t;
            d+=pow(-1,i)*array[0][i]*determinant(temp,tRow);
            
            
            
        }
        for(int i=0;i<tRow;i++) {
                delete []temp[i];
            }
            delete []temp;
    }
    cout<<"Determinant: "<<d<<endl;
}

int Matrix::determinant(int **a,int n) {
    if(n==1) {
        return a[0][0];
    } else if(n==2) {
        return a[0][0]*a[1][1]-a[0][1]*a[1][0];
    } else {
        int **temp;//2-d array of matrix
        //create rows
        int tRow=n-1;
        int tCol=n-1;
        temp=new int*[tRow];
        //create columns
        for(int i=0;i<tRow;i++) {
            temp[i]=new int[tCol];
            for(int j=0;j<tCol;j++) {
                temp[i][j]=0;
            }
        }
        int det=0;
        int c=0,
            r=0;
        for(int i=0;i<n;i++) {
            c=r=0;
            for(int j=1;j<n;j++) {
                for(int k=0;k<n;k++) {
                    if(k==i) continue;
                    temp[c][r]=a[j][k];
                    r++;
                    if(r==(n-1)) {
                        c++;
                        r=0;
                    }
                }
            }
            det+=pow(-1,i)*a[0][i]*determinant(temp,tRow);   
        }
        for(int i=0;i<tRow;i++) {
                delete []temp[i];
            }
            delete []temp;
        return det;
    }
}

//Use adj(A)
void Matrix::inverse() {
    
}