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
	//定义我们所用的图种类
	typedef adjacency_list < listS, vecS, directedS,
		no_property, property < edge_weight_t, double > > graph_t;

	//定义相关类型
	typedef graph_traits < graph_t >::vertex_descriptor vertex_descriptor;
	typedef graph_traits < graph_t >::edge_descriptor edge_descriptor;
	typedef std::pair<int, int> Edge;

	//定义节点和边的相关对象和属性
	enum nodes { A, B, C, D, E, F, G, H, N };
	char name[] = "ABCDEFGH";
	Edge edge_array[] = { Edge(A, B), Edge(A, C), Edge(B, D), Edge(B, E), Edge(C, E),
		Edge(C, F), Edge(F, G), Edge(G, H), Edge(E, H), Edge(D, E), Edge(D, H) };
	double weights[] = { 5, 1, 1.3, 3, 10, 2, 1.2, 0.5, 1.3, 0.4, 6.3 };
	int num_arcs = sizeof(edge_array) / sizeof(Edge);

	//生成被建模的图对象
	graph_t g(edge_array, edge_array + num_arcs, weights, N);

	//p用于放置最短路径生成树的各个顶点
	std::vector<vertex_descriptor> p(num_vertices(g));
	//d用于放置依近到远的路径距离
	std::vector<double> d(num_vertices(g));
	//待求最短路径的源顶点
	vertex_descriptor s = vertex(A, g);

	//对图g的A顶点(s为它的描述器)应用dijkstra算法
	//作为结果的距离矢量保存在d数组中，
	//最短路径树上的父节点保存在p数组中
	dijkstra_shortest_paths(g, s, predecessor_map(&p[0]).distance_map(&d[0]));
	std::cout << "最短路径延时(ms)" << "\t最短路径树的父节点:" << std::endl;
	//输出结果到屏幕
	graph_traits < graph_t >::vertex_iterator vi, vend;
	for (tie(vi, vend) = vertices(g); vi != vend; ++vi) {
		std::cout << "路径距离(" << name[*vi] << ") = " << d[*vi] << ", \t";
		std::cout << "父节点(" << name[*vi] << ") = " << name[p[*vi]] << std::endl;
	}
	std::cout << std::endl;

	//下面部分的代码输出Graphvis图形格式文件的g图
	//用于Graphvis软件输出g的可视化视图
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
