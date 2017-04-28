// array length
int arrLength()
{
	int arr[] = { 99, 15, 100, 888, 252 };
	int length = sizeof(arr) / sizeof(int); //5
	int i = 0;
	//printf("arr=%d\n", sizeof(arr));//每个占4个字节 4*5=20
	//printf("int=%d\n", sizeof(int)); //4个字节
	//printf("length=%d\n", length); //5

	for (i; i < length;i++) {
		printf("%d\t", *(arr + i)); // *(arr+i)等价于arr[i]
									//99, 15, 100, 888, 252
	}

	int *p = arr;  //*p指向arr[0]的内存地址 等介于 int *p = &arr[0];
				   //可以看出p指向了数组的开头,那么p+1 指向数组第二个元素 

	printf("\n*p=%d\n", *p);//99

							//指针遍历
	for (i = 0;i < length;i++) {
		printf("%d\t", *(p + i));//99, 15, 100, 888, 252
	}

	printf("\n");

	for (i = 0;i < length;i++) {
		//*p++ 应该理解为 *(p++)
		printf("%d\t", *p++);//99, 15, 100, 888, 252 
	}

	return 0;

}

/*
假设 p 是指向数组 arr 中第 n 个元素的指针，那么 *p++、*++p、(*p)++分别是什么意思呢？
*p++ 等价于 *(p++)，表示先取得第 n 个元素的值，再将 p 指向下一个元素
*++p 等价于 *(++p)，会先进行 ++p 运算，使得 p 的值增加，指向下一个元素，整体上相当于 *(p + 1)，所以会获得第 n + 1 个数组元素的值。
(*p)++就非常简单了，会先取得第 n 个元素的值，再对该元素的值加 1。假设 p 指向第 0  个元素，并且第 0 个元素的值为 99，执行完该语句后，第 0  个元素的值就会变为 100。
*/