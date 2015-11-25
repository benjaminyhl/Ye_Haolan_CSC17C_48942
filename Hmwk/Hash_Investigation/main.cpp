/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Modified by: Haolan Ye (Benjamin)
 * Created on January 10, 2014, 6:49 PM
 * Last Modified: November 20th,2015
 * Testing something like a hash-cash algorithm
 */

//System Libraries
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <ctime>
#include <sstream>
#include <cmath>
#include <set>
#include <map>
#include <vector>
using namespace std;

//user libraries
#include "GeneralHashFunctions.h"

//Function Prototypes
//void prntRes(unsigned int [],int);

//Execution Begins here
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Create a message
    string msg="What a difference a day makes!";
    cout<<"The base message = "<<msg<<endl;
    
    vector<unsigned int> vec; //vector to store the result of hash
    set<unsigned int> s; //set to store the result of hash
    map<int,unsigned int> range;    //get the frequency of different range
    unsigned int endLoop;//number of loops
    unsigned int fstColl=0;//first collision
    unsigned int ttColl;//total collision
    bool hasColl=false;//has collision
    unsigned int res;//result of hash function  
    
//    char hash;//which hash
    //Prompt for number of loop
    do {
        cout<<"Input the number of loop(non-negative): ";
        cin>>endLoop;
        if(endLoop<1) cout<<"Invalid input"<<endl;
    } while(endLoop<1);
    //choose hash function
//    do {
//        cout<<endl<<"******Hash Function Menu******"<<endl;
//        cout<<"1. RSHash"<<endl;
//        cout<<"2. JSHash"<<endl;
//        cout<<"3. PJWHash"<<endl;
//        cout<<"4. ELFHash"<<endl;
//        cout<<"5. BKDRHash"<<endl;
//        cout<<"6. SDBMHash"<<endl;
//        cout<<"7. DJBHash"<<endl;
//        cout<<"8. DEKHash"<<endl;
//        cout<<"9. BPHash"<<endl;
//        cout<<"Hash Function you would like to use(1-9): ";
//        cin>>hash;
//        if(hash<'1'||hash>'9') cout<<"Invalid input"<<endl;
//    } while(hash<'1'||hash>'9');
    
    //Record the start time
    int strTime=time(0);
    //initial the map
    for(int j=9;j>=0;j--) {
        range.insert(make_pair(j,0));
    }
    
    //Loop until you have reached the number of size
    for(int hash=9;hash<10;hash++) {
        map<unsigned int, unsigned int> test;
        fstColl=0;
        ttColl=0;
        hasColl=false;
        s.clear();
        vec.clear();
        for(int i=0;i<10;i++) {
            range[i]=0;
        }
        
        switch(hash) {
            case 1:cout<<"RSHash"<<endl; break;
            case 2:cout<<"JSHash"<<endl; break;
            case 3:cout<<"PJWHash"<<endl; break;
            case 4:cout<<"ELFHash"<<endl; break;
            case 5:cout<<"BKDRHash"<<endl; break;
            case 6:cout<<"SDBMHash"<<endl; break;
            case 7:cout<<"DJBHash"<<endl; break;
            case 8:cout<<"DEKHash"<<endl; break;
            case 9:cout<<"BPHash"<<endl; break;
            default:;
        }
        //Choose a random number
        unsigned int randNum=rand();
        cout<<"The initial random number = "<<randNum<<endl;
        
        for(unsigned int i=1;i<=endLoop;i++) {
            ostringstream convert;   // stream used for the conversion
            convert << randNum++;      // insert the textual representation of 'Number' in the characters in the stream
            string strRnd = convert.str();
            string newMsg=msg+strRnd;
            //use hash function
            switch(hash) {
                case 1:res=RSHash(newMsg); break;
                case 2:res=JSHash(newMsg); break;
                case 3:res=PJWHash(newMsg); break;
                case 4:res=ELFHash(newMsg); break;
                case 5:res=BKDRHash(newMsg); break;
                case 6:res=SDBMHash(newMsg); break;
                case 7:res=DJBHash(newMsg); break;
                case 8:res=DEKHash(newMsg); break;
                case 9:res=BPHash(newMsg); break;
                default:;
            }
            
            
            //insert the result of hash to set
            if(s.insert(res).second){
                test[res]=0;
            }
            vec.push_back(res);
            range[static_cast<int>(log10(res))]++;
            
            if((!hasColl)&&(s.size()!=vec.size())) {
                fstColl=i;
                hasColl=true;
                cout<<"Has 1111"<<endl;
            }         
//            //count depending on the digit of the result of hash function
//            switch((log10(res))) {
//                case 9:  range[9]++; break;
//                case 8:  range[8]++; break;
//                case 7:  range[7]++; break;
//                case 6:  range[6]++; break;
//                case 5:  range[5]++; break;
//                case 4:  range[4]++; break;
//                case 3:  range[3]++; break;
//                case 2:  range[2]++; break;
//                case 1:  range[1]++; break;
//                case 0:  range[0]++; break;
//                default:;
//            }
        }
        for(int i=0;i<vec.size();i++){
            test[vec[i]]++;
        }
        //print out result
//        prntRes(range,9);
            cout<<"Range      Frequency"<<endl;
        for(int j=9;j>=0;j--) {
            cout<<"10^"<<j<<"-10^"<<(j+1)<<": "<<range[j]<<endl;
        }  
        ttColl=endLoop-s.size();
        cout<<"Total collision: "<<ttColl<<endl;
        cout<<"First collision at i = "<<fstColl<<endl;

        //Take the time it took
        int endTime=time(0);
        //Output the result
        cout<<"Size of set = "<<s.size()<<endl;
        cout<<"Size of vec = "<<vec.size()<<endl;
        cout<<"The total time take = "<<endTime-strTime<<" (secs)"<<endl<<endl;
        map<unsigned int, unsigned int>::iterator iter=test.begin();
        int max=0;
        for(;iter!=test.end();iter++){
//            cout<<iter->first<<" "<<iter->second<<endl;
            if(iter->second>max)max = iter->second;
        }
        cout<<max<<endl;
        cout<<s.size()<<endl;
    }

    //Exit stage right
    return 0;
}

//void prntRes(unsigned int range[],int n){
//    cout<<"Range      Frequency"<<endl;
//    for(int i=n;i>=0;i--) {
//        cout<<"10^"<<i<<"-10^"<<(i+1)<<": "<<range[i]<<endl;
//    }
//}