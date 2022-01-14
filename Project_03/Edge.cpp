#include "Edge.h"

//Constructor definition
Edge::Edge(std::string name, Vertex *source, Vertex *dest ,int weight)
{
    this->name = name;
    this->source = source;
    this->destination = dest;
    this->weight = weight;
}

Edge::Edge(std::string name)
{
    this->name = name;

}

//Operator overload for <<
//This prints the name of the edge
std::ostream &operator<<(std::ostream &os, Edge &edge)
{
    os << edge.getName() << ", ";
    os << edge.getSource()->getName();
    return os;
}


//Getter and setters
const std::string &Edge::getName() const {
    return name;
}

void Edge::setName(const std::string &name) {
    Edge::name = name;
}

Vertex *Edge::getSource() const {
    return source;
}

void Edge::setSource(Vertex *source) {
    Edge::source = source;
}

Vertex *Edge::getDestination() const {
    return destination;
}

void Edge::setDestination(Vertex *destination) {
    Edge::destination = destination;
}

int Edge::getWeight() const {
    return weight;
}

void Edge::setWeight(int weight) {
    Edge::weight = weight;
}

