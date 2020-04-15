all: main.o graph_list.o graph_matrix.o
	g++ main.o graph_list.o graph_matrix.o -o output
 
main.o: main.cpp
	g++ -c main.cpp
 
graph_list.o: graph_list.cpp
	g++ -c graph_list.cpp

graph_matrix.o: graph_matrix.cpp
	g++ -c graph_matrix.cpp