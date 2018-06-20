#pragma warning(disable : 4819 4244 )
#include <boost/config.hpp>
#include <iostream>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/prim_minimum_spanning_tree.hpp>

int main2()
{
	using namespace boost;
	//定义我们所用的图类型
	typedef adjacency_list < vecS, vecS, undirectedS,
		no_property, property < edge_weight_t, int > > Graph;
	//定义相关类型
	typedef graph_traits < Graph >::edge_descriptor Edge;
	typedef graph_traits < Graph >::vertex_descriptor Vertex;
	typedef std::pair<int, int> E;

	//定义节点和边的相关对象和属性
	const int num_nodes = 5;
	E edge_array[] = { E(0, 2), E(1, 3), E(1, 4), E(2, 1),
		E(2, 3), E(3, 4), E(4, 0), E(4, 2) };
	int weights[] = { 1, 1, 2, 7, 3, 1, 1, 1 };
	std::size_t num_edges = sizeof(edge_array) / sizeof(E);
	//生成被建模的图对象
	Graph g(edge_array, edge_array + num_edges, weights, num_nodes);
	property_map < Graph, edge_weight_t >::type weight
		= get(edge_weight, g);

	//向量容器p用于放置每个顶点在最小生成树中前驱顶点映射容器
	std::vector < graph_traits < Graph >::vertex_descriptor >
		p(num_nodes);

	//对图g应用prim算法
	//作为结果的最小生成树保存在p中
	prim_minimum_spanning_tree(g, &p[0]);

	//输出结果
	for (std::size_t i = 0; i != p.size(); ++i)
		if (p[i] != i)
		{
		std::cout << "parent[" << i << "] = " << p[i] << "\t";
		Edge ed;
		bool existed;
		tie(ed, existed) = edge(i, p[i], g);
		std::cout << " MST树边" << p[i] << "<-->" << i
			<< "的权重为" << weight[ed] << std::endl;
		}
		else
			std::cout << "顶点" << i << "为MST树根节点" << std::endl;
	system("pause");
	return EXIT_SUCCESS;
}
