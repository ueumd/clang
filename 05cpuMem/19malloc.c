#include <stdio.h>
#include <stdlib.h>
int main19 () {
#if 0
    int a[1024*1024] // 挂掉
#endif

    int a; int *pa= &a;
    *pa = 100;
    printf("a=%d\n", a);

    // malloc free 配套使用 realloc
    int *p = (int *)malloc(sizeof(int)); //开辟空间
    if(NULL == p) { //不建议p==NULL 这种写法，这样写如果手误成p=NULL也是可以通过的。但是NULL=p 编译时就会报措 常量是不可以更改的
        printf("malloc error\n");
        return -1;
    }
    *p =200;
    printf("*p= %d\n", *p);

    free(p); //释放空间

    return 0;
}
