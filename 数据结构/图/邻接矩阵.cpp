//FileName:adj_matrix_demo.cpp
//演示邻接矩阵adjacency_matrix的基本应用

#pragma warning(disable : 4800 4819)

#include <boost/config.hpp>
#include <iostream>
#include <boost/graph/adjacency_matrix.hpp>
#include <boost/graph/graph_utility.hpp>	
//用于print_vertices(), print_edges()和print_graph();


int main1()
{
	using namespace boost;
	enum { A, B, C, D, E, F, N };
	//枚举常量，A…F用作顶点描述器
	//根据枚举量的性质，N == 6
	const char* name = "ABCDEF";
	//6个顶点的名称属性

	//有向图
	typedef adjacency_matrix<directedS> Graph;
	Graph g(N);
	//构造有N（N=6）个顶点的图
	//添加边到无向图g中
	add_edge(B, C, g);
	add_edge(B, F, g);
	add_edge(C, A, g);
	add_edge(C, C, g);
	add_edge(D, E, g);
	add_edge(E, D, g);
	add_edge(F, A, g);

	//打印图g顶点集合
	std::cout << "有向图g的各种元素: " << std::endl;
	std::cout << "vertex set: ";
	print_vertices(g, name);
	std::cout << std::endl;

	//打印图g边集合
	std::cout << "edge set: ";
	print_edges(g, name);
	std::cout << std::endl;

	//打印有向图g所有顶点的出边集合
	std::cout << "out-edges: " << std::endl;
	print_graph(g, name);
	std::cout << std::endl;

	// 无向图
	typedef adjacency_matrix<undirectedS> UGraph;
	UGraph ug(N);
	add_edge(B, C, ug);
	add_edge(B, F, ug);
	add_edge(C, A, ug);
	add_edge(D, E, ug);
	add_edge(F, A, ug);

	//打印图g顶点集合
	std::cout << "无向图ug的各种元素: " << std::endl;
	std::cout << "vertex set: ";
	print_vertices(ug, name);
	std::cout << std::endl;

	//打印图g边集合
	std::cout << "edge set: ";
	print_edges(ug, name);
	std::cout << std::endl;

	//打印无向图g所有顶点的关联边集合
	std::cout << "incident edges: " << std::endl;
	print_graph(ug, name);
	std::cout << std::endl;
	system("pause");
	//输出窗口暂停以观察输出结果
	return 0;
}
