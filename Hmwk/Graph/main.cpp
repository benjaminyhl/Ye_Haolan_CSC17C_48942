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
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    cout << "Following is Breadth First Traversal (starting from vertex 2): \n";
    g.BFS(2);
    return 0;
}

