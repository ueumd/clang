#include "Vertex.h"

template<typename NameType, typename DistType> class Graph{
public:
	Graph(int size = m_nDefaultSize);   //create the Graph with the most vertex of size
	~Graph();
	bool GraphEmpty() const{    //Is empty?
		return 0 == m_nnumvertex;
	}
	bool GraphFull() const{     //Is full?
		return m_nMaxNum == m_nnumvertex;
	}
	int NumberOfVertex() const{ //get the number of vertex
		return m_nnumvertex;
	}
	int NumberOfEdge() const{   //get the number of edge
		return m_nnumedges;
	}
	NameType GetValue(int v);   //get the value of the vth vertex
	DistType GetWeight(int v1, int v2); //get the weight between v1 and v2
	int GetFirst(int v);        //get the first neighbor vertex of v
	int GetNext(int v1, int v2);//get the next neighbor vertex of v1 behind v2
	bool InsertVertex(const NameType vertex);   //insert vertex with the name of vertex
	bool Removevertex(int v);   //remove the vth vertex

	//insert the edge between v1 and v2
	bool InsertEdge(int v1, int v2, DistType weight = m_Infinity);

	bool RemoveEdge(int v1, int v2);    //delete the edge between v1 and v2
	void Print();   //print the graph

	Edge<DistType> *GetMin(int v, int *visited);    //get the min weight of the neighbor vertex of v
	void Prim(Graph<NameType, DistType> &graph);    //get the minimize span tree
	void DFS(int v, int *visited);      //depth first search
	void DFS();
	void Dijkstra(int v, DistType *shotestpath);    //get the min weight from v to other vertex

private:
	Vertex<NameType, DistType> *m_pnodetable;   //neighbor list
	int m_nnumvertex;
	const int m_nMaxNum;
	static const int m_nDefaultSize = 10;       //the default maximize vertex
	static const DistType m_Infinity = 100000;  //there is no edge
	int m_nnumedges;
	int Getvertexpos(const NameType vertex);    //get the vertex's position with the name of vertex
};


template<typename NameType, typename DistType> Graph<NameType, DistType>::Graph(int size)
	: m_nnumvertex(0), m_nMaxNum(size), m_nnumedges(0){
	m_pnodetable = new Vertex<NameType, DistType>[size];
}

template<typename NameType, typename DistType> Graph<NameType, DistType>::~Graph(){
	Edge<DistType> *pmove;
	for (int i = 0; i < this->m_nnumvertex; i++){
		pmove = this->m_pnodetable[i].adj;
		if (pmove){
			this->m_pnodetable[i].adj = pmove->m_pnext;
			delete pmove;
			pmove = this->m_pnodetable[i].adj;
		}
	}
	delete[] m_pnodetable;
}

template<typename NameType, typename DistType> int Graph<NameType, DistType>::GetFirst(int v){
	if (v < 0 || v >= this->m_nnumvertex){
		return -1;
	}
	Edge<DistType> *ptemp = this->m_pnodetable[v].adj;
	return m_pnodetable[v].adj ? m_pnodetable[v].adj->m_ndest : -1;
}

template<typename NameType, typename DistType> int Graph<NameType, DistType>::GetNext(int v1, int v2){
	if (-1 != v1){
		Edge<DistType> *pmove = this->m_pnodetable[v1].adj;
		while (NULL != pmove->m_pnext){
			if (pmove->m_ndest == v2){
				return pmove->m_pnext->m_ndest;
			}
			pmove = pmove->m_pnext;
		}
	}
	return -1;
}

template<typename NameType, typename DistType> NameType Graph<NameType, DistType>::GetValue(int v){
	if (v < 0 || v >= this->m_nnumvertex){
		cerr << "The vertex is not exsit" << endl;
		exit(1);
	}
	return m_pnodetable[v].m_data;

}

template<typename NameType, typename DistType> int Graph<NameType, DistType>::Getvertexpos(const NameType vertex){
	for (int i = 0; i < this->m_nnumvertex; i++){
		if (vertex == m_pnodetable[i].m_data){
			return i;
		}
	}
	return -1;
}

template<typename NameType, typename DistType> DistType Graph<NameType, DistType>::GetWeight(int v1, int v2){
	if (v1 >= 0 && v1 < this->m_nnumvertex && v2 >= 0 && v2 < this->m_nnumvertex){
		if (v1 == v2){
			return 0;
		}
		Edge<DistType> *pmove = m_pnodetable[v1].adj;
		while (pmove){
			if (pmove->m_ndest == v2){
				return pmove->m_cost;
			}
			pmove = pmove->m_pnext;
		}
	}
	return m_Infinity;
}

