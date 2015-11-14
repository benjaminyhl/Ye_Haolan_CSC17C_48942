/* 
 * File:   main.cpp
 * Author: Haolan Ye (Benjamin)
 * Created on October 10, 2015, 10:06 PM
 * Purpose: Project #1 --- Matrix Calculator
 */

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

#include "Matrix.h"
#include "LnkList.h" //Something wrong
#include "Record.h"
void menu();
void mainMenu();
int **getArray(int &,int &);
int **rndmArr(int,int);
void game();
void calculator();


int main(int argc, char** argv) {
    srand(static_cast<unsigned int>(time(0)));
    game();
//    char ch1;
//    do {
//        do {
//            mainMenu();
//            cout<<"You choose(1-3): ";
//            cin>>ch1;
//            if(ch1!='1'&&ch1!='2'&&ch1!='3') {
//                    cout<<"Invalid input"<<endl;
//            } 
//        } while(ch1!='1'&&ch1!='2'&&ch1!='3');
//        if(ch1=='1') {
//            calculator();
//        } else if(ch1=='2') {
//            game();
//        }
//        if(ch1!='3') {
//            cout<<"Click Enter to continue...";
//            cin.ignore();
//            cin.ignore();
//        }
//    } while(ch1!='3');
    

//    vector<Matrix> a;
//    LnkList<Matrix> a;
    //Add a matrix
//    int row,col;//row and column
//    string name="aaa";//name of the matrix
//    //create a linked list to store the matrix
//    int **array=getArray(row,col);//2-d array of matrix
//    Matrix m(row,col,array,name);
//    a.push_back(m);
//    a.append(m); 
//    cout<<endl<<endl<<"Here is your matrix:"<<endl;
//    m.display();
//    a[0].display();
    //Multiply by a number
//    cout<<"Multiply by: ";
//    int num;
//    cin>>num;
//    m.multiByNum(num);
    
    //Test for add 2 matrix
    
    //Trch1pose
//    m.trch1pose();
//    a[0].trch1pose();
    //Test for matrix multiplication
//    Matrix n(m);
//    m.multiByMat(n);
//    cout<<endl<<endl;
//    m.determinant();
//    a[0].determinant();
//    m.inverse();
    
//    //Test the Cofactor
//    for(int i=0;i<m.getRow();i++) {
//        for(int j=0;j<m.getCol();j++) {
//            cout<<"Cofactor("<<i<<","<<j<<"): "<<m.cofactor(i,j)<<endl;
//        }
//    }
//    m.inverse();
    
    return 0;
}

void game() {    
    cout<<"GAME TIME"<<endl;
    cout<<"You will have 5 matrix problems to solve"<<endl;
    for(int i=1;i<=5;i++) {
        cout<<endl<<"Problem #"<<i<<": "<<endl;
        int correct=0;
        int temp=rand()%5+1;
        cout<<"Temp: "<<temp<<endl;
        switch(temp) {
            case 1: {
                int ans;//answer from player
                //Find determinant
                int **array=rndmArr(2,2);
                Matrix m(2,2,array,"");
                m.display();
                cout<<"The determinant: ";
                cin>>ans;
                if(ans==m.getDet()) {
                    cout<<"You got it"<<endl;
                    correct++;
                } else cout<<"You are wrong"<<endl;
                break;
            }
            case 2: {
                int **ans=rndmArr(2,2);//answer from player
                //Find the matrix that multiplied by a matrix and a number
                int **array=rndmArr(2,2);
                cout<<"Here is the matrix: "<<endl;
                for(int i=0;i<2;i++) {
                    cout<<"[ ";
                    for(int j=0;j<2;j++) {
                        cout<<array[i][j]<<" ";
                    }
                    cout<<"]\n";
                }
                cout<<endl;
                int tem=rand()%10+1;
                cout<<"The matrix multiply by "<<tem<<": \n";
                for(int i=0;i<2;i++) {
                    cout<<"Row#"<<(i+1)<<": ";
                    for(int j=0;j<2;j++) {
                        cin>>ans[i][j];
                    }
                }
                bool right=true;
                for(int i=0;i<2;i++) {
                    for(int j=0;j<2;j++) {
                        if((tem*array[i][j])!=ans[i][j]) right=false;
                    }
                }
                for(int i=0;i<2;i++) {
                    delete []ans[i];
                }
                delete []ans;
                if(right) {
                    cout<<"You got it"<<endl;
                    correct++;
                }
                else cout<<"You are wrong"<<endl;
                break;
            }
            case 3: {
                int **ans=rndmArr(2,2);
                //Find the transpose of matrix 
                int **array=rndmArr(2,2);
                Matrix m(2,2,array,"");
                m.display();
                array=m.getArray();
                cout<<"The transpose of matrix"<<": \n";
                for(int i=0;i<2;i++) {
                    cout<<"Row#"<<(i+1)<<": ";
                    for(int j=0;j<2;j++) {
                        cin>>ans[i][j];
                    }
                }
                
                bool right=true;
                for(int i=0;i<2;i++) {
                    for(int j=0;j<2;j++) {
                        if(array[j][i]!=ans[i][j]) right=false;
                    }
                }   
                for(int i=0;i<2;i++) {
                    delete []ans[i];
                }
                delete []ans;
                if(right) {
                    cout<<"You got it"<<endl;
                    correct++;
                }
                else cout<<"You are wrong"<<endl;
                break;
            }
            case 4: {
                int ans;
                //Find a cofactor
                int **array=rndmArr(2,2);
                Matrix m(2,2,array,"");
                m.display();
                cout<<"The cofactor C(0,0): ";
                cin>>ans;
                if(ans==m.cofactor(0,0)) {
                    cout<<"You got it"<<endl;
                    correct++;
                } else cout<<"You are wrong"<<endl;
                break;
            }
            case 5: {
                //matrix * matrix
                bool right=true;
                int **ans=rndmArr(2,2);
                int **array1=rndmArr(2,2);
                int **array2=rndmArr(2,2);
                Matrix a(2,2,array1,"");
                Matrix b(2,2,array2,"");
                cout<<"Here are two matrix: \n";
                cout<<"1) ";
                a.display();
                cout<<"2) ";
                b.display();
                cout<<"Result of first matrix multiply by second matrix :\n";
                int **arr=a.timesByMat(b);
                for(int i=0;i<2;i++) {
                    cout<<"Row#"<<(i+1)<<": ";
                    for(int j=0;j<2;j++) {
                        cin>>ans[i][j];
                    }
                }
                for(int i=0;i<2;i++) {
                    for(int j=0;j<2;j++) {
                        if(arr[i][j]!=ans[i][j]) right=false;
                    }
                } 
                if(right) {
                    cout<<"You got it"<<endl;
                    correct++;
                } else cout<<"You are wrong"<<endl;
                for(int i=0;i<2;i++) {
                    delete []ans[i];
                    delete []arr[i];
                }
                delete []ans;
                delete []arr;
                break;
            }
            default:;
        }
    }
}

void calculator() {
    menu();
    cout<<"Cal"<<endl;
}

void mainMenu() {
    cout<<"***********     Main  Menu     ***********"<<endl;
    cout<<"1. MATRIX CALCULATOR"<<endl;
    cout<<"2. GAME"<<endl;
    cout<<"3. Exit"<<endl;
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

int **rndmArr(int row,int col) {
    int **array;
    array=new int*[row];
    //create columns
    for(int i=0;i<row;i++) {
        array[i]=new int[col];
        for(int j=0;j<col;j++) {
            array[i][j]=rand()%10;
        }
    }
    return array;
}