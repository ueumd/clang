#pragma warning(disable : 4819 4244 4267)

#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/breadth_first_search.hpp>


#include <boost/pending/indirect_cmp.hpp>
#include <iostream>

using namespace boost;
template < typename TimeMap >
class bfs_time_visitor :public default_bfs_visitor
{
	typedef typename property_traits < TimeMap >::value_type T;
public:
	bfs_time_visitor(TimeMap tmap, T & t) :m_timemap(tmap), m_time(t) { }
	template < typename Vertex, typename Graph >
	void discover_vertex(Vertex u, const Graph & network) const
	{
		put(m_timemap, u, m_time++);
	}
	TimeMap m_timemap;
	T & m_time;
};


int main()
{
	using namespace boost;
	// 选择我们希望用的图类型
	typedef adjacency_list < vecS, vecS, undirectedS > graph_t;
	// 设置顶点ID和名称
	enum { a, b, c, d, e, f, g, h, N };


	const char *name = "abcdefgh";
	// 指定图的所有边
	typedef std::pair < int, int >E;
	E edge_array[] = { E(a, b), E(a, c), E(b, g), E(b, e), E(c, f),
		E(f, d), E(f, h), E(d, g), E(g, e) };




	// 生成图对象
	const int n_edges = sizeof(edge_array) / sizeof(E);
	typedef graph_traits<graph_t>::vertices_size_type v_size_t;
	graph_t network(edge_array, edge_array + n_edges, v_size_t(N));

	// 类型定义
	typedef graph_traits < graph_t >::vertex_descriptor Vertex;
	typedef graph_traits < graph_t >::vertices_size_type Size;
	typedef Size* Iiter;

	// 用于放置各个顶点发现时间属性的向量
	std::vector < Size > dtime(num_vertices(network));

	Size time = 0;
	bfs_time_visitor < Size * >vis(&dtime[0], time);
	breadth_first_search(network, vertex(d, network), visitor(vis));

	// 用std::sort算法对顶点根据他们的发现时间进行排序
	std::vector<graph_traits<graph_t>::vertices_size_type > discover_order(N);
	integer_range < int >range(0, N);
	//整数区间（0，N）用以对向量填值
	std::copy(range.begin(), range.end(), discover_order.begin());
	std::sort(discover_order.begin(), discover_order.end(),
		indirect_cmp < Iiter, std::less < Size > >(&dtime[0]));
	std::cout << "顶点发现次序: ";
	for (int i = 0; i < N; ++i)
		std::cout << name[discover_order[i]] << " ";
	std::cout << std::endl;
	system("pause");
	return EXIT_SUCCESS;
}
