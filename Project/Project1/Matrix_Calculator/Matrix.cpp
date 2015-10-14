

#include "Matrix.h"

Matrix::Matrix(int r, int c, int **a, string nm) {
    row=r;
    col=c;
    name=nm;
    array=a;
}

void Matrix::display() const{
    //output the matrix
    for(int i=0;i<row;i++) {
        for(int j=0;j<col;j++) {
            cout<<array[i][j]<<" ";
        }
        cout<<endl;
    }
}

Matrix::~Matrix() {
    //deallocate memory
    for(int i=0;i<row;i++) {
        delete []array[i];
    }
    delete []array;
}
