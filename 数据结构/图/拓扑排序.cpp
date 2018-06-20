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

	//��ģΪͼ����ĸ�������������
	vector<string> tasks;
	tasks.push_back("���׶�԰��С��");
	tasks.push_back("���ӻ��Ϳ��");
	tasks.push_back("��ATMȡ�ֽ�");
	tasks.push_back("��С���������");
	tasks.push_back("��");
	tasks.push_back("������ӽ�С��");
	tasks.push_back("�Է�");

	//����ͼ�ıߣ��ǶԻ������ϵ�Ľ�ģ
	typedef pair < int, int > E;
	E ea[] = { E(0, 3), E(1, 3), E(1, 4), E(2, 1),
		E(3, 5), E(4, 6), E(5, 6) };
	vector<E> edgeV(ea, ea + 7);

	// ѡ������ϣ���õ�ͼ����
	typedef adjacency_list < listS, vecS, directedS > Graph;
	// ����ͼ����
	Graph g(edgeV.begin(), edgeV.end(), tasks.size());

	//�洢������������������
	//Ϊ�˱���ǰ�˲��룬ѡ��deque����
	deque < int >topo_order;
	topological_sort(g, front_inserter(topo_order),
		vertex_index_map(identity_property_map()));
	//��ʾ������
	for (deque < int >::iterator i = topo_order.begin();
		i != topo_order.end(); ++i)
		cout << tasks[*i] << endl;
	system("pause");
	return EXIT_SUCCESS;
}
