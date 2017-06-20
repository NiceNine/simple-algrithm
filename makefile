FLAGS = -g -std=c++14
HEADERS = bfs.h common.h dfs.h graph.h insert_sort.h merge_sort.h quick_sort.h select_sort.h

main: main.o graph.o
	g++ -o $@ main.o graph.o 

main.o: main.cpp $(HEADERS) 
	g++ -c $(FLAGS) $<

graph.o: graph.cpp graph.h
	g++ -c $(FLAGS) $<
