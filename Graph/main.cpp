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
    GraphList g(vertices,density);
    std::cout << g.getDensity() << g.getE() << g.getV() << std::endl;
    g.fillGraph();
    /*g.addEdge(0,1,5);
    g.addEdge(0,2,4);
    g.addEdge(1,3,3);
    g.addEdge(2,1,1);
    g.addEdge(3,2,2);
    g.addEdge(0,1,3);*/
    g.printfGraph();
    bellmanfordList(g,0);
    return 0;
}
