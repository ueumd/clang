//初始化const成员变量的唯一方法就是使用初始化表
class ConstVla {
	private:
		const int m_len;
		int *m_arr;
	public:
		ConstVla(int len);	//构造函数
};


//必须使用参数初始化表来初始化 VLA(int len) : m_len(len)
ConstVla::ConstVla(int len) :m_len(len) {

	// m_len = len;//错误
	m_arr = new int[len];
}
