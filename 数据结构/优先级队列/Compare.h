#include <iostream>
using namespace std;

template<typename Type> class Compare{	//处理一般比较大小
public:
	static bool lt(Type item1, Type item2);
};

template<typename Type> bool Compare<Type>::lt(Type item1, Type item2){
	return item1 < item2;
}

struct SpecialData{
	friend ostream& operator<<(ostream&, SpecialData &);
	int m_ntenor;
	int m_npir;
};

ostream& operator<<(ostream& os, SpecialData &out){
	os << out.m_ntenor << "   " << out.m_npir;
	return os;
}

class SpecialCmp{		//处理特殊比较大小,用户可添加适当的类
public:
	static bool lt(SpecialData item1, SpecialData item2);
};

bool SpecialCmp::lt(SpecialData item1, SpecialData item2){
	return item1.m_npir < item2.m_npir;
}

