#include <iostream>
#include <cstdlib>


int main()
{
    int vertices; // liczba wierzcholkow
    int edges;  //liczba krawedzi
    int vertexSource;
    int vertexDestination;
    std::cout << "Podaj liczbe krawedzi: ";
    std::cin >> edges;
    std::cout << std::endl;
    std::cout << "Podaj liczbe wierzcholkow: ";
    std::cin >> vertices;
    //tworzymy wiersze
    int** adjacencyMatrix  = new int *[vertices];
    //tworzymy kolumny dynamicznie
    for(int i = 0; i < vertices; i++)
        adjacencyMatrix[i] = new int[vertices];

    //wypelniamy macierz zerami
    for(int i = 0 ; i < vertices; i++)
        for(int j = 0 ; j < vertices; j++)
            adjacencyMatrix[i][j] = 0;

    //dodajemy krawedzie
    for(int i = 0; i < edges; i++)
    {
        std::cout << "Podaj krawedz zrodlowa: ";
        std::cin >> vertexSource;
        std::cout << std::endl;
        std::cout << "Podaj krawedz docelowa: ";
        std::cin >> vertexDestination;
        std::cout << std::endl;
        adjacencyMatrix[vertexSource][vertexDestination]+=1;
        adjacencyMatrix[vertexDestination][vertexSource]+=1;
    }

    //wypisanie macierzy sasiedztwa
    for(int i = 0; i < vertices; i++)
    {
        for(int j = 0; j < vertices; j++)
            std::cout << adjacencyMatrix[i][j] << " ";
        std:: cout << std::endl;    
    }




    //usuwamy wiersze
    for(int i = 0; i < vertices; i++)
        delete [] adjacencyMatrix[vertices];
    delete adjacencyMatrix[vertices];    


    return 0;
}