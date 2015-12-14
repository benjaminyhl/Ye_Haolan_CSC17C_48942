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
    parent=new int[nVert];
    for(int i=0;i<nVert;i++)
        parent[i]=-1;
}

Graph::~Graph() {
    delete []adj;
    delete []parent;
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
    int weight=0;//weight of the tree
    set<int> s;
//Get the minimum spanning tree
    for(;it2!=ls.end();++it2) {
        //Determine create circle or not
        if(!isCycle((*it2).second.first,(*it2).second.second)) {
            weight+=(*it2).first;
            s.insert((*it2).second.first);
            s.insert((*it2).second.second);
            cout<<(*it2).second.first<<" --- "<<(*it2).second.second;
            cout<<"   "<<(*it2).first<<endl;
        }
    }
    cout<<"Weight: "<<weight<<endl;
}

//find the parent
int Graph::find(int x) {
    if(parent[x]==-1)
        return x;
    return find(parent[x]);
}

//Determine it creates circle after connect x and y node
bool Graph::isCycle(int x,int y) {
    // Iterate through all edges of graph, find subset of both
    // vertices of every edge, if both subsets are same, then 
    // there is cycle in graph.
    int xpar=find(x);
    int ypar=find(y);
    if(xpar==ypar) return true;
    unionVer(x,y);
    return false;
}

//put x and y into union
void Graph::unionVer(int x, int y) {
    int xset=find(x);
    int yset=find(y);
    parent[xset]=yset;
}

//   Prim’s Minimum Spanning Tree (MST)
void Graph::primMST() {
    
}

//shortest path between two points with Dijkstra's algorithm
int Graph::shortestPath(int a, int b) {
    int c=1;
    return c;
}

