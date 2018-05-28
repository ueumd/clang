#include <stdio.h>.
int main7 () {
    unsigned char ch;

    ch = 0;
    //ascii的验证
    for(ch = 0; ch < 128; ch++) {
        printf("%3d =  %c", ch, ch);
        if((ch+1) % 8 == 0) {
            putchar(10);
        }
    }

    ch = 97;

    printf("ch = %d\n", ch);
    printf("ch = %c\n", ch);

    for(ch = 'a'; ch <= 'z'; ch++) {
        printf("%c\t", ch- ' '); //大写字母 ' ' 空格是32
    }

    return 0;
}
