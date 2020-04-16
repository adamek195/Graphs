#include "bellmanford.hpp"

void display(int data[], int size, int vertexSource)
{
    std::cout << "Dla wierzcholka zrodlowego: " << vertexSource << std::endl;
	for(int i = 0; i < size; i++)
    {
		std::cout <<"Do wierzcholka: " << i << "koszt wynosi $" << data[i] << " ";
	}
	std::cout << std::endl;
}


void bellmanfordList(GraphList &graph, int vertexSource)
{
    // zmienna pomocnicza
    listNode* tmpNode;
    //liczba wierzcholkow
    int totalVertices = graph.getV();
    //liczba krawedzi
    int totalEdges = graph.getE();

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
    for(int i = 1; i <= totalVertices - 1; i++) // petla relaksacji
        for(int j = 0; j < totalVertices; j++) //przejscie po wszystich wierzcholkach
            for(tmpNode = graph.getListNode(j); tmpNode; tmpNode=tmpNode->nextNode)
            {
        	    if((distanceArray[tmpNode->vertexSource] != INFINITY) && (distanceArray[tmpNode->vertexDestination] > distanceArray[tmpNode->vertexSource] + tmpNode->weightNode))
        	    {
				    distanceArray[tmpNode->vertexDestination] = distanceArray[tmpNode->vertexSource] + tmpNode->weightNode;
				    preArray[tmpNode->vertexDestination] = tmpNode->vertexSource;
			    }
            }
		
        
    

    //jeśli wartość się zmieni, wówczas mamy ujemny cykl na wykresie
    //i nie możemy znaleźć najkrótszych odległości
   for(int i = 0; i < totalVertices; i++)
        for(tmpNode = graph.getListNode(i); tmpNode; tmpNode=tmpNode->nextNode)
        {
		    if((distanceArray[tmpNode->vertexSource] != INFINITY) && (distanceArray[tmpNode->vertexDestination] > distanceArray[tmpNode->vertexSource] + tmpNode->weightNode))
            {
			    std::cout << "Negatywny cykl zostal wykryty!" << std::endl;
                for(int j=0;j<totalVertices;j++)
                    std::cout << distanceArray[j] << " ";
			    return;
		    }
	    }

    //wyswietlenie tablicy
    std::cout << "Distance array: " << std::endl;
	display(distanceArray, totalVertices,vertexSource);

    //usuniecie zaalokowanych pamieci
    delete [] distanceArray;
    delete [] preArray;
}