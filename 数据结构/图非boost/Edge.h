template<typename DistType> struct Edge{
public:
	Edge(int dest, DistType cost) : m_ndest(dest), m_cost(cost), m_pnext(NULL){}

public:
	int m_ndest;
	DistType m_cost;
	Edge<DistType> *m_pnext;

};


