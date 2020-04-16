#include "graph_matrix.hpp"

GraphMatrix::~GraphMatrix()
{
    //usuwamy kolumny
    for (int i = 0; i < this->verticesGraph; i++)
        delete[] adjacencyMatrix[i];

    //usuwamy cala tablice 
    delete[] adjacencyMatrix;
}

void GraphMatrix::addEdge(int vertexSource, int vertexDestination)
{
    this->adjacencyMatrix[vertexSource][vertexDestination] += 1;
    //jesli mamy graf nieskierowany to:
    this->adjacencyMatrix[vertexDestination][vertexSource] += 1;
}

void GraphMatrix::removeEdge(int vertexSource, int vertexDestination)
{
    //jesli krawedz nie istnieje
    if (this->adjacencyMatrix[vertexSource][vertexDestination] == 0)
        return;

    this->adjacencyMatrix[vertexSource][vertexDestination] -= 1;
    //jesli mamy graf nieskierowany
    this->adjacencyMatrix[vertexDestination][vertexSource] -= 1;
}

void GraphMatrix::fillGraph()
{
    srand(time(NULL));
    int vertexSource;
    int vertexDestination;
    for (int i = 0; i < this->edgesGraph; i++)
    {
        //usuwamy przypadek jesli wylosowalby te same wierzcholki zeby nie bylo petli w grafie
        do {
            vertexSource = rand() % this->verticesGraph;
            vertexDestination = rand() % this->verticesGraph;
        } while (vertexSource == vertexDestination);
        addEdge(vertexSource, vertexDestination);
    }
}

void GraphMatrix::printfGraph()
{
    for (int i = 0; i < this->verticesGraph; i++)
    {
        for (int j = 0; j < this->verticesGraph; j++)
            std::cout << this->adjacencyMatrix[i][j] << " ";
        std::cout << std::endl;
    }
}