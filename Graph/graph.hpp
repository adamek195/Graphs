#ifndef graph_hpp
#define graph_hpp
#include <cstdlib>

//abstakcyjna klasa graf
class Graph
{
    protected:
    int vertices_V; // liczba wierzcholkow w grafie
    int edges_E; //liczba krawedzi w grafie
    double density; //gestosc grafu

    public:
    int getV() { return vertices_V;}
    int getE() { return edges_E;}
    double getDensity() {return density;}
    virtual void fillGraph();
    virtual void printfGraph();
};

#endif