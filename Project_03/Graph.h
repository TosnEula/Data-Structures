#include <iostream>
#include <vector>
#include <queue>

#ifndef Graph_h
#define Graph_h
#include "Vertex.h"
#include "Edge.h"

class Vertex;
class Edge;

class Graph
{
std::vector<Vertex*> verticies;
std::vector<Edge*> edges;

public:

    //add an edge or a vertex to the graph
    void addVertex(Vertex *vertex);
    void addEdge(Edge *edge);

    //Finds the shortest route from a given starting vertex to an end vertex
    void shortestRoute(std::string start, std::string end);
    //function that does all the calculations
    std::vector<std::string> shortestRouteCal(Vertex* cStart, Vertex* cEnd, int curEdgeNo);

    //Prints the adjancency list of the graph
    void adjacencyList();
    //Checks if an edge is adjacent to another
    bool checkAdjacent(Vertex* sVer,Vertex* cVer);

    //Breadth first search
    void bFSearch(std::string targetVer);

    //depth first search
    void dFSearch(std::string targetVer);
};


#endif	//Graph_h