#pragma warning(disable : 4819 4244 )

#include <boost/config.hpp>
#include <iostream>
#include <fstream>

#include <boost/graph/graph_traits.hpp>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/dijkstra_shortest_paths.hpp>

using namespace boost;

int main3(int, char *[])
{
	//�����������õ�ͼ����
	typedef adjacency_list < listS, vecS, directedS,
		no_property, property < edge_weight_t, double > > graph_t;

	//�����������
	typedef graph_traits < graph_t >::vertex_descriptor vertex_descriptor;
	typedef graph_traits < graph_t >::edge_descriptor edge_descriptor;
	typedef std::pair<int, int> Edge;

	//����ڵ�ͱߵ���ض��������
	enum nodes { A, B, C, D, E, F, G, H, N };
	char name[] = "ABCDEFGH";
	Edge edge_array[] = { Edge(A, B), Edge(A, C), Edge(B, D), Edge(B, E), Edge(C, E),
		Edge(C, F), Edge(F, G), Edge(G, H), Edge(E, H), Edge(D, E), Edge(D, H) };
	double weights[] = { 5, 1, 1.3, 3, 10, 2, 1.2, 0.5, 1.3, 0.4, 6.3 };
	int num_arcs = sizeof(edge_array) / sizeof(Edge);

	//���ɱ���ģ��ͼ����
	graph_t g(edge_array, edge_array + num_arcs, weights, N);

	//p���ڷ������·���������ĸ�������
	std::vector<vertex_descriptor> p(num_vertices(g));
	//d���ڷ���������Զ��·������
	std::vector<double> d(num_vertices(g));
	//�������·����Դ����
	vertex_descriptor s = vertex(A, g);

	//��ͼg��A����(sΪ����������)Ӧ��dijkstra�㷨
	//��Ϊ����ľ���ʸ��������d�����У�
	//���·�����ϵĸ��ڵ㱣����p������
	dijkstra_shortest_paths(g, s, predecessor_map(&p[0]).distance_map(&d[0]));
	std::cout << "���·����ʱ(ms)" << "\t���·�����ĸ��ڵ�:" << std::endl;
	//����������Ļ
	graph_traits < graph_t >::vertex_iterator vi, vend;
	for (tie(vi, vend) = vertices(g); vi != vend; ++vi) {
		std::cout << "·������(" << name[*vi] << ") = " << d[*vi] << ", \t";
		std::cout << "���ڵ�(" << name[*vi] << ") = " << name[p[*vi]] << std::endl;
	}
	std::cout << std::endl;

	//���沿�ֵĴ������Graphvisͼ�θ�ʽ�ļ���gͼ
	//����Graphvis������g�Ŀ��ӻ���ͼ
	std::ofstream dot_file("figs/dijkstra-demo.dot");
	dot_file << "digraph D {\n"
		<< "  rankdir=LR\n"
		<< "  size=\"4,3\"\n"
		<< "  ratio=\"fill\"\n"
		<< "  edge[style=\"bold\"]\n" << "  node[shape=\"circle\"]\n";

	property_map<graph_t, edge_weight_t>::type weightmap = get(edge_weight, g);
	graph_traits < graph_t >::edge_iterator ei, ei_end;
	for (tie(ei, ei_end) = edges(g); ei != ei_end; ++ei) {
		graph_traits < graph_t >::edge_descriptor e = *ei;
		graph_traits < graph_t >::vertex_descriptor
			u = source(e, g), v = target(e, g);
		dot_file << name[u] << " -> " << name[v]
			<< "[label=\"" << get(weightmap, e) << "ms\"";
		if (p[v] == u)
			dot_file << ", color=\"black\"";
		else
			dot_file << ", color=\"grey\"";
		dot_file << "]";
	}
	dot_file << "}";
	system("pause");
	return EXIT_SUCCESS;
}
