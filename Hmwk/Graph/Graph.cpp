/* 
 * File:   Graph.cpp
 * Author: Haolan Ye (Benjamin)
 * Created on December 6, 2015, 9:14 AM
 * Graph 
 * 1. Traverse the graph with Breath First Search and Depth First Search
 * 2. Find minimum spanning tree
 * 3. shortest path between any 2 points
 */

#include "Graph.h"
Graph::Graph(int n) {
    nVert=n;
    adj=new list<pair<int,int> >[n];
}

Graph::~Graph() {
    delete []adj;
}

void Graph::addEdge(int a, int b,int d) {
    //a --- First node
    //b --- Second node
    //d --- Distance between them
    adj[a].push_back(make_pair(b,d));
}

//Traverse the graph with Breath First Search
void Graph::BFS(int s) {
    //bool array for each node
    bool *visited=new bool[nVert];
    for(int i=0;i<nVert;i++) {
        visited[i]=false;
    }
    //create a queue fir BFS
    list<int> queue;
    
    //mark the current as visited
    visited[s]=true;
    queue.push_back(s);
    
    list<pair<int,int> >::iterator it;
    
    while(!queue.empty()) {
        s=queue.front();
        cout<<s<<" ";
        queue.pop_front();
        for(it=adj[s].begin();it!=adj[s].end();++it) {
            if(!visited[(*it).first]) {
                visited[(*it).first]=true;
                queue.push_back((*it).first);
            }
        }
    }
    cout<<endl<<endl;
    delete []visited;
}

//Traverse the graph with Depth  First Search
void Graph::DFS(int s) {
    //bool array for each node
    bool *visited=new bool[nVert];
    for(int i=0;i<nVert;i++) {
        visited[i]=false;
    }
    //Traversal recursively
    DFS(s,visited);
    cout<<endl<<endl;
    delete []visited;
}

//DFS for recursion
void Graph::DFS(int s, bool *visited) {
    //mark the current as visited
    visited[s]=true;
    cout<<s<<" ";
    //create a iterator
    list<pair<int,int> >::iterator it=adj[s].begin();
    for(;it!=adj[s].end();++it) {
        //if the node is unread
        if(!visited[(*it).first]) {
            //DFS this node
            DFS((*it).first,visited);
        }
    }
    
}

//Kruskal’s Minimum Spanning Tree (MST)
void Graph::krusMST() {
    vector<pair< int, pair<int,int> > > ls;
//    int min=0,max=0;
    //sort all the edge
    //input the beginning vertex,end vertex, distance from the private list<int,int> adj
    list<pair<int,int> >::iterator it;
    for(int i=0;i<nVert;i++) {
        for(it=adj[i].begin();it!=adj[i].end();++it) {
            ls.push_back(make_pair((*it).second,make_pair(i,(*it).first)));
            
//            if(ls.empty()) {
//                min=(*it).second;
//                max=(*it).second;
////                cout<<min<<" "<<max<<endl;
//                ls.push_back(make_pair(i,make_pair((*it).first,(*it).second)));
////                cout<<"111";
//            } else {
//                if((*it).second<min) {
//                    min=(*it).second;
////                    cout<<"Min: "<<min<<endl;
//                    ls.push_front(make_pair(i,make_pair((*it).first,(*it).second)));
//                } else {
//                    max=(*it).second;
////                    cout<<"Max: "<<max<<endl;
//                    ls.push_back(make_pair(i,make_pair((*it).first,(*it).second)));
//                }
//            }
        }
        
    }
    sort(ls.begin(),ls.end());
    cout<<"Size: "<<ls.size()<<endl;
    vector<pair< int, pair<int,int> > >::iterator it2=ls.begin();
    
    //output all the edge with vertices
//    for(;it2!=ls.end();++it2) {
//        int a,b,c;
//        a=(*it2).first;
//        b=(*it2).second.first;
//        c=(*it2).second.second;
//        cout<<a<<" "<<b<<" "<<c<<endl;
//    }
    
    bool *visited=new bool[nVert];
    for(int i=0;i<nVert;i++) {
        visited[i]=false;
    }
    int weight=0;//weight of the tree
//Get the minimum spanning tree
    for(;it2!=ls.end();++it2) {
        //If not first and second node both have been visited
        if(!(visited[(*it2).second.first]&&visited[(*it2).second.second])) {
//            cout<<"aaa"<<endl;
            weight+=(*it2).first;
            visited[(*it2).second.first]=true;
            visited[(*it2).second.second]=true;
            cout<<(*it2).second.first<<" --- "<<(*it2).second.second;
            cout<<"   "<<(*it2).first<<endl;
        }
    }
    
    
    delete []visited;
}

//   Prim’s Minimum Spanning Tree (MST)
void Graph::primMST() {
    
}

//shortest path between two points with Dijkstra's algorithm
int Graph::shortestPath(int a, int b) {
    int c=1;
    return c;
}

