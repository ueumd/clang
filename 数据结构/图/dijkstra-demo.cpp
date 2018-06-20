
#pragma warning(disable : 4819 4244 )

#include <boost/config.hpp>
#include <vector>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/bellman_ford_shortest_paths.hpp>

using namespace boost;

int main4()
{
	//����ڵ�ͱߵ���ض��������
	enum { u, v, x, y, z, N };
	char name[] = { 'u', 'v', 'x', 'y', 'z' };
	typedef std::pair < int, int >E;
	E edge_array[] = { E(u, y), E(u, x), E(u, v), E(v, u),
		E(x, y), E(x, v), E(y, v), E(y, z), E(z, u), E(z, x) };
	int weights[] = { -4, 8, 5, -2, 9, -3, 7, 2, 6, 7 };
	int num_arcs = sizeof(edge_array) / sizeof(E);

	//�����������õ�ͼ������������
	typedef adjacency_list < vecS, vecS, directedS,
		no_property, property < edge_weight_t, int > > Graph;
	//����ͼ����
	Graph g(edge_array, edge_array + num_arcs, weights, N);
	graph_traits < Graph >::edge_iterator ei, ei_end;

	//distance���ڷ���������Զ��·������
	std::vector<int> distance(N, (std::numeric_limits < short >::max)());
	//parent���ڷ������·���������ĸ�������
	std::vector<std::size_t> parent(N);
	for (int i = 0; i < N; ++i)
		parent[i] = i;


	//��Դ��z��Ӧ������Ϊ0
	distance[z] = 0;
	//Ӧ��Bellman-Ford�㷨
	bool r = bellman_ford_shortest_paths
		(g, int(N), weight_map(get(edge_weight, g)).distance_map(&distance[0]).
		predecessor_map(&parent[0]));

	if (r)
	{
		std::cout << "Դ��z����������·��\n";
		std::cout << "Ŀ�ĵ�\t" << "���·��\t" << "���·�����ĸ��ڵ�:\n";
		for (int i = 0; i < N; ++i)
			std::cout << name[i] << ": \t" << distance[i]
			<< "\t\t" << name[parent[i]] << std::endl;
	}
	else
		std::cout << "negative cycle" << std::endl;

	std::ofstream dot_file("figs/bellman-demo.dot");
	dot_file << "digraph D {\n"
		<< "  rankdir=LR\n"
		<< "  size=\"5,3\"\n"
		<< "  ratio=\"fill\"\n"
		<< "  edge[style=\"bold\"]\n" << "  node[shape=\"circle\"]\n";

	for (tie(ei, ei_end) = edges(g); ei != ei_end; ++ei)
	{
		graph_traits < Graph >::edge_descriptor e = *ei;
		graph_traits < Graph >::vertex_descriptor
			u = source(e, g), v = target(e, g);
		dot_file << name[u] << " -> " << name[v]
			<< "[label=\"" << get(get(edge_weight, g), e) << "\"";
		if (parent[v] == u)
			dot_file << ", color=\"black\"";
		else
			dot_file << ", color=\"grey\"";
		dot_file << "]";
	}
	dot_file << "}";
	system("pause");
	return EXIT_SUCCESS;
}