template<typename NameType, typename DistType> bool Graph<NameType, DistType>::InsertEdge(int v1, int v2, DistType weight){
	if (v1 >= 0 && v1 < this->m_nnumvertex && v2 >= 0 && v2 < this->m_nnumvertex){
		Edge<DistType> *pmove = m_pnodetable[v1].adj;
		if (NULL == pmove){ //the first neighbor
			m_pnodetable[v1].adj = new Edge<DistType>(v2, weight);
			return 1;
		}
		while (pmove->m_pnext){
			if (pmove->m_ndest == v2){
				break;
			}
			pmove = pmove->m_pnext;
		}
		if (pmove->m_ndest == v2){  //if the edge is exist, change the weight
			pmove->m_cost = weight;
			return 1;
		}
		else{
			pmove->m_pnext = new Edge<DistType>(v2, weight);
			return 1;
		}
	}
	return 0;
}
template<typename NameType, typename DistType> bool Graph<NameType, DistType>::InsertVertex(const NameType vertex){
	int i = this->Getvertexpos(vertex);
	if (-1 != i){
		this->m_pnodetable[i].m_data = vertex;
	}
	else{
		if (!this->GraphFull()){
			this->m_pnodetable[this->m_nnumvertex].m_data = vertex;
			this->m_nnumvertex++;
		}
		else{
			cerr << "The Graph is Full" << endl;
			return 0;
		}
	}
	return 1;
}
template<typename NameType, typename DistType> bool Graph<NameType, DistType>::RemoveEdge(int v1, int v2){
	if (v1 >= 0 && v1 < this->m_nnumvertex && v2 >= 0 && v2 < this->m_nnumvertex){
		Edge<DistType> *pmove = this->m_pnodetable[v1].adj, *pdel;
		if (NULL == pmove){
			cerr << "the edge is not exist!" << endl;
			return 0;
		}
		if (pmove->m_ndest == v2){  //the first neighbor
			this->m_pnodetable[v1].adj = pmove->m_pnext;
			delete pmove;
			return 1;
		}
		while (pmove->m_pnext){
			if (pmove->m_pnext->m_ndest == v2){
				pdel = pmove->m_pnext;
				pmove->m_pnext = pdel->m_pnext;
				delete pdel;
				return 1;
			}
			pmove = pmove->m_pnext;
		}
	}
	cerr << "the edge is not exist!" << endl;
	return 0;
}
template<typename NameType, typename DistType> bool Graph<NameType, DistType>::Removevertex(int v){
	if (v < 0 || v >= this->m_nnumvertex){
		cerr << "the vertex is not exist!" << endl;
		return 0;
	}
	Edge<DistType> *pmove, *pdel;
	for (int i = 0; i < this->m_nnumvertex; i++){
		pmove = this->m_pnodetable[i].adj;
		if (i != v){    //delete the edge point to v
			if (NULL == pmove){
				continue;
			}
			if (pmove->m_ndest == v){
				this->m_pnodetable[i].adj = pmove->m_pnext;
				delete pmove;
				continue;
			}
			else {
				if (pmove->m_ndest > v){    //the vertex more than v subtract 1
					pmove->m_ndest--;
				}
			}
			while (pmove->m_pnext){
				if (pmove->m_pnext->m_ndest == v){
					pdel = pmove->m_pnext;
					pmove->m_pnext = pdel->m_pnext;
					delete pdel;
				}
				else {
					if (pmove->m_pnext->m_ndest > v){
						pmove->m_pnext->m_ndest--;
						pmove = pmove->m_pnext;
					}
				}
			}
		}
		else {      //delete the edge point from v
			while (pmove){
				this->m_pnodetable[i].adj = pmove->m_pnext;
				delete pmove;
				pmove = this->m_pnodetable[i].adj;
			}
		}
	}
	this->m_nnumvertex--;
	for (int i = v; i < this->m_nnumvertex; i++)    //delete the vertex
	{
		this->m_pnodetable[i].adj = this->m_pnodetable[i + 1].adj;
		this->m_pnodetable[i].m_data = this->m_pnodetable[i + 1].m_data;
	}
	this->m_pnodetable[this->m_nnumvertex].adj = NULL;
	return 1;
}

