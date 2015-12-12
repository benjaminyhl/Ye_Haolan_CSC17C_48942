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
    bool *visited=new bool[nVert];
    for(int i=0;i<nVert;i++) {
        visited[i]=false;
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

