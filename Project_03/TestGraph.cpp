#include "Edge.h"
#include "Vertex.h"
#include <iostream>
#include "Graph.h"
#include <fstream>
#include <sstream>
#include <string.h>

int main()
{
    std::string graphLine, word;
    int noNodes, iteration = 0, cycle = 0;
    std::fstream graphFile;
    std::vector<Vertex*> nodeList;
    std::vector<std::string> source, destination;
    std::vector<int>weight;
    Graph map;
    std::vector<Edge*> edgeList;
    std::string edgeName;
    char dyName[3] = "a1";
    Vertex *cSource, *cDestination;
    char choice ='z';
    std::string startVer, endVer;

    //Assign the text file to the variable graphFile
    graphFile.open("../Project_03/Graph.txt", std::ios::in);

    //Seperate the text document into lines

    while(std::getline(graphFile, graphLine))
    {
        std::stringstream parts(graphLine);
        while(std::getline(parts, word,','))
        {
            //blank line in the text file but its not finished
            if (word==" ")
            {

            }
            //First line of the file is always the amount of verticies
            else if(iteration == 0)
            {
                noNodes = std::stoi(word);
                iteration++;

            }
            //Add the name of each vertex to a vector
            else if(iteration<=noNodes)
            {
                nodeList.push_back(new Vertex(word));
                map.addVertex(nodeList.at(iteration-1));
                iteration++;
            }
            //Get the source, destination and weight of each edge
            else
            {
                iteration++;
                switch (cycle)
                {
                    case 0:
                        source.push_back(word);
                        cycle++;
                        break;

                    case 1:
                        destination.push_back(word);
                        cycle++;
                        break;
                    case 2:
                        weight.push_back(std::stoi(word));
                        cycle = 0;
                        break;
                }
            }
        }
    }


    //add the edges to a vector
    for (int i = 0; i < (iteration-noNodes-1)/3; i++)
    {
        //Once the number of edges passes 9, it changes the letter and start back at 1
        if(dyName[1] == ':')
        {
            dyName[0]++;
            dyName[1]='1';
        }
        edgeName.append(dyName);

        //finds the related vertice for the source and destination of the edge
        for (int j = 0; j < nodeList.size(); j++)
        {

            if(nodeList.at(j)->getName()==source.at(i))
            {
                cSource=nodeList.at(j);
            }
            if(nodeList.at(j)->getName()==destination.at(i))
            {
                cDestination = nodeList.at(j);
            }
        }


        edgeList.push_back(new Edge(edgeName));
        edgeList.at(i)->setName(edgeName);
        edgeList.at(i)->setSource(cSource);
        edgeList.at(i)->setDestination(cDestination);
        edgeList.at(i)->setWeight(weight.at(i));
        edgeName="";
        dyName[1]++;


    }
    //add the edges to the vectors
    for (int i = 0; i < nodeList.size(); i++)
    {
        for (int j = 0; j < edgeList.size(); ++j)
        {
            if(edgeList.at(j)->getSource()->getName() == nodeList.at(i)->getName())
            {

                nodeList.at(i)->addEdge(edgeList.at(j));
            }
        }

    }

    //add the edges to the graph
    for (int i = 0; i < edgeList.size(); i++)
    {

        map.addEdge(edgeList.at(i));
    }




    //UI interface
    while(choice != '0')
        {
        std::cout<< "Please input an option" <<std::endl;
        std::cout<< "------------------------------------------------------" << std::endl;
        std::cout << "[1] Print adjacency list" << std::endl;
        std::cout << "[2] Shortest Path" << std::endl;
        std::cout << "[3] Breadth First Search" << std::endl;
        std::cout << "[4] Depth First Search" << std::endl;
        std::cout << "[0] Exit" << std::endl;

        std::cin >> choice;

            switch (choice)
            {
                case '1':
                    map.adjacencyList();
                    break;
                case '2':
                    std::cout << "Please input a starting vertex: ";
                    std::cin >> startVer;
                    std::cout << "Please input an ending vertex: ";
                    std::cin >> endVer;
                    map.shortestRoute(startVer, endVer);
                    break;
                case '3':
                    std::cout << "Please input an ending vertex: ";
                    std::cin >> endVer;
                    map.bFSearch(endVer);
                    break;
                case '4':
                    std::cout << "Please input an ending vertex: ";
                    std::cin >> endVer;
                    map.dFSearch(endVer);
                    break;
                case '0':
                    break;
                default:
                    std::cout << "Please input a valid option." << std::endl;
            }

    }
}