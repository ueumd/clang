#pragma warning(disable : 4819 4244 )
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/kruskal_min_spanning_tree.hpp>
#include <iostream>
#include <fstream>

int main3()
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

	//��������spanning_tree���ڷ�����С�������ĸ�����
	std::vector < Edge > spanning_tree;

	//��ͼgӦ��kruskal�㷨
	//��Ϊ�������С����������������spanning_tree��
	kruskal_minimum_spanning_tree(g, std::back_inserter(spanning_tree));

	//������
	std::cout << "��ӡ��С��������MST�����б�:" << std::endl;
	for (std::vector < Edge >::iterator ei = spanning_tree.begin();
		ei != spanning_tree.end(); ++ei)
	{
		std::cout << source(*ei, g) << " <--> " << target(*ei, g)
			<< " �ߵ�Ȩ��Ϊ " << weight[*ei]
			<< std::endl;
	}

	std::ofstream fout("figs/kruskal-demo.dot");
	fout << "graph A {\n"
		<< " rankdir=LR\n"
		<< " size=\"5,3\"\n"
		<< " ratio=\"fill\"\n"
		<< " edge[style=\"bold\"]\n" << " node[shape=\"circle\"]\n";
	graph_traits<Graph>::edge_iterator eiter, eiter_end;
	for (tie(eiter, eiter_end) = edges(g); eiter != eiter_end; ++eiter)
	{
		fout << source(*eiter, g) << " -- " << target(*eiter, g);
		if (std::find(spanning_tree.begin(), spanning_tree.end(), *eiter)
			!= spanning_tree.end())
			fout << "[color=\"black\", label=\"" << get(edge_weight, g, *eiter)
			<< "\"];\n";
		else
			fout << "[color=\"gray\", label=\"" << get(edge_weight, g, *eiter)
			<< "\"];\n";
	}
	fout << "}\n";
	system("pause");
	return EXIT_SUCCESS;
}
