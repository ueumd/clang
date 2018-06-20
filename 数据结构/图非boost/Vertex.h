#include "Edge.h"

template<typename NameType, typename DistType> struct Vertex{
public:
	Vertex() : adj(NULL){}
	NameType m_data;
	Edge<DistType> *adj;
	~Vertex();
};

template<typename NameType, typename DistType> Vertex<NameType, DistType>::~Vertex(){
	Edge<DistType> *pmove = adj;
	while (pmove){
		adj = pmove->m_pnext;
		delete pmove;
		pmove = adj;
	}
}
