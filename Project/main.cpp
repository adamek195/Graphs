#include "graph_list.hpp"
#include "graph_matrix.hpp"
#include "bellmanford.hpp"

int main()
{
    double density;
    int vertices, E;
    int u,v,weight;
    std::cout << "Podaj gestosc grafu: "; 
    std::cin >> density;
    std::cout << density <<std::endl;
    std::cout << "Podaj liczbe wierzcholkow: ";
    std::cin >> vertices;
    std::cout << vertices << std::endl;
    GraphMatrix g(vertices,density);
    g.fillGraph();
    g.printfGraph();
    bellmanfordMatrix(g,0);
    return 0;
}
