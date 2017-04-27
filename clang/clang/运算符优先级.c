#include <stdio.h>
#include <stdlib.h>

int 运main()
{
	int a = 20;
	int b = 10;
	int c = 15;
	int d = 5;
	int e;

	e = (a + b) * c / d;      // ( 30 * 15 ) / 5
	printf("Value of (a + b) * c / d is : %d\n",  e );  //90

	e = ((a + b) * c) / d;    // (30 * 15 ) / 5
	printf("Value of ((a + b) * c) / d is  : %d\n" ,  e ); //90

	e = (a + b) * (c / d);   // (30) * (15/5)
	printf("Value of (a + b) * (c / d) is  : %d\n",  e ); //90

	e = a + (b * c) / d;     //  20 + (150/5)
	printf("Value of a + (b * c) / d is  : %d\n" ,  e );//50

	system("pause");
	return 0;
		
}