/* 
 * File:   main.cpp
 * Author: Haolan Ye (Benjamin)
 * Created on October 10, 2015, 10:06 PM
 * Purpose: Project #1 --- Matrix Calculator
 */

#include <iostream>
using namespace std;

#include "Matrix.h"

int main(int argc, char** argv) {
    cout<<"****WELCOME TO MATRIX CALCULATOR****"<<endl;
    cout<<endl<<endl<<"***********     Menu     ***********"<<endl<<endl;
    cout<<"1. Add a matrix"<<endl;
    cout<<"2. Determinant"<<endl;
    cout<<"3. Transpose"<<endl;
    cout<<"4. Inverse"<<endl;
    cout<<"5. Multiply by a number"<<endl;
    cout<<"6. Multiply by a matrix"<<endl;
    cout<<"7. Exit"<<endl;
    
    //Add a matrix
    int row,col;//row and column
    string name="aaa";//name of the matrix
    //create a linked list to store the matrix
    int **array;//2-d array of matrix
    cout<<"Row and Column of matrix: "<<endl;
    cin>>row>>col;
    //create rows
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
    
    Matrix m(row,col,array,name);
    m.display();
    return 0;
}

