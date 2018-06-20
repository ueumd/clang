#pragma warning(disable : 4819)

#include <boost/config.hpp> 
#include <iostream>						// for std::cout
#include <boost/graph/adjacency_list.hpp>
using namespace boost;

template < typename VertexDescriptor, typename VertexNameMap >
void print_vertex_name(VertexDescriptor v, VertexNameMap name_map)
//��ӡһ��������������ӳ��Ķ��������
//v��ͼ����Ч�Ķ����������
//name_map����������ӳ��
{
	std::cout << get(name_map, v);
}

template < typename Graph, typename TransDelayMap, typename VertexNameMap >
void print_trans_delay(typename graph_traits < Graph >::edge_descriptor e,
	const Graph & g, TransDelayMap delay_map,
	VertexNameMap name_map)
	//��ӡһ��������������ӳ��Ķ���ͱ��ӳ�����ӳ����ӳ�ֵ
	//e��ͼg����Ч�ı�
	//name_map����������ӳ��
	//delay_map���ӳ�����ӳ��
{
	std::cout << "trans-delay(" << get(name_map, source(e, g)) << ","
		<< get(name_map, target(e, g)) << ") = " << get(delay_map, e);
	//source(e,g)��target(e,g)�����ֱ𷵻�
	//ͼg��e��ʾ�ıߣ�u��v���Ķ���u��v��������
}

template < typename Graph, typename VertexNameMap >
void print_vertex_names(const Graph & g, VertexNameMap name_map)
//��ӡͼ�����ж������������
{
	std::cout << "vertices(g) = { ";
	typedef typename graph_traits < Graph >::vertex_iterator iter_t;
	for (std::pair < iter_t, iter_t > p = vertices(g); p.first != p.second;
		++p.first)
		//vertices(g)���ض�����������䣬����ͼg�����ж���
	{
		print_vertex_name(*p.first, name_map);
		std::cout << ' ';
	}
	std::cout << "}" << std::endl;
}

template < typename Graph, typename TransDelayMap, typename VertexNameMap >
void print_trans_delays(const Graph & g, TransDelayMap trans_delay_map,
	VertexNameMap name_map)
	//��ӡͼ�����бߵ��ӳ�����
{
	typename graph_traits < Graph >::edge_iterator first, last;
	for (tie(first, last) = edges(g); first != last; ++first)
		//edges(g)���رߵ��������䣬����ͼg�����б�
	{
		print_trans_delay(*first, g, trans_delay_map, name_map);
		std::cout << std::endl;
	}
}

template < typename Graph, typename VertexNameMap, typename TransDelayMap >
void build_router_network(Graph & g, VertexNameMap name_map,
	TransDelayMap delay_map)
	// ����·���������ͼģ��
{
	//����5�������ʾ·����
	typename graph_traits < Graph >::vertex_descriptor a, b, c, d, e;
	//���5�����㵽ͼģ���У������ö������������
	a = add_vertex(g);
	name_map[a] = 'a';
	b = add_vertex(g);
	name_map[b] = 'b';
	c = add_vertex(g);
	name_map[c] = 'c';
	d = add_vertex(g);
	name_map[d] = 'd';
	e = add_vertex(g);
	name_map[e] = 'e';

	//����߱�ʾ·����֮�������
	typename graph_traits < Graph >::edge_descriptor ed;
	bool inserted;
	//��Ӷ���֮����Ӧ���ӵ�ͼģ���У������ö������������
	tie(ed, inserted) = add_edge(a, b, g);
	delay_map[ed] = 1.2;
	tie(ed, inserted) = add_edge(a, d, g);
	delay_map[ed] = 4.5;
	tie(ed, inserted) = add_edge(b, d, g);
	delay_map[ed] = 1.8;
	tie(ed, inserted) = add_edge(c, a, g);
	delay_map[ed] = 2.6;
	tie(ed, inserted) = add_edge(c, e, g);
	delay_map[ed] = 5.2;
	tie(ed, inserted) = add_edge(d, c, g);
	delay_map[ed] = 0.4;
	tie(ed, inserted) = add_edge(d, e, g);
	delay_map[ed] = 3.3;
}


int main6()
{
	typedef adjacency_list < listS, listS, directedS,
		property < vertex_name_t, char >,
		property < edge_weight_t, double > > graph_t;
	//����ͼ����graph_t
	graph_t g;
	//����ͼ����g
	property_map < graph_t, vertex_name_t >::type name_map =
		get(vertex_name, g);
	//��������ӳ��name_map����ʼ��
	property_map < graph_t, edge_weight_t >::type delay_map =
		get(edge_weight, g);
	//��������ӳ��delay_map����ʼ��
	build_router_network(g, name_map, delay_map);
	//����·���������ͼģ��g
	//ע�⺯������Ϊ���ô���
	print_vertex_names(g, name_map);
	//��ӡͼg���ж������������
	print_trans_delays(g, delay_map, name_map);
	//��ӡͼg�����бߵ��ӳ�����
	system("pause");
	//���������ͣ�Թ۲�������
	return 0;
}
