//��ʾDFSVisitor�Ķ��ƺ�DFS�㷨��Ӧ��

#pragma warning(disable : 4819 4244)

#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/depth_first_search.hpp>
#include <boost/pending/indirect_cmp.hpp>


#include <iostream>

using namespace boost;
template < typename TimeMap >
class dfs_time_visitor :public default_dfs_visitor
{
	typedef typename property_traits < TimeMap >::value_type T;
public:
	dfs_time_visitor(TimeMap dmap, TimeMap fmap, T & t)
		: m_dtimemap(dmap), m_ftimemap(fmap), m_time(t) { }
	template < typename Vertex, typename Graph >
	void discover_vertex(Vertex u, const Graph & network) const
	{
		put(m_dtimemap, u, m_time++);
	}
	template < typename Vertex, typename Graph >
	void finish_vertex(Vertex u, const Graph & network) const
	{
		put(m_ftimemap, u, m_time++);
	}
	TimeMap m_dtimemap;
	TimeMap m_ftimemap;
	T & m_time;
};


int main7()
{
	//ѡ������ϣ���õ�ͼ����
	typedef adjacency_list < vecS, vecS, directedS > graph_t;
	typedef graph_traits < graph_t >::vertices_size_type size_type;
	//���ö���ID������
	enum{ a, b, c, d, e, f, g, h, i, j, N };
	char name[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j' };
	//ָ��ͼ�����б�
	typedef std::pair < int, int >E;
	E edge_array[] = { E(a, b), E(a, c), E(b, e), E(b, d),
		E(c, f), E(d, e), E(d, g), E(f, g), E(f, h), E(i, j) };
	//����ͼ����
	const int n_edges = sizeof(edge_array) / sizeof(E);
	graph_t network(edge_array, edge_array + n_edges, N);

	//���Ͷ���
	typedef boost::graph_traits < graph_t >::vertex_descriptor Vertex;
	typedef size_type* Iiter;

	//����ʱ��ͽ���ʱ������
	std::vector < size_type > dtime(num_vertices(network));
	std::vector < size_type > ftime(num_vertices(network));
	size_type t = 0;
	dfs_time_visitor < size_type * >vis(&dtime[0], &ftime[0], t);

	depth_first_search(network, visitor(vis));

	//��std::sort�㷨�Զ���������ǵķ���ʱ���������
	std::vector < size_type > discover_order(N);
	integer_range < size_type > r(0, N);
	std::copy(r.begin(), r.end(), discover_order.begin());
	std::sort(discover_order.begin(), discover_order.end(),
		indirect_cmp < Iiter, std::less < size_type > >(&dtime[0]));
	std::cout << "����ķ��ִ���: ";
	for (int i = 0; i < N; ++i)
		std::cout << name[discover_order[i]] << " ";

	//��std::sort�㷨�Զ���������ǵĽ���ʱ���������
	std::vector < size_type > finish_order(N);
	std::copy(r.begin(), r.end(), finish_order.begin());
	std::sort(finish_order.begin(), finish_order.end(),
		indirect_cmp < Iiter, std::less < size_type > >(&ftime[0]));
	std::cout << std::endl << "����Ľ�������: ";
	for (int i = 0; i < N; ++i)
		std::cout << name[finish_order[i]] << " ";
	std::cout << std::endl;
	system("pause");
	return EXIT_SUCCESS;
}
