all: main.o graph_list.o graph_matrix.o bellmanford.o vector.o
	g++ main.o graph_list.o graph_matrix.o bellmanford.o vector.o -o output
 
main.o: main.cpp
	g++ -c main.cpp
 
graph_list.o: graph_list.cpp
	g++ -c graph_list.cpp

graph_matrix.o: graph_matrix.cpp
	g++ -c graph_matrix.cpp

bellmanford.o: bellmanford.cpp
	g++ -c bellmanford.cpp

vector.o: vector.cpp
	g++ -c vector.cpp