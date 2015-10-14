/* 
 * File:   Matrix.h
 * Author: admin
 *
 * Created on October 14, 2015, 3:22 PM
 */

#ifndef MATRIX_H
#define	MATRIX_H

#include <iostream>
#include <string>
using namespace std;


class Matrix {
    private:
        int row;
        int col;
        int **array;
        string name;
    public:
        Matrix();
        Matrix(int,int,int **,string);
        ~Matrix();
        void display() const;
};

#endif	/* MATRIX_H */

