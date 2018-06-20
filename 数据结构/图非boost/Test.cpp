#include <iostream>

using namespace std;

#include "Graph.h"

int main(){
	Graph<char *, int> graph, graph2;
	int shotestpath[7];
	char *vertex[] = { "清华", "武大", "华科", "交大", "北大", "地大", "复旦" };
	int edge[][3] = { { 0, 1, 43 }, { 0, 2, 12 }, { 1, 2, 38 }, { 2, 3, 1325 }
	, { 3, 6, 55 }, { 4, 5, 34 }, { 4, 6, 248 } };
	for (int i = 0; i < 7; i++){
		graph.InsertVertex(vertex[i]);
	}
	graph.Print();
	cout << endl << endl << endl;
	for (int i = 0; i < 7; i++){
		graph.InsertEdge(edge[i][0], edge[i][1], edge[i][2]);
		graph.InsertEdge(edge[i][1], edge[i][0], edge[i][2]);
	}
	graph.Print();
	cout << endl << endl << endl;
	graph.Dijkstra(0, shotestpath);
	for (int i = 0; i < 7; i++){
		cout << graph.GetValue(0) << "--->" << graph.GetValue(i)
			<< ":   " << shotestpath[i] << endl;
	}

	cout << endl << endl << endl;
	graph.Prim(graph2);
	cout << endl << endl << endl;
	graph.Removevertex(2);
	graph.Print();
	cin.get();
	return 0;

}
