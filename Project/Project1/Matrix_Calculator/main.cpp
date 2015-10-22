/* 
 * File:   main.cpp
 * Author: Haolan Ye (Benjamin)
 * Created on October 10, 2015, 10:06 PM
 * Purpose: Project #1 --- Matrix Calculator
 */

#include <iostream>
using namespace std;

#include "Matrix.h"


void menu();
int **getArray(int &,int &);


int main(int argc, char** argv) {
    menu();
    
    //Add a matrix
    int row,col;//row and column
    string name="aaa";//name of the matrix
    //create a linked list to store the matrix
    int **array=getArray(row,col);//2-d array of matrix
    Matrix m(row,col,array,name);
    cout<<endl<<endl<<"Here is your matrix:"<<endl;
    m.display();
    
    //Multiply by a number
//    cout<<"Multiply by: ";
//    int num;
//    cin>>num;
//    m.multiByNum(num);
    
    //Test for add 2 matrix
    m.transpose();
    
    //Test for matrix multiplication
//    Matrix n(m);
//    m.multiByMat(n);
    cout<<endl<<endl;
    m.determinant();
    
    return 0;
}

void menu() {
    cout<<"****WELCOME TO MATRIX CALCULATOR****"<<endl;
    cout<<endl<<endl<<"***********     Menu     ***********"<<endl<<endl;
    cout<<"1. Add a matrix"<<endl;
    cout<<"2. Subtract a matrix"<<endl;
    cout<<"3. Determinant"<<endl;
    cout<<"4. Transpose"<<endl;
    cout<<"5. Inverse"<<endl;
    cout<<"6. Multiply by a number"<<endl;
    cout<<"7. Multiply by a matrix"<<endl;
    cout<<"8. Exit"<<endl;
}

int **getArray(int &row,int &col) {
    cout<<"Row and Column of matrix: "<<endl;
    cin>>row>>col;
    //create rows
    int **array;
    array=new int*[row];
    //create columns
    for(int i=0;i<row;i++) {
        array[i]=new int[col];
    }
    
    //Get the elements of matrix
    for(int i=0;i<row;i++) {
        for(int j=0;j<col;j++) {
            cin>>array[i][j];
        }
    }
    return array;
}