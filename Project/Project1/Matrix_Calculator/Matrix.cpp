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
    int t;//temp int
    if(col!=row||col<1||row<1) {
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
        
        for(int i=0;i<row;i++) {
            t=0;
            for(int j=0;j<row;j++) {
                if(j==t) continue;
                temp[i-1][t]=array[i][j];
            }
            d+=pow(-1,i+2)*array[0][i]*determinant(temp,tRow);
        }
//        det = 0;
//      for (j1=0;j1<n;j1++) {
//         m = malloc((n-1)*sizeof(double *));
//         for (i=0;i<n-1;i++)
//            m[i] = malloc((n-1)*sizeof(double));
//         for (i=1;i<n;i++) {
//            j2 = 0;
//            for (j=0;j<n;j++) {
//               if (j == j1)
//                  continue;
//               m[i-1][j2] = a[i][j];
//               j2++;
//            }
//         }
//         det += pow(-1.0,1.0+j1+1.0) * a[0][j1] * Determinant(m,n-1);
//         for (i=0;i<n-1;i++)
//            free(m[i]);
//         free(m);
//      }
    }
    cout<<"Determinant: "<<d<<endl;
}

int Matrix::determinant(int **a,int n) {
    if(n==1) {
        return a[0][0];
    } else if(n==2) {
        return a[0][0]*a[1][1]-a[0][1]*a[1][0];
    } else {
//        int **temp;//2-d array of matrix
//        //create rows
//        temp=new int*[row];
//        //create columns
//        for(int i=0;i<row;i++) {
//            temp[i]=new int[col];
//        }
//        for(int i=0;i<row;i++) {
//            for(int j=0;j<col;j++) {
//                temp[i][j]=n*array[i][j];
//            }
//        }
    }
}

void Matrix::inverse() {
    
}