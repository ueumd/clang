//��ʼ��const��Ա������Ψһ��������ʹ�ó�ʼ����
class ConstVla {
	private:
		const int m_len;
		int *m_arr;
	public:
		ConstVla(int len);	//���캯��
};


//����ʹ�ò�����ʼ��������ʼ�� VLA(int len) : m_len(len)
ConstVla::ConstVla(int len) :m_len(len) {

	// m_len = len;//����
	m_arr = new int[len];
}
