#pragma warning(disable : 4819 4244)

#include <boost/config.hpp>
#include <vector>
#include <string>
#include <deque>
#include <iostream>
#include <boost/graph/topological_sort.hpp>
#include <boost/graph/adjacency_list.hpp>
int main5()
{
	using namespace boost;
	using namespace std;

	//建模为图顶点的各对象名称属性
	vector<string> tasks;
	tasks.push_back("从幼儿园接小孩");
	tasks.push_back("买杂货和快餐");
	tasks.push_back("从ATM取现金");
	tasks.push_back("送小孩到足球队");
	tasks.push_back("煮饭");
	tasks.push_back("从足球队接小孩");
	tasks.push_back("吃饭");

	//构造图的边，是对活动依赖关系的建模
	typedef pair < int, int > E;
	E ea[] = { E(0, 3), E(1, 3), E(1, 4), E(2, 1),
		E(3, 5), E(4, 6), E(5, 6) };
	vector<E> edgeV(ea, ea + 7);

	// 选择我们希望用的图类型
	typedef adjacency_list < listS, vecS, directedS > Graph;
	// 生成图对象
	Graph g(edgeV.begin(), edgeV.end(), tasks.size());

	//存储拓扑排序结果的容器，
	//为了便于前端插入，选用deque容器
	deque < int >topo_order;
	topological_sort(g, front_inserter(topo_order),
		vertex_index_map(identity_property_map()));
	//显示排序结果
	for (deque < int >::iterator i = topo_order.begin();
		i != topo_order.end(); ++i)
		cout << tasks[*i] << endl;
	system("pause");
	return EXIT_SUCCESS;
}
