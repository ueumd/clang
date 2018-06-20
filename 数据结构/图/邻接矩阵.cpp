//FileName:adj_matrix_demo.cpp
//��ʾ�ڽӾ���adjacency_matrix�Ļ���Ӧ��

#pragma warning(disable : 4800 4819)

#include <boost/config.hpp>
#include <iostream>
#include <boost/graph/adjacency_matrix.hpp>
#include <boost/graph/graph_utility.hpp>	
//����print_vertices(), print_edges()��print_graph();


int main1()
{
	using namespace boost;
	enum { A, B, C, D, E, F, N };
	//ö�ٳ�����A��F��������������
	//����ö���������ʣ�N == 6
	const char* name = "ABCDEF";
	//6���������������

	//����ͼ
	typedef adjacency_matrix<directedS> Graph;
	Graph g(N);
	//������N��N=6���������ͼ
	//��ӱߵ�����ͼg��
	add_edge(B, C, g);
	add_edge(B, F, g);
	add_edge(C, A, g);
	add_edge(C, C, g);
	add_edge(D, E, g);
	add_edge(E, D, g);
	add_edge(F, A, g);

	//��ӡͼg���㼯��
	std::cout << "����ͼg�ĸ���Ԫ��: " << std::endl;
	std::cout << "vertex set: ";
	print_vertices(g, name);
	std::cout << std::endl;

	//��ӡͼg�߼���
	std::cout << "edge set: ";
	print_edges(g, name);
	std::cout << std::endl;

	//��ӡ����ͼg���ж���ĳ��߼���
	std::cout << "out-edges: " << std::endl;
	print_graph(g, name);
	std::cout << std::endl;

	// ����ͼ
	typedef adjacency_matrix<undirectedS> UGraph;
	UGraph ug(N);
	add_edge(B, C, ug);
	add_edge(B, F, ug);
	add_edge(C, A, ug);
	add_edge(D, E, ug);
	add_edge(F, A, ug);

	//��ӡͼg���㼯��
	std::cout << "����ͼug�ĸ���Ԫ��: " << std::endl;
	std::cout << "vertex set: ";
	print_vertices(ug, name);
	std::cout << std::endl;

	//��ӡͼg�߼���
	std::cout << "edge set: ";
	print_edges(ug, name);
	std::cout << std::endl;

	//��ӡ����ͼg���ж���Ĺ����߼���
	std::cout << "incident edges: " << std::endl;
	print_graph(ug, name);
	std::cout << std::endl;
	system("pause");
	//���������ͣ�Թ۲�������
	return 0;
}
