#include "graph_list.hpp"

struct listNode* GraphList::createNode(int vertexSource,int vertexDestination,int weight)
{
    listNode *newNode = new listNode;
    newNode->vertexSource = vertexSource;
    newNode->vertexDestination = vertexDestination;
    newNode->weightNode = weight;   
    newNode->nextNode = NULL;
    return newNode;
}

GraphList::~GraphList()
{
    listNode* newNode; //zmienna potrzebna do obslugi
    listNode* tmpNode; //zmienna potrzebna do obslugi
    for(int i = 0; i < this->verticesGraph; i++)
    {
        tmpNode = adjacencyList [ i ];
        while( tmpNode )
        {
            newNode = tmpNode;
            tmpNode = tmpNode->nextNode;
            delete newNode;
        }
    }
    delete [ ] adjacencyList;
}


void GraphList::addEdge(int vertexSource,int vertexDestination,int weight)
{
    listNode* newNode; //zmienna potrzebna do obslugi

    //dodaj krawedz od zrodla do celu
    newNode = createNode(vertexSource,vertexDestination,weight);
    newNode->nextNode = this->adjacencyList[vertexSource];
    this->adjacencyList[vertexSource] = newNode;

    //dodaj krawedz od celu do zrodla
    newNode = createNode(vertexDestination,vertexSource,weight);
    newNode->nextNode = adjacencyList[vertexDestination];
    this->adjacencyList[vertexDestination] = newNode;
}


void GraphList::fillGraph()
{
    srand(time(NULL));
    int vertexSource;// wierzcholek zrodlowy
    int vertexDestination; // wierzcholek docelowy
    int weight; // waga polaczenia 
    for(int i = 0; i < this->edgesGraph; i++)
    {
        //usuwamy przypadek jesli wylosowalby te same wierzcholki zeby nie bylo petli w grafie
        do{
            vertexSource = rand() % this->verticesGraph;
            vertexDestination = rand() % this->verticesGraph;
        }while(vertexSource == vertexDestination);    
        weight = rand () % 1000;
        addEdge(vertexSource,vertexDestination, weight);
    }
}

void GraphList::printfGraph()
{
    listNode* tmpNode; //zmienna potrzeban do obslugi
    for (int i = 0; i < this->verticesGraph; i++)
    {
        tmpNode = adjacencyList[i];
        std::cout << "Wierzcholek listy sasiedztwa " << i << ": ";
        while(tmpNode)
        {
            std::cout << tmpNode->vertexSource <<"->" << tmpNode->vertexDestination << "(" << tmpNode->weightNode <<")"<< " ";
            tmpNode = tmpNode->nextNode;
        }
        std::cout << std::endl;
    }
}

void GraphList::cleanMemory()
{
    listNode* newNode; //zmienna potrzebna do obslugi
    listNode* tmpNode; //zmienna potrzebna do obslugi
    for(int i = 0; i < this->verticesGraph; i++)
    {
        tmpNode = adjacencyList [ i ];
        while( tmpNode )
        {
            newNode = tmpNode;
            tmpNode = tmpNode->nextNode;
            delete newNode;
        }
    }
    delete [ ] adjacencyList;
}