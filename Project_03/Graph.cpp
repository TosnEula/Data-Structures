#include "Graph.h"

//add vertex to the vertex vector
void Graph::addVertex(Vertex *vertex)
{
    verticies.push_back(vertex);
}

//add edge to the edge vector
void Graph::addEdge(Edge *edge)
{
    edges.push_back(edge);
}

//prints the shortest route from start to end
void Graph::shortestRoute(std::string start, std::string end)
{
    //Defining variables

    Vertex* vStart= nullptr, *vEnd= nullptr;        //Define two vertex pointers to assign to the start and end.
    int size;                                       //holds the degree of the starting vertex
    std::vector<std::string> fastPath;              //Vector that holds the edges to the shortest path

    //Check to make sure the start and end are not the same
    if(start == end)
    {
        std::cout<< "Please pick two separate vertices";
        return;
    }

    //locate the start and the end vertex and assign it to vStart and vEnd.
    for(int x = 0; x<verticies.size(); x++)
    {
        if(start == verticies.at(x)->getName()) {
            vStart = verticies.at(x);
        }

        if(end == verticies.at(x)->getName())
        {
            vEnd = verticies.at(x);
        }

    }

    //Escape case should the user input a nonexistant vertex
    if (vEnd == nullptr || vStart == nullptr)
    {
        std::cout << "Could not locate a vertex" << std::endl;
        return;
    }

    //Assigning the size of the degree of the starting vertex
    size = vStart->getDegree();

    //calling the function to do the calculations to find the shortest path
    fastPath = shortestRouteCal(vStart, vEnd, size - 1);

    //printing the results
    std::cout << "The path with the smallest cost to reach "<< vEnd->getName() <<" is: ";

    for (int x = 0; x < fastPath.size(); x++)
    {
        std::cout << fastPath.at(x) << std::endl;
    }



}


std::vector<std::string> Graph::shortestRouteCal(Vertex *cStart, Vertex *cEnd, int curEdgeNo)
{
    //Defining variables
    static int bestWeight = 999, currentWeight = 0;
    static std::vector<Vertex*> prevVertex, checkedVer;
    static std::vector<int> remEdges;
    static std::string check;
    static std::vector<std::string> edgePath, bestPath;
    bool dupVer = 0;

    //Ensures that the vertex is not going to be repeatedly added to the checked vector
    for (int x = 0; x < checkedVer.size(); x++)
    {
        if(checkedVer.at(x) == cStart)
            dupVer =1;
    }
    if (dupVer == 0)
        checkedVer.push_back(cStart);

    //Base case the current vertex is out of edges to check
    if(curEdgeNo == -1)
    {
        return bestPath;
    }

    //assigns the edge that will be looked at during this iteration of the vertex that is being looked at.
    Edge* currentEdge = cStart->getEdge(curEdgeNo);

    //Second base case, where the edge of the vertex leads to the destination
    if (currentEdge->getDestination()->getName() == cEnd->getName())
    {
        //Recursively calls it self back to see if there are any other paths
        shortestRouteCal(cStart, cEnd, curEdgeNo - 1);

        //totals the weight of the edge being checked
        currentWeight += currentEdge->getWeight();

        //Gets the name of the edge being used in this path
        edgePath.push_back(currentEdge->getName());

        //if the current weight is less that the
        if(currentWeight < bestWeight)
        {
            bestWeight = currentWeight;
            bestPath = edgePath;
        }
        currentWeight-=currentEdge->getWeight();
        edgePath.pop_back();
        return bestPath;
    }

    dupVer=0;
    for (int x = 0; x < checkedVer.size(); x++)
    {
        if(checkedVer.at(x) == currentEdge->getDestination())
            dupVer =1;
    }

    if(dupVer != 1)
    {
        //stores the vertex and edges remaing to check
        currentWeight += currentEdge->getWeight();
        edgePath.push_back(currentEdge->getName());
        prevVertex.push_back(cStart);
        remEdges.push_back(curEdgeNo);

        cStart = currentEdge->getDestination();
        checkedVer.push_back(currentEdge->getDestination());
        curEdgeNo = cStart->getDegree();

        //recursive call starting at the following node
        shortestRouteCal(cStart, cEnd, curEdgeNo - 1);

        //Moves to the node before the recursion and returns all the values.
        cStart = prevVertex.back();
        prevVertex.pop_back();

        curEdgeNo = remEdges.back();
        remEdges.pop_back();

        edgePath.pop_back();

        currentWeight -= cStart->getEdge(curEdgeNo)->getWeight();

        //check the next edge of the node
        shortestRouteCal(cStart, cEnd, curEdgeNo - 1);
        return bestPath;
    }
    return bestPath;
}

