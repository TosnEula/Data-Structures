#include "Vertex.h"

//Constructor
Vertex::Vertex(std::string name)
{
    this->name = name;
}

//copies the contents of the edge into the vector
void Vertex::addEdge(Edge *newEdge)
{
    edges.push_back(new Edge(newEdge->getName(), newEdge->getSource(), newEdge->getDestination(), newEdge->getWeight()));
}

//Returns the edge from the vector
Edge* Vertex::getEdge(int location)
{
   return edges.at(location);
}

//Returns the size of the vertex
int Vertex::getDegree()
{
    return edges.size();
}

//Operator overload for cout
//This prints the name of the edge
std::ostream &operator<<(std::ostream &os, Vertex &vertex)
{
    os << vertex.getName();
    return os;


}

const std::string &Vertex::getName() const
{
    return name;
}

void Vertex::setName(const std::string &name)
{
    Vertex::name = name;
}
