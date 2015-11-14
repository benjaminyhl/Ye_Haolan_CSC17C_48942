/* 
 * File:   Matrix.h
 * Author: Haolan Ye (Benjamin)
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
        int determinant(int**,int);
        int **adj();
        
    public:
        Matrix() {row=col=0;array=0;name="";}
        Matrix(const Matrix &);
        Matrix(int,int,int **,string);
        ~Matrix();
        void addMatrix(Matrix);         //done
        void subtract(Matrix);         //done
        void multiByNum(int);           //done
        void multiByMat(Matrix);//multiply by a matrix
        int **timesByMat(Matrix);//multiply by a matrix
        void transpose();               //done
        void determinant();
        int getDet();
        void inverse();
        void reduce_echelon();
        int getRow() const {return row;}
        int getCol() const {return col;}
        string getName() const {return name;}
        void setRow(int r) {row=r;}
        void setCol(int c) {col=c;}
        void setArray(int **a) {array=a;}
        void setName(string n) {name=n;}
        void display() const;
        int cofactor(int,int);
        int **getArray() const {return array;}
        //operator +, -, *
        void operator=(const Matrix &right);
        Matrix operator + (const Matrix &);
        Matrix operator - (const Matrix &);
        Matrix operator * (const Matrix &);
        Matrix operator * (int);
};

#endif	/* MATRIX_H */

