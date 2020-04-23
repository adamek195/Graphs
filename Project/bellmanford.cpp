#include "bellmanford.hpp"

void displayArrayFile(int distanceArray[],int preArray[], int size, int vertexSource)
{
    std::fstream file; //zmienna do ktorej bedziemy zapisywac do pliku
    //otwieramy plik
    file.open("sciezka.txt", std::ios::out|std::ios::app);
    file << "Dla wierzcholka zrodlowego: " << vertexSource << std::endl;
	for(int i = 0; i < size; i++)
    {
		file <<"Do wierzcholka: " << i << "koszt wynosi $" << distanceArray[i] << " " << std::endl;
	}
	file << std::endl;

    // Tworzymy prosty stos
    int* arrayOfVertices = new int[size];
    int ptr = 0;

    for (int i = 0; i < size; i++)
    {
        file << "Dla wierzcholka" <<i << ": najktrotsza droga prowadzi przez wierzcholki: ";
        // Wierzchołki ścieżki umieszczamy na stosie
        for(int x = i; x !=-1 ; x = preArray[x])
            arrayOfVertices[ptr++] = x; // w kolejności od ostatniego do pierwszego

        while(ptr) // Wierzchołki ze stosu drukujemy
        {
            file << arrayOfVertices[--ptr] << " "; // w kolejności od pierwszego do ostatniego
        }
        file << std::endl;
    }
    //zamykamy plik
    file.close(); 
    // Usuwamy stos
    delete[] arrayOfVertices;
}

//algorytm bellmana forda sluzacy do przeszukiwan dla 100 instancji dla list sasiedztwa
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
			    return;
		    }
	    }

    //usuniecie zaalokowanych pamieci
    delete [] distanceArray;
    delete [] preArray;
}

//algorytm bellmana forda sluzacy do zapisu do pliku dla listy sasiedztwa
void bellmanfordListFile(GraphList &graph, int vertexSource)
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
        preArray[i] = -1;
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
			    return;
		    }
	    }

    //zapisanie tablicy do pliku
	displayArrayFile(distanceArray,preArray, totalVertices, vertexSource);

    //usuniecie zaalokowanych pamieci
    delete [] distanceArray;
    delete [] preArray;
}

//algorytm bellmana forda dzialajacy dla 100 instancji macierzy sasiedztwa
void bellmanfordMatrix(GraphMatrix &graph, int vertexSource)
{
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
    for(int h = 1; h <=totalVertices-1; h++)
        for(int i = 0; i < totalVertices; i++)
            for(int j = 0; j < totalVertices; j++)
                for(int k = 0; k < graph.getSizeMatrix(i,j); k++)
                {
                    if (distanceArray[i] != INFINITY && distanceArray[j] > distanceArray[i] + graph.getWeightMatrix(i,j,k))
                    {
                        distanceArray[j] = distanceArray[i] + graph.getWeightMatrix(i,j,k);
                        preArray[j] = i;
                    }
                }

    //jeśli wartość się zmieni, wówczas mamy ujemny cykl na wykresie
    //i nie możemy znaleźć najkrótszych odległości
   for(int i = 0; i < totalVertices; i++)
        for(int j = 0; j < totalVertices; j++)
            for(int k = 0; k < graph.getSizeMatrix(i,j); k++)
            {
		        if((distanceArray[i] != INFINITY) && (distanceArray[j] > distanceArray[i] + graph.getWeightMatrix(i,j,k)))
                {
			        std::cout << "Negatywny cykl zostal wykryty do wierzolka docelowego: " << j << std::endl;
			        return;
		        }
	        }

    //usuniecie zaalokowanych pamieci
    delete [] distanceArray;
    delete [] preArray;                        
}

//algorytm bellmana forda zapisujacy do pliku dla macierzy sasiedztwa
void bellmanfordMatrixFile(GraphMatrix &graph, int vertexSource)
{
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
        preArray[i] = -1;
    }

    //wyznaczamy zrodlowy wierzcholek w tablicy
    distanceArray[vertexSource] = 0; 

    //relaksacja krawedzi
    for(int h = 1; h <=totalVertices-1; h++)
        for(int i = 0; i < totalVertices; i++)
            for(int j = 0; j < totalVertices; j++)
                for(int k = 0; k < graph.getSizeMatrix(i,j); k++)
                {
                    if (distanceArray[i] != INFINITY && distanceArray[j] > distanceArray[i] + graph.getWeightMatrix(i,j,k))
                    {
                        distanceArray[j] = distanceArray[i] + graph.getWeightMatrix(i,j,k);
                        preArray[j] = i;
                    }
                }

    //jeśli wartość się zmieni, wówczas mamy ujemny cykl na wykresie
    //i nie możemy znaleźć najkrótszych odległości
   for(int i = 0; i < totalVertices; i++)
        for(int j = 0; j < totalVertices; j++)
            for(int k = 0; k < graph.getSizeMatrix(i,j); k++)
            {
		        if((distanceArray[i] != INFINITY) && (distanceArray[j] > distanceArray[i] + graph.getWeightMatrix(i,j,k)))
                {
			        std::cout << "Negatywny cykl zostal wykryty do wierzolka docelowego: " << j << std::endl;
			        return;
		        }
	        }

    //zapisanie tablicy do pliku
	displayArrayFile(distanceArray,preArray, totalVertices, vertexSource);

    //usuniecie zaalokowanych pamieci
    delete [] distanceArray;
    delete [] preArray;                    
}