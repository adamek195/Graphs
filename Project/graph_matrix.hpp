#ifndef graph_matrix_hpp
#define graph_matrix_hpp
#include "graph.hpp"
#include "vector.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>


class GraphMatrix:public Graph
{
    vectorClass** adjacencyMatrix; // tablica intow opisujaca macierz sasiedztwa z wagami

    public:
    GraphMatrix(int vertices,double density):Graph(vertices,density)
    {
        //tworzymy tablice
         this->adjacencyMatrix  = new vectorClass *[vertices];
        // tworzymy liczbe kolumn
        for(int i = 0; i < vertices; i++)
            this->adjacencyMatrix[i] = new vectorClass[vertices];
    }
    GraphMatrix(int vertices,int edges,double density):Graph(vertices,edges,density)
    {
        //tworzymy tablice
         this->adjacencyMatrix  = new vectorClass *[vertices];
        // tworzymy liczbe kolumn
        for(int i = 0; i < vertices; i++)
            this->adjacencyMatrix[i] = new vectorClass[vertices];
    }
    GraphMatrix(){};
    ~GraphMatrix();
    void setAdjacencyMatrix(int vertices)
    {
        //tworzymy tablice
         this->adjacencyMatrix  = new vectorClass *[vertices];
        // tworzymy liczbe kolumn
        for(int i = 0; i < vertices; i++)
            this->adjacencyMatrix[i] = new vectorClass[vertices];
    }
    void addEdge(int vertexSource,int vertexDestination,int weight);
    void removeEdge(int vertexSource, int vertexDestination);
    int getSizeMatrix(int i, int j);
    int getWeightMatrix(int i, int j, int k);
    void fillGraph();
    void printfGraph();
};

#endif