#include "graph_list.hpp"
#include "graph_matrix.hpp"

int main()
{
    double density;
    int vertices, E;
    int u, v, weight;
    std::cout << "Podaj gestosc grafu: ";
    std::cin >> density;
    std::cout << density << std::endl;
    std::cout << "Podaj liczbe wierzcholkow: ";
    std::cin >> vertices;
    std::cout << vertices << std::endl;
    GraphList g(vertices, density);
    std::cout << g.getDensity() << g.getE() << g.getV() << std::endl;
    g.fillGraph();
    g.printfGraph();
    E = g.getE();
    return 0;
}
