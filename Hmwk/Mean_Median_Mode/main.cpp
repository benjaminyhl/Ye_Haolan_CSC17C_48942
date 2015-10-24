/* 
 * File:   main.cpp
 * Author: Haolan Ye (Benjamin)
 * Created on October 22, 2015, 8:55 AM
 */

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <iterator>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

int main(int argc, char** argv) {
    //set seeds for random numbers
    srand(static_cast<unsigned int>(time(0)));
    int n=100;//number of elements
    int pl=10;//per line
    vector<int> vec;
    set<int> s;
    set<int>::iterator pos;//iterator for set
    int temp;
    float ave=0;//average
    float median=0;//median
    
    //insert and output random 2-digit number into vector
    //insert these number to the set
    cout<<"Here are "<<n<<" integers: "<<endl;
    for(int i=0;i<n;i++) {
        temp=rand()%+10;
//        temp=rand()%10;
        cout<<temp<<" ";
        if(i%pl==(pl-1)) cout<<endl;
        ave+=temp;
        vec.push_back(temp);
        s.insert(temp);
    }
    cout<<endl<<endl;
    //sort the vector
    sort(vec.begin(),vec.end());
    
    //create a map and let the elements in sets be the keys of map
    map<int,int> m;
    for(pos=s.begin();pos!=s.end();++pos) {
        m[*pos]=0;
    }
    
    //get the average
    ave/=n;
    //Get the median
    if(n%2==1) {
        median=vec[n/2];
    } else {
        median=(vec[n/2]+vec[n/2-1])/2.0f;
    }
    cout<<"After sorting: "<<endl;
    
    //output the elements in vector after sorting
    for(int i=0;i<vec.size();i++) {
        m[vec[i]]++;
        cout<<vec[i]<<" ";
        if(i%pl==(pl-1)) cout<<endl;
    }
    cout<<endl<<endl;
    
    set<int> mode;
    int times=0;
    //Output the frequency
    cout<<"Frequency"<<endl;
    cout<<"Key   Value"<<endl;
    for(pos=s.begin();pos!=s.end();pos++) {
        cout<<*pos<<"     "<<m[*pos]<<endl;
        //Get the mode from the map
        if(m[*pos]>times) {
            mode.clear();
            mode.insert(*pos);
            times=m[*pos];
        } 
        if(m[*pos]==times) {
            mode.insert(*pos);
        } 
    }
    
    //Output the result
    cout<<"Average: "<<ave<<endl;
    cout<<"Median: "<<median<<endl;
    cout<<"Mode: ";
    for(pos=mode.begin();pos!=mode.end();++pos) {
        cout<<*pos<<"  ";
    }
    cout<<endl;
    return 0;
}

