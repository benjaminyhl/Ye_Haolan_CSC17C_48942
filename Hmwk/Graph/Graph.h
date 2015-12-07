/* 
 * File:   Graph.h
 * Author: Haolan Ye (Benjamin)
 * Created on December 6, 2015, 9:14 AM
 * Graph 
 * 1. Traverse the graph with Breath First Search and Depth First Search
 * 2. Find minimum spanning tree
 * 3. shortest path between any 2 points
 */

#ifndef GRAPH_H
#define	GRAPH_H

#include <iostream>
#include <list>
#include <iterator>
using namespace std;

class Graph {
    private:
        int nVert;//number of vertices
        list<int> *adj;
    public:
        Graph(int);//constructor
        ~Graph();
        void addEdge(int,int);
        void BFS(int);//Traverse the graph with Breath First Search
        void DFS(int);//Traverse the graph with Depth  First Search
        void primMST();//   Prim’s Minimum Spanning Tree (MST)
        void krusMST();//Kruskal’s Minimum Spanning Tree (MST)
        int shortestPath(int,int);//shortest path between two points with Dijkstra's algorithm
};

#endif	/* GRAPH_H */

