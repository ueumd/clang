//����ָ��
int twolevlepointer()
{
	int a = 100;
	int *p1 = &a;
	//����ָ��������**
	int **p2 = &p1;//ָ�����Ҳ��һ�ֱ�����Ҳ��ռ�ô洢�ռ䣬Ҳ����ʹ��&��ȡ���ĵ�ַ

	//p2(&p1)->p1(&a)->a(100)

	//�����ļ�ָ��
	int ***p3 = &p2;
	int ****p4 = &p3;


	//��Ҫ��ȡָ��ָ�������ʱ��һ��ָ���һ��*������ָ�������*������ָ�������*���Դ����ƣ��뿴���룺

	printf("a=%d,*p1=%d,*p2=%d,*p3=%d\n",a,*p1,**p2,***p3);
	printf("&p2=%#x,&p3=%#x\n", &p2, &p3);
	printf("&p1 = %#X, p2 = %#X, *p3 = %#X\n", &p1, p2, *p3);
	printf(" &a = %#X, p1 = %#X, *p2 = %#X, **p3 = %#X\n", &a, p1, *p2, **p3);
	return 0;

}
