#pragma warning(disable : 4819)

#include <boost/config.hpp> 
#include <iostream>						// for std::cout
#include <boost/graph/adjacency_list.hpp>
using namespace boost;

template < typename VertexDescriptor, typename VertexNameMap >
void print_vertex_name(VertexDescriptor v, VertexNameMap name_map)
//打印一个给定名称属性映射的顶点的名称
//v是图中有效的顶点的描述器
//name_map是名称属性映射
{
	std::cout << get(name_map, v);
}

template < typename Graph, typename TransDelayMap, typename VertexNameMap >
void print_trans_delay(typename graph_traits < Graph >::edge_descriptor e,
	const Graph & g, TransDelayMap delay_map,
	VertexNameMap name_map)
	//打印一个给定名称属性映射的顶点和边延迟属性映射的延迟值
	//e是图g中有效的边
	//name_map是名称属性映射
	//delay_map是延迟属性映射
{
	std::cout << "trans-delay(" << get(name_map, source(e, g)) << ","
		<< get(name_map, target(e, g)) << ") = " << get(delay_map, e);
	//source(e,g)和target(e,g)函数分别返回
	//图g中e表示的边（u，v）的顶点u和v的描述器
}

template < typename Graph, typename VertexNameMap >
void print_vertex_names(const Graph & g, VertexNameMap name_map)
//打印图中所有顶点的名称属性
{
	std::cout << "vertices(g) = { ";
	typedef typename graph_traits < Graph >::vertex_iterator iter_t;
	for (std::pair < iter_t, iter_t > p = vertices(g); p.first != p.second;
		++p.first)
		//vertices(g)返回顶点迭代器区间，遍历图g的所有顶点
	{
		print_vertex_name(*p.first, name_map);
		std::cout << ' ';
	}
	std::cout << "}" << std::endl;
}

template < typename Graph, typename TransDelayMap, typename VertexNameMap >
void print_trans_delays(const Graph & g, TransDelayMap trans_delay_map,
	VertexNameMap name_map)
	//打印图中所有边的延迟属性
{
	typename graph_traits < Graph >::edge_iterator first, last;
	for (tie(first, last) = edges(g); first != last; ++first)
		//edges(g)返回边迭代器区间，遍历图g的所有边
	{
		print_trans_delay(*first, g, trans_delay_map, name_map);
		std::cout << std::endl;
	}
}

template < typename Graph, typename VertexNameMap, typename TransDelayMap >
void build_router_network(Graph & g, VertexNameMap name_map,
	TransDelayMap delay_map)
	// 构造路由器网络的图模型
{
	//定义5个顶点表示路由器
	typename graph_traits < Graph >::vertex_descriptor a, b, c, d, e;
	//添加5个顶点到图模型中，并设置顶点的名称属性
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

	//定义边表示路由器之间的连接
	typename graph_traits < Graph >::edge_descriptor ed;
	bool inserted;
	//添加顶点之间相应连接到图模型中，并设置顶点的名称属性
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
	//定义图类型graph_t
	graph_t g;
	//定义图对象g
	property_map < graph_t, vertex_name_t >::type name_map =
		get(vertex_name, g);
	//定义属性映射name_map并初始化
	property_map < graph_t, edge_weight_t >::type delay_map =
		get(edge_weight, g);
	//定义属性映射delay_map并初始化
	build_router_network(g, name_map, delay_map);
	//构造路由器网络的图模型g
	//注意函数参数为引用传递
	print_vertex_names(g, name_map);
	//打印图g所有顶点的名称属性
	print_trans_delays(g, delay_map, name_map);
	//打印图g中所有边的延迟属性
	system("pause");
	//输出窗口暂停以观察输出结果
	return 0;
}
