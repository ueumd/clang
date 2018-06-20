#pragma warning(disable : 4819 4244 )
#include <boost/config.hpp>
#include <iostream>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/prim_minimum_spanning_tree.hpp>

int main2()
{
	using namespace boost;
	//�����������õ�ͼ����
	typedef adjacency_list < vecS, vecS, undirectedS,
		no_property, property < edge_weight_t, int > > Graph;
	//�����������
	typedef graph_traits < Graph >::edge_descriptor Edge;
	typedef graph_traits < Graph >::vertex_descriptor Vertex;
	typedef std::pair<int, int> E;

	//����ڵ�ͱߵ���ض��������
	const int num_nodes = 5;
	E edge_array[] = { E(0, 2), E(1, 3), E(1, 4), E(2, 1),
		E(2, 3), E(3, 4), E(4, 0), E(4, 2) };
	int weights[] = { 1, 1, 2, 7, 3, 1, 1, 1 };
	std::size_t num_edges = sizeof(edge_array) / sizeof(E);
	//���ɱ���ģ��ͼ����
	Graph g(edge_array, edge_array + num_edges, weights, num_nodes);
	property_map < Graph, edge_weight_t >::type weight
		= get(edge_weight, g);

	//��������p���ڷ���ÿ����������С��������ǰ������ӳ������
	std::vector < graph_traits < Graph >::vertex_descriptor >
		p(num_nodes);

	//��ͼgӦ��prim�㷨
	//��Ϊ�������С������������p��
	prim_minimum_spanning_tree(g, &p[0]);

	//������
	for (std::size_t i = 0; i != p.size(); ++i)
		if (p[i] != i)
		{
		std::cout << "parent[" << i << "] = " << p[i] << "\t";
		Edge ed;
		bool existed;
		tie(ed, existed) = edge(i, p[i], g);
		std::cout << " MST����" << p[i] << "<-->" << i
			<< "��Ȩ��Ϊ" << weight[ed] << std::endl;
		}
		else
			std::cout << "����" << i << "ΪMST�����ڵ�" << std::endl;
	system("pause");
	return EXIT_SUCCESS;
}