template<typename NameType, typename DistType> void Graph<NameType, DistType>::Print(){
	Edge<DistType> *pmove;
	for (int i = 0; i < this->m_nnumvertex; i++){
		cout << this->m_pnodetable[i].m_data << "--->";
		pmove = this->m_pnodetable[i].adj;
		while (pmove){
			cout << pmove->m_cost << "--->" << this->m_pnodetable[pmove->m_ndest].m_data << "--->";
			pmove = pmove->m_pnext;
		}
		cout << "NULL" << endl;
	}
}

template<typename NameType, typename DistType> void Graph<NameType, DistType>::Prim(Graph<NameType, DistType> &graph){
	int *node = new int[this->m_nnumvertex];    //using for store the vertex visited
	int *visited = new int[this->m_nnumvertex];
	int count = 0;
	Edge<DistType> *ptemp, *ptemp2 = new Edge<DistType>(0, this->m_Infinity), *pmin;
	int min;
	for (int i = 0; i < this->m_nnumvertex; i++){
		graph.InsertVertex(this->m_pnodetable[i].m_data);
		node[i] = 0;
		visited[i] = 0;
	}
	visited[0] = 1;
	while (++count < this->m_nnumvertex){
		pmin = ptemp2;
		pmin->m_cost = this->m_Infinity;

		//get the minimize weight between the vertex visited and the  vertex which is not visited
		for (int i = 0; i<count; i++){
			ptemp = GetMin(node[i], visited);
			if (NULL == ptemp){
				continue;
			}
			if (pmin->m_cost > ptemp->m_cost){
				pmin = ptemp;
				min = node[i];
			}
		}

		node[count] = pmin->m_ndest;
		visited[node[count]] = 1;
		graph.InsertEdge(pmin->m_ndest, min, pmin->m_cost);
		graph.InsertEdge(min, pmin->m_ndest, pmin->m_cost);
	}
	graph.DFS();
	delete ptemp2;
	delete[] node;
	delete[] visited;
}

template<typename NameType, typename DistType> void Graph<NameType, DistType>::DFS(int v, int *visited){
	cout << "--->" << this->GetValue(v);
	visited[v] = 1;
	int weight = this->GetFirst(v);
	while (-1 != weight){
		if (!visited[weight]){
			cout << "--->" << this->GetWeight(v, weight);
			DFS(weight, visited);
		}
		weight = this->GetNext(v, weight);
	}
}

template<typename NameType, typename DistType> void Graph<NameType, DistType>::DFS(){
	int *visited = new int[this->m_nnumvertex];
	for (int i = 0; i < this->m_nnumvertex; i++){
		visited[i] = 0;
	}
	cout << "head";
	DFS(0, visited);
	cout << "--->end";
}

template<typename NameType, typename DistType> Edge<DistType>* Graph<NameType, DistType>::GetMin(int v, int *visited){
	Edge<DistType> *pmove = this->m_pnodetable[v].adj, *ptemp = new Edge<DistType>(0, this->m_Infinity), *pmin = ptemp;
	while (pmove){
		if (!visited[pmove->m_ndest] && pmin->m_cost > pmove->m_cost){
			pmin = pmove;
		}
		pmove = pmove->m_pnext;
	}
	if (pmin == ptemp){
		delete ptemp;
		return NULL;
	}
	delete ptemp;
	return pmin;
}
template<typename NameType, typename DistType> void Graph<NameType, DistType>::Dijkstra(int v, DistType *shotestpath){
	int *visited = new int[this->m_nnumvertex];
	int *node = new int[this->m_nnumvertex];
	for (int i = 0; i < this->m_nnumvertex; i++){
		visited[i] = 0;
		node[i] = 0;
		shotestpath[i] = this->GetWeight(v, i);
	}
	visited[v] = 1;
	for (int i = 1; i < this->m_nnumvertex; i++){
		DistType min = this->m_Infinity;
		int u = v;

		for (int j = 0; j < this->m_nnumvertex; j++){   //get the minimize weight
			if (!visited[j] && shotestpath[j] < min){
				min = shotestpath[j];
				u = j;
			}
		}

		visited[u] = 1;
		for (int w = 0; w < this->m_nnumvertex; w++){   //change the weight from v to other vertex
			DistType weight = this->GetWeight(u, w);
			if (!visited[w] && weight != this->m_Infinity
				&& shotestpath[u] + weight < shotestpath[w]){
				shotestpath[w] = shotestpath[u] + weight;
			}
		}
	}
	delete[] visited;
	delete[] node;
}

