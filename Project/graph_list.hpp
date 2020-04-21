#ifndef graph_list_hpp
#define graph_list_hpp
#include "graph.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

//struktura opisujaca wezel laczacy wierzcholki
struct listNode   
{
    int vertexSource; //wierzcholek poczatkowy
    int vertexDestination; // wierzcholek koncowy
    int weightNode; // waga wezla
    listNode* nextNode;
};


class GraphList:public Graph
{
    listNode **adjacencyList;

    public:
    GraphList(int vertices,double density):Graph(vertices,density)
    {
        //tworzymy tablice listy sasiedztwa
        this->adjacencyList = new listNode* [vertices];

        //tablice wypelniamy pustymi miejscami
        for(int i = 0; i < vertices; i++)
            this->adjacencyList[i] = NULL;
    }
    GraphList(){};
    ~GraphList();
    void setAdjacencyList(int vertices)
    {
        //tworzymy tablice listy sasiedztwa
        this->adjacencyList = new listNode* [vertices];

        //tablice wypelniamy pustymi miejscami
        for(int i = 0; i < vertices; i++)
            this->adjacencyList[i] = NULL;
    }
    struct listNode* getListNode(int index){return this->adjacencyList[index];}
    struct listNode* createNode(int vertexSource, int vertexDestination, int weight);
    void addEdge(int vertexSource, int vertexDestination, int weight);
    void fillGraph(); 
	void printfGraph();
    void cleanMemory();
};

#endif