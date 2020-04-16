#include <iostream>
#include <stdlib.h>

#define INFINITY 99999

//struktura opisujaca krawedz w grfie
struct Edge
{
    int vertexSource; //wierzcholek zrodlowy krawedzi
    int vertexDestination; // wierzcholek docelowy krawedzi
    int weight; // waga krawedzi
};

struct Graph
{
    int vertices; // liczba wierzcholkow
    int edges; // liczba krawedzi
    struct Edge *edgeNext; //tablica krawedzi
};


void display(int data[], int size)
{
	for(int i = 0; i < size; i++)
    {
		std::cout << data[i] << " ";
	}
	std::cout << std::endl;
}

void bellmanford(struct Graph *graph, int vertexSource)
{
    int u,v, weight; // zmienne pomocnicze
    //liczba wierzcholkow
    int totalVertices = graph->vertices;
    //liczba krawedzi
    int totalEdges = graph->edges;

    //tablica dlugosci do wszystkich wierzcholkow od wierzcholka zrodlowego
    int *distanceArray = new int[totalVertices];

    //tablica zapisujaca poprzedni uklad
    int *preArray = new int[totalVertices];

    //wypelniamy tablice zgodnie z algorytmem
    //wszystkie wierzcholki nieskonczonosc i zerujemy tablice pomocnicza
    for (int i = 0; i < totalVertices; i++)
    {
        distanceArray[i] = INFINITY;
        preArray[i] = 0;
    }

    //wyznaczamy zrodlowy wierzcholek w tablicy
    distanceArray[vertexSource] = 0;

    //relaksacja krawedzi
    for(int i = 1; i <= totalVertices - 1; i++)
    {
        for(int j = 0; j < totalEdges; j++)
        {
            //get the edge data
			u = graph->edgeNext[j].vertexSource;
			v = graph->edgeNext[j].vertexDestination;
			weight = graph->edgeNext[j].weight;
        
        	if((distanceArray[u] != INFINITY) && (distanceArray[v] > distanceArray[u] + weight))
        	{
				distanceArray[v] = distanceArray[u] + weight;
				preArray[v] = u;
			}
		}
        
    }

    //jeśli wartość się zmieni, wówczas mamy ujemny cykl na wykresie
    //i nie możemy znaleźć najkrótszych odległości
   for(int i = 0; i < totalEdges; i++)
    {
		u = graph->edgeNext[i].vertexSource;
		v = graph->edgeNext[i].vertexDestination;
		weight = graph->edgeNext[i].weight;
		if(distanceArray[u] != INFINITY && distanceArray[v] > distanceArray[u] + weight)
        {
			std::cout << "Negative weight cycle detected!" << std::endl;
			return;
		}
	}

    //wyswietlenie tablicy
    std::cout << "Distance array: " << std::endl;
	display(distanceArray, totalVertices);
	printf("Predecessor array: ");
	display(preArray, totalVertices);

    //usuniecie zaalokowanych pamieci
    delete [] distanceArray;
    delete [] preArray;
}

int main ()
{
    //create graph
	Graph *g = new Graph;
	g->vertices = 4;	//total vertices
	g->edges = 5;	//total edges
	
	//array of edges for graph
	g->edgeNext = new Edge[g->edges];
	
	
	//edge 0 --> 1
	g->edgeNext[0].vertexSource = 0;
	g->edgeNext[0].vertexDestination = 1;
	g->edgeNext[0].weight = 5;
	
	//edge 0 --> 2
	g->edgeNext[1].vertexSource = 0;
	g->edgeNext[1].vertexDestination = 2;
	g->edgeNext[1].weight = 4;

	//edge 1 --> 3
	g->edgeNext[2].vertexSource = 1;
	g->edgeNext[2].vertexDestination = 3;
	g->edgeNext[2].weight = 3;

	//edge 2 --> 1
	g->edgeNext[3].vertexSource = 2;
	g->edgeNext[3].vertexDestination = 1;
	g->edgeNext[3].weight = 1;

	//edge 3 --> 2
	g->edgeNext[4].vertexSource = 3;
	g->edgeNext[4].vertexDestination = 2;
	g->edgeNext[4].weight = 2;
	
	//0 is the source vertex
	bellmanford(g, 0);

	delete [] g->edgeNext;
	delete g;
	
	return 0;
}