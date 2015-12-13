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
    g.addEdge(0, 1, 3);
    g.addEdge(0, 5, 7);
    g.addEdge(0, 4, 4);
    g.addEdge(1, 0, 3);
    g.addEdge(1, 2, 5);
    g.addEdge(1, 5, 8);
    g.addEdge(2, 1, 5);
    g.addEdge(2, 3, 4);
    g.addEdge(2, 5, 6);
    g.addEdge(3, 2, 4);
    g.addEdge(3, 4, 2);
    g.addEdge(3, 5, 8);
    g.addEdge(4, 0, 4);
    g.addEdge(4, 3, 2);
    g.addEdge(4, 5, 5);
    g.addEdge(5, 0, 7);
    g.addEdge(5, 1, 8);
    g.addEdge(5, 2, 6);
    g.addEdge(5, 3, 8);
    g.addEdge(5, 4, 5);
    
//    Graph g(4);
//    g.addEdge(0, 1,1);
//    g.addEdge(0, 2,1);
//    g.addEdge(1, 2,1);
//    g.addEdge(2, 0,1);
//    g.addEdge(2, 3,1);
//    g.addEdge(3, 3,1);

    cout << "Following is Breadth First Traversal (starting from vertex 2): \n";
//    g.DFS(0);
    g.krusMST();
    return 0;
}

