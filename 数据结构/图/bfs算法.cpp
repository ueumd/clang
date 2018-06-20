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
	// ѡ������ϣ���õ�ͼ����
	typedef adjacency_list < vecS, vecS, undirectedS > graph_t;
	// ���ö���ID������
	enum { a, b, c, d, e, f, g, h, N };


	const char *name = "abcdefgh";
	// ָ��ͼ�����б�
	typedef std::pair < int, int >E;
	E edge_array[] = { E(a, b), E(a, c), E(b, g), E(b, e), E(c, f),
		E(f, d), E(f, h), E(d, g), E(g, e) };




	// ����ͼ����
	const int n_edges = sizeof(edge_array) / sizeof(E);
	typedef graph_traits<graph_t>::vertices_size_type v_size_t;
	graph_t network(edge_array, edge_array + n_edges, v_size_t(N));

	// ���Ͷ���
	typedef graph_traits < graph_t >::vertex_descriptor Vertex;
	typedef graph_traits < graph_t >::vertices_size_type Size;
	typedef Size* Iiter;

	// ���ڷ��ø������㷢��ʱ�����Ե�����
	std::vector < Size > dtime(num_vertices(network));

	Size time = 0;
	bfs_time_visitor < Size * >vis(&dtime[0], time);
	breadth_first_search(network, vertex(d, network), visitor(vis));

	// ��std::sort�㷨�Զ���������ǵķ���ʱ���������
	std::vector<graph_traits<graph_t>::vertices_size_type > discover_order(N);
	integer_range < int >range(0, N);
	//�������䣨0��N�����Զ�������ֵ
	std::copy(range.begin(), range.end(), discover_order.begin());
	std::sort(discover_order.begin(), discover_order.end(),
		indirect_cmp < Iiter, std::less < Size > >(&dtime[0]));
	std::cout << "���㷢�ִ���: ";
	for (int i = 0; i < N; ++i)
		std::cout << name[discover_order[i]] << " ";
	std::cout << std::endl;
	system("pause");
	return EXIT_SUCCESS;
}
