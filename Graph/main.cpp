#include "graph_list.hpp"

int main()
{
    double density;
    int vertices;
    std::cout << "Podaj gestosc grafu: "; 
    std::cin >> density;
    std::cout << std::endl;
    std::cout << "Podaj liczbe wierzcholkow: ";
    std::cin >> vertices;
    GraphList graph(vertices,density);
    std::cout << graph.getDensity() << graph.getE() << graph.getV() << std::endl;
    graph.fillGraph();
    graph.printfGraph();
    graph.cleanMemory();

    return 0;
}
