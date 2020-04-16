#ifndef graph_matrix_hpp
#define graph_matrix_hpp
#include "graph.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>


class GraphMatrix :public Graph
{
    int** adjacencyMatrix; // tablica intow opisujaca macierz sasiedztwa

public:
    GraphMatrix(int vertices, double density) :Graph(vertices, density)
    {
        //tworzymy tablice
        this->adjacencyMatrix = new int* [vertices];
        // tworzymy liczbe kolumn
        for (int i = 0; i < vertices; i++)
            this->adjacencyMatrix[i] = new int[vertices];

        //wypelniamy macierz zerami
        for (int i = 0; i < vertices; i++)
            for (int j = 0; j < vertices; j++)
                this->adjacencyMatrix[i][j] = 0;
    }
    ~GraphMatrix();
    void addEdge(int vertexSource, int vertexDestination);
    void removeEdge(int vertexSource, int vertexDestination);
    void fillGraph();
    void printfGraph();
};

#endif