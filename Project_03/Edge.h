#include <iostream>
#include <vector>


#ifndef EDGE_H
#define EDGE_H
#include "Vertex.h"

class Vertex;

class Edge
{
    //Defining variables
    std::string name;
    Vertex *source = nullptr, *destination= nullptr;
    int weight;

public:
    //constructor
    Edge(std::string name, Vertex *source, Vertex *dest, int weight);
    Edge(std::string name);

    //Operator overloading of <<. for testing purposes.
    friend std::ostream& operator<< (std::ostream& os, Edge& edge);



    //Getter and setters
    const std::string &getName() const;
    void setName(const std::string &name);

    Vertex *getSource() const;
    void setSource(Vertex *source);

    Vertex *getDestination() const;
    void setDestination(Vertex *destination);

    int getWeight() const;
    void setWeight(int weight);
};


#endif //EDGE_H