//Prints the adjacency list for the current graph
void Graph::adjacencyList()
{
    //prints the header
    std::cout<< "\t";
    for (int x = 0; x < verticies.size(); x++)
    {
        std::cout << verticies.at(x)->getName() << "\t";
    }

    std::cout << std::endl << "---------------------------------------------------" << std::endl;

    //prints the body
    for (int x=0; x<verticies.size(); x++)
    {
        std::cout << verticies.at(x)->getName() << "\t";
        for(int y = 0; y<verticies.size(); y++)
        {
            if(x==y)
            {
                std::cout << "0\t";
            }
            else
            {
                std::cout << checkAdjacent(verticies.at(x),verticies.at(y)) << "\t";
            }

        }
        std::cout << std::endl;
    }

}

//Checks if the starting vertex is adjacent to the desired vertex
bool Graph::checkAdjacent(Vertex *sVer, Vertex *cVer)
{
    for(int y=0; y< sVer->getDegree(); y++)
    {
        if (sVer->getEdge(y)->getDestination() == cVer)
        {
            return true;
        }
    }
        return false;
}

//Performs a breadth first search
void Graph::bFSearch(std::string targetVer)
{
    Vertex *checkedVer;
    bool repeatedVer;
    std::string checked [verticies.size()], queued[verticies.size()];
    int iteration=0;
    std::queue <Vertex*> vertCheck;
    vertCheck.push(verticies.at(0));
    //Uses a queue to keep track of the verticies that need to be checked.
    queued[0] = verticies.at(0)->getName();

    while(!vertCheck.empty())
    {
        //visits vertex
        if(vertCheck.front()->getName() == targetVer)
        {

            std::cout << "Vertices visited before reaching " << targetVer << " are: ";;
            for (int x = 0; x < iteration; x++)
            {
                std::cout << checked[x] << std::endl;
            }
            return;

        }

        //adds the visited vertex to the checked list
        checked[iteration] = vertCheck.front()->getName();
        //sets the variable for the checked vertex to the vertex current
        checkedVer = vertCheck.front();
        //remove the visited vertex from the queue
        vertCheck.pop();
        iteration++;

        //Checks if the vertex is either repeated or queued
        //and if not adds it to the queue.
        for (int x = 0; x < checkedVer->getDegree(); x++)
        {

            for (int y = 0; y < iteration ; y++)
            {
                if (queued[y] == checkedVer->getEdge(x)->getDestination()->getName())
                    repeatedVer = 1;
            }
            if(repeatedVer != 1)
            {
                vertCheck.push(checkedVer->getEdge(x)->getDestination());
                queued[iteration] = checkedVer->getEdge(x)->getDestination()->getName();
            }
            repeatedVer=0;
        }


    }
    //Escape statement should a vertex not exist
    std::cout << "Cannot locate vertex after visiting: " << std::endl;
    for (int x = 0; x < iteration; x++)
    {
        std::cout << checked[x] << std::endl;

    }

}


void Graph::dFSearch(std::string targetVer)
{
   Vertex *checkedVer;
    bool repeatedVer;
    std:std::string checked [verticies.size()];
    int iteration=0;
    std::vector <Vertex*> vertCheck;
    vertCheck.push_back(verticies.at(0));
    while(!vertCheck.empty())
    {
        //visits vertex
        if(vertCheck.back()->getName() == targetVer)
        {
            std::cout << "Vertices visited before reaching " << targetVer << " are: ";
            for (int x = 0; x < iteration; x++)
            {
                std::cout << checked[x] << std::endl;
            }
            return;
        }

        //adds the visited vertex to the checked list
        checked[iteration] = vertCheck.back()->getName();
        //sets the variable for the checked vertex to the vertex current
        checkedVer = vertCheck.back();
        //remove the visited vertex from the stack
        vertCheck.pop_back();
        iteration++;
        //Checks if the vertex is either repeated or in the stack
        //and if not adds it to the stacl.
        for (int x = 0; x < checkedVer->getDegree(); x++)
        {

            for (int y = 0; y < iteration ; y++)
            {
                if (checked[y] == checkedVer->getEdge(x)->getDestination()->getName())
                    repeatedVer=1;
            }

            for (int z = 0; z < vertCheck.size(); z++)
            {
                if (vertCheck.at(z)->getName() == checkedVer->getEdge(x)->getDestination()->getName())
                    repeatedVer=1;
            }
            if(repeatedVer != 1)
                vertCheck.push_back(checkedVer->getEdge(x)->getDestination());

            repeatedVer=0;
        }



    }
    std::cout << "Cannot locate vertex after visting: " << std::endl;
    for (int x = 0; x < iteration; x++)
    {
        std::cout << checked[x] << std::endl;

    }
}

