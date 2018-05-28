#include <stdio.h>

/**
内存对齐
 */
int main23() {

    char c;         // 1个字节
    char *name;     // 4个字节

    printf("sizeof(c)=%d\n", sizeof(c));
    printf("sizeof(name)=%d\n", sizeof(name));

    return 0;
}
