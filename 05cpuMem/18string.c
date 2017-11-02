#include <stdio.h>
#include <string.h>

int myStringLen (const char *str) {
    int len = 0;
    while (*str != '\0') { // *str字符串每个字符
        len ++;
        str ++; //地址加1
        printf("%p \n", str);
    }

    return len;
}

//指针函数: C语言允许函数的返回值是一个指针（地址)
char * myStringCopy (char *dest, char *src) {
    char *retDest = dest;
    while ((*dest = *src) != '\0') { // dest和src 末尾都有\0
        dest++;
        src++;
    }

    return retDest; //返回 实际修改了实参的值
}


void isArrAndString () {
    char str[] = "http://c.biancheng.net"; // 字符数组
    printf("str =%s\n", str); //str =http://c.biancheng.net

    char *str2 = "http://c.biancheng.net"; // 字符串常量
    printf("str2 =%s\n", str2); //str2 =http://c.biancheng.net

    str[0] = 'H';
    //  str2[0] = 'H'; 能够正常编译和链接 但是在运行时错误 常量是不能修改的
    printf("str =%s\n", str); //str =Http://c.biancheng.net
    printf("str2 =%s\n", str2); //str2 =http://c.biancheng.net

    /*
    总结：在编程过程中如果只涉及到对字符串的读取，那么字符数组和字符串常量都能够满足要求；
    如果有写入（修改）操作，那么只能使用字符数组，不能使用字符串常量。

    获取用户输入的字符串就是一个典型的写入操作，只能使用字符数组，不能使用字符串常量
    */
    char str3[30];
    gets(str3);
    printf("%s\n", str3);

}

int main18 () {

    char firstName[] = "hello";
    char lastName[] = " world";

    int len = strlen(firstName);
    printf("len = %d\n", len); // 5 \0


    /*
     * char * strcpy ( char * dest, const char * src );
     * 追加src 串到dest的末尾，dest的末尾的‘\0’字符，
     * 会被 src的第一个字符所覆盖，追加完成后的新串会被在其末尾自动追加\0
     */
    strcat(firstName, lastName);
    printf("fistName = %s\n", firstName);  //fistName = hello world

    len = strlen(firstName);
    printf("len = %d\n", len); // 11 \0

    char str[] = "Great Wall";
    int size = myStringLen(str); //str数组首个地址
    printf("size = %d\n", size); // 11 \0


    char dest[100]; char src[100] = "Panda";
    myStringCopy(dest, src);
    printf("dest = %s\n",dest);


    isArrAndString();
    return 0;
}
