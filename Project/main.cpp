#include <chrono>
#include <ratio>
#include <fstream>
#include <cstdlib>
#include "graph_list.hpp"
#include "graph_matrix.hpp"
#include "bellmanford.hpp"
#define SIZE 100

int main()
{
    double density;
    int vertices;
    int edges;
    int vertexSource, vertexDestination, weight;
    int choice_graph = 0;
    std::fstream file; //zmienna plikowa potrzebna do wczytywania danych z pliku
    std::cout << "MENU dla badania czasu algorytmu Bellmana-forda: " << std::endl;
    std::cout << "Jaki rodzaj grafu chcesz zbadac: " << std::endl;
    std::cout << "1. Sto instancji grafu jako lista sasiedztwa " << std::endl;
    std::cout << "2. Sto instancji grafu jako macierz sasiedztwa: " << std::endl;
    std::cout << "3. Wczytaj graf z pliu z zupelnie innymi paramterami jako lista sasiedztwa: " << std::endl;
    std::cout << "4. Wczytaj graf z pliu z zupelnie innymi paramterami jako macierz sasiedztwa: " << std::endl;
    std::cout << "Twoj wybor to: ";
    std::cin >> choice_graph;
    std::cin.ignore(100000,'\n');
    switch(choice_graph)
    {
        case 1:
        {
            //pobieramy parametry grafu
            std::cout << "Podaj ilosc wierzcholkow w grafie: ";
            std::cin >> vertices;
            std::cin.ignore(100000,'\n');
            std::cout << "Podaj gestosc grafu: ";
            std::cin >> density;
            std::cin.ignore(100000,'\n');

            //dynamiczna tablica grafow
            GraphList *graphlist;
            graphlist = new GraphList[SIZE];

            //ustawiamy parametry grafu
            for(int i = 0; i < SIZE; i++)
            {
                graphlist[i].setDensity(density);
                graphlist[i].setEdges(vertices,density);
                graphlist[i].setVertices(vertices);
            }
            
            //ustawiamy dynamicznie liste
            for(int i = 0; i < SIZE; i++)
                graphlist[i].setAdjacencyList(vertices);

            //wypelniamy graf losowymi krawedziami o losowych wierzcholkach
            for(int i = 0; i < SIZE; i++)
                graphlist[i].fillGraph();
            
            //czas przed wyszukaniem najkrotszej drogi
            auto time_start = std::chrono::high_resolution_clock::now();
            for(int i = 0; i < SIZE; i++)
                bellmanfordList(graphlist[i],0);
            auto time_end = std::chrono::high_resolution_clock::now();       

            /*czas trwania zmiennoprzecinkowego*/
            std::chrono::duration<double, std::milli> algorithmTime_ms = time_end - time_start;
 
            // integralny czas trwania: wymaga czasu duration_cast
            auto int_ms = std::chrono::duration_cast<std::chrono::milliseconds>(time_end - time_start);
 
            /* zamiana calkowiego czasu na mniejsza jednostke
            nie potrzebny duration_cast */
            std::chrono::duration<long, std::micro> int_usec = int_ms;

            std::cout << "algorithm took " << algorithmTime_ms.count() << " ms, "
              << "or " << int_ms.count() << " whole milliseconds "
              << "(which is " << int_usec.count() << " whole microseconds)" << std::endl;

              delete[] graphlist;
            break;
        }
        case 2:
        {
            //pobieramy parametry grafu
            std::cout << "Podaj ilosc wierzcholkow grafie: ";
            std::cin >> vertices;
            std::cin.ignore(100000,'\n');
            std::cout << "Podaj gestosc grafu: ";
            std::cin >> density;
            std::cin.ignore(100000,'\n');

            //dynamiczna tablica grafow
            GraphMatrix *graphmatrix;
            graphmatrix = new GraphMatrix[SIZE];

            //ustawiamy parametru grafu
            for(int i = 0; i < SIZE; i++)
            {
                graphmatrix[i].setDensity(density);
                graphmatrix[i].setVertices(vertices);
                graphmatrix[i].setEdges(vertices,density);
            }

            //ustawiamy dynamicznie macierz
            for(int i = 0; i < SIZE; i++)
                graphmatrix[i].setAdjacencyMatrix(vertices);

            //wypelniamy graf losowymi krawedziami o losowych wagach
            for(int i = 0; i < SIZE; i++)
                graphmatrix[i].fillGraph();

            //czas przed wyszukaniem najkrotszej drogi
            auto time_start = std::chrono::high_resolution_clock::now();
            for(int i = 0; i < SIZE; i++)
                bellmanfordMatrix(graphmatrix[i],0);
            auto time_end = std::chrono::high_resolution_clock::now();       

            /*czas trwania zmiennoprzecinkowego*/
            std::chrono::duration<double, std::milli> algorithmTime_ms = time_end - time_start;
 
            // integralny czas trwania: wymaga czasu duration_cast
            auto int_ms = std::chrono::duration_cast<std::chrono::milliseconds>(time_end - time_start);
 
            /* zamiana calkowiego czasu na mniejsza jednostke
            nie potrzebny duration_cast */
            std::chrono::duration<long, std::micro> int_usec = int_ms;

            std::cout << "algorithm took " << algorithmTime_ms.count() << " ms, "
              << "or " << int_ms.count() << " whole milliseconds "
              << "(which is " << int_usec.count() << " whole microseconds)" << std::endl;

              delete[] graphmatrix;    

            break;
        }
        case 3:
        {
            //otwieramy plik
            file.open("dane.txt", std::ios::in);
            //sprawdzamy czy plik istnieje
            if(file.good() == false)
            {
                std::cout << "Plik nie istnieje: ";
                exit(0);
            }
            //odczytujemy z pliku parametry plikow
            file >> edges;
            file >> vertices;
            file >> density; 
            //zamykamy plik
            //tworzymy graf z podanymi parametrami
            GraphList graph(vertices,edges,density);
            //wczytujemy krawedzie
            for (int i = 0 ; i < graph.getE(); i++)
            {
                file >> vertexSource;
                file >> vertexDestination;
                file >> weight;
                graph.addEdge(vertexSource,vertexDestination,weight);
            }
            //zamykamy plik
            file.close();
            graph.printfGraph();
            bellmanfordListFile(graph,0);
            break;
        }
        case 4:
        {
            //otwieramy plik
            file.open("dane.txt", std::ios::in);
            //sprawdzamy czy plik istnieje
            if(file.good() == false)
            {
                std::cout << "Plik nie istnieje: ";
                exit(0);
            }
            //odczytujemy z pliku parametry plikow
            file >> edges;
            file >> vertices;
            file >> density; 
            //zamykamy plik
            //tworzymy graf z podanymi parametrami
            GraphMatrix graph(vertices,edges,density);
            for(int i = 0 ; i < graph.getE(); i++)
            {
                file >> vertexSource;
                file >> vertexDestination;
                file >> weight;
                graph.addEdge(vertexSource,vertexDestination,weight);
            }
            //zamykamy plik
            file.close();
            graph.printfGraph();
            bellmanfordMatrixFile(graph,0);

            break;
        }
        default:
        {
            std::cout << "Nie ma takiej opcji w menu: " << std::endl;
        }
    }

    return 0;
}
