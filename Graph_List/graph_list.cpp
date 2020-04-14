#include <iostream>
#include <iomanip>

struct listNode   
{
    int vertexData; //dana jaka zawiera wierzcholek
    listNode* nextNode;
};
struct listNode* createNode(int);

int main()
{
    int vertices; // liczba wierzcholkow w grafie
    int edges; // liczba krawedzi w grafie
    int vertexSource,vertexDestination; // pierwszy i ostatni wierzcholek
    listNode **adjacencyList;
    listNode* newNode; //zmienna potrzebna do obslugi
    listNode* tmpNode; //zmienna potrzeban do obslugi
    std::cout << "Podaj liczbe wierzcholkow: ";
    std::cin >> vertices;
    std::cout << "Podaj liczbe krawedzi w grafie: ";
    std::cin >> edges;

    //tworzymy tablice listy sasiedztwa
    adjacencyList = new listNode* [vertices];

    //tablice wypelniamy pustymi miejscami
    for(int i = 0; i < vertices; i++)
        adjacencyList[i] = NULL;

    //dodanie krawedzi do naszego grafu
    for(int i = 0; i < edges; i++)
    {
        std::cout << "Podaj vertexSource: " ;
        std::cin >> vertexSource;
        std::cout << "Podaj vertexDestination: ";
        std::cin >> vertexDestination;
        //dodaj krawedz od zrodla do celu
        newNode = createNode(vertexDestination);
        newNode->nextNode = adjacencyList[vertexSource];
        adjacencyList[vertexSource] = newNode;

        //dodaj krawedz od celu do zrodla
        newNode = createNode(vertexSource);
        newNode->nextNode = adjacencyList[vertexDestination];
        adjacencyList[vertexDestination] = newNode;
    }

    //wypisanie grafi
    for (int i = 0; i <vertices; i++)
    {
        tmpNode = adjacencyList[i];
        std::cout << "Adjacency list of vertex " << i << ": ";
        while(tmpNode)
        {
            std::cout << tmpNode->vertexData << " ";
            tmpNode = tmpNode->nextNode;
        }
        std::cout << std::endl;
    }

    //Usuwanie listy sasiedztwa
    for(int i = 0; i < vertices; i++)
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
    
    return 0;
}


struct listNode* createNode(int vertex)
{
    listNode *newNode = new listNode;
    newNode->vertexData = vertex;   
    newNode->nextNode = NULL;
    return newNode;
}
