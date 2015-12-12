/* 
 * File:   main.cpp
 * Author: Haolan Ye (Benjamin)
 * Created on December 6, 2015, 9:11 AM
 * Graph 
 * 1. Traverse the graph with Breath First Search and Depth First Search
 * 2. Find minimum spanning tree
 * 3. shortest path between any 2 points
 */

#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;

#include "Graph.h"

int main(int argc, char** argv) {
    Graph g(8);
    g.addEdge(0, 1, 1);
    g.addEdge(0, 3, 1);
    g.addEdge(0, 5, 1);
    g.addEdge(0, 6, 1);
    g.addEdge(1, 4, 1);
    g.addEdge(1, 0, 1);
    g.addEdge(1, 5, 1);
    g.addEdge(2, 5, 1);
    g.addEdge(2, 7, 1);
    g.addEdge(3, 0, 1);
    g.addEdge(3, 5, 1);
    g.addEdge(4, 1, 1);
    g.addEdge(4, 6, 1);
    g.addEdge(5, 1, 1);
    g.addEdge(5, 2, 1);
    g.addEdge(5, 3, 1);
    g.addEdge(6, 0, 1);
    g.addEdge(6, 4, 1);
    g.addEdge(7, 2, 1);
    
//    Graph g(4);
//    g.addEdge(0, 1,1);
//    g.addEdge(0, 2,1);
//    g.addEdge(1, 2,1);
//    g.addEdge(2, 0,1);
//    g.addEdge(2, 3,1);
//    g.addEdge(3, 3,1);

    cout << "Following is Breadth First Traversal (starting from vertex 2): \n";
    g.DFS(0);
    return 0;
}

