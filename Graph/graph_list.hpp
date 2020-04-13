#ifndef graph_list_hpp
#define graph_list_hpp
#include "graph.hpp"

//wezel pomiedzy dwoma wierzchołkami 
struct Node
{
    int data // dana jaka ma wirzcholek
    int weight; // waga krawedzi laczaca poszczegolne wierzcholki
    struct Node* nextNode // adres kolejnego wierzcholka 
};

class GraphList:public Graph
{

    public:
    void fillGraph() const override; 
	void printGraph() const override;

};

#endif