#include <iostream>
#include <vector>


#ifndef Vertex_h
#define Vertex_h
#include "Edge.h"

class Edge;

class Vertex
{
    //Defining variables
	std::string name;
	std::vector<Edge*> edges;
	
	public:
    //constructor
	Vertex(std::string name);

    //prototype to add an edge to the current vertex
    void addEdge(Edge *newEdge);

    //Returns the edge at the given location
    Edge * getEdge(int location);

    //Returns the amount of edges the vertex has
    int getDegree();

    //operator overload of <<, for testing.
    friend std::ostream& operator<< (std::ostream& os, Vertex& Vertex);

    //Getter and Setter
    const std::string &getName() const;
    void setName(const std::string &name);
};


#endif	//Vertex_h