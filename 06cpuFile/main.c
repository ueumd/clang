#include<stdio.h>
#include<stdlib.h>//exit在此头文件中
#include<string.h>

int testfopen() {
    FILE *fp = fopen("E:\\demo.txt", "rw"); // e:\\ 另一个斜杠是转义

    if(NULL == fp) {
        printf("\nConnot open file!"); //如果打开不成功则显示不能打开文件
        exit(-1);
    }

    fputs(" hello world", fp); //向文件写入一行字符串
    fputs(" hello world", fp); //向文件写入一行字符串
    fputs(" hello world", fp); //向文件写入一行字符串
    fputs(" hello world", fp); //向文件写入一行字符串
    fputs(" hello world", fp); //向文件写入一行字符串
    fputs(" hello world", fp); //向文件写入一行字符串

    while (!feof(fp)) {
        char buf[100] = {0};
        fgets(buf, sizeof(buf), fp);
        printf("%s", buf); // c language
    }

    fclose(fp); // 关闭这个文件 会有刷新缓冲的功能

    return 0;
}

/**
 * fputc 一次写一个字符
 */
void testfputc(){
    FILE *fp = fopen("fputc.txt","w+");

    for (char ch='a'; ch<='z';ch++){
        printf("%c\n",fputc(ch,fp));
    }

    rewind(fp); // 缓冲区，当前读写指针移动文件开始 ，不然读不出来

#if 0
    // char ret = fgetc(fp);
    // printf("ret=%c\n", ret);
#endif



    char ret;
    while((ret = fgetc(fp)) != EOF){
        printf("ret=%c\n", ret);
    }

    //fclose(fp);

}

//一次读写一行字符
/**
 fgets(buf, len, fp) 最多读len-1个字符，中途遇到“\n” (会被读取) EOF 结束本次读取，读取结束后自动加\0
 */
void testFputcsAndFgetc() {
    FILE *fp = fopen("fputs.txt","w+");
    if(NULL == fp) return -1;

    //  int ft =fputs("hello world", fp);  0表示成功

    printf("ft=%d\n",fputs("aaaa\n", fp));
    printf("ft=%d\n",fputs("bbbb\n", fp));
    printf("ft=%d\n",fputs("cccc\n", fp));
    printf("ft=%d\n",fputs("dddd\n", fp));

    rewind(fp);

    char buf[1024];

    while(fgets(buf, 1024, fp) != NULL){
        printf("buf len=%d ", strlen(buf));
        printf("%s",buf);
    }

    fclose(fp);

#if 0
    fgets(buf, 10, fp); 读了5次
            1234567890abcdefg
            1234567890
            abcdefg

            123456789\0
            0abcdefg\n\0
            123456789\0
            0\n\0
            abcdefg\0
        #endif
}

int main()
{
    //testfopen();
    // testfputc();

    testFputcsAndFgetc();
    return 0;
}
