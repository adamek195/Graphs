#ifndef graph_hpp
#define graph_hpp
#include <cstdlib>

//abstakcyjna klasa graf
class Graph
{
    protected:
    int verticesGraph; // liczba wierzcholkow w grafie
    int edgesGraph; //liczba krawedzi w grafie
    double densityGraph; //gestosc grafu

    public:
    int getV() { return verticesGraph;}
    int getE() { return edgesGraph;}
    double getDensity() {return densityGraph;}
    void setVertices(int vertices){ this->verticesGraph = vertices;}
    void setEdges(int vertices,double density){ this->edgesGraph = (density*(vertices-1)*vertices)/2;}
    void setDensity(double density){this->densityGraph = density;}
    Graph(){};
    virtual ~Graph(){};
    Graph(int vertices,double density)
    {
        this->verticesGraph = vertices;
        this->densityGraph = density;
        this->edgesGraph = (density*(vertices-1)*vertices)/2; 
    }
    Graph(int vertices,int edges,double density)
    {
        this->verticesGraph = vertices;
        this->densityGraph = density;
        this->edgesGraph = edges; 
    }
    virtual void fillGraph() = 0;
    virtual void printfGraph() = 0;
};

#endif