/**
typedef typerename 起别名;
typedef int INT;

起别名的好处易跨平台



 typedef #define区别：
 typedef 编译时运行 灵活方便 偏于移植
 #define 预处理阶段
 */

typedef int INT; //是C语言语句
#define INTD int // 没有分号， 宏 , 预处理阶段完成

 // 不同之处
#define CHARPD char *
typedef char *CHARPT;

int main22(){
    /**
     char   short   int     long
     8      16      64      128
     */
   // typedef int INT8;
  //  typedef char INT16;
  //  typedef short INT32;


    INT a;
    printf("sizeof(INT) = %d sizeof(a)=%d\n", sizeof(INT), sizeof(a)); // 4 4

    INTD b;
    printf("sizeof(INTD) = %d sizeof(b)=%d\n", sizeof(INTD), sizeof(b));// 4 4


    // 不同之处
    CHARPD p,q; //陷阱
    printf("sizeof(p) = %d sizeof(q)=%d\n", sizeof(p), sizeof(q)); // 4 1
    /**
        为什么是 4 1 ???  CHARPD p,q; 把CHARPD替换成 CHARPD p,q => char *p,q 这样4 1
     */

    CHARPT x, y;
    printf("sizeof(x) = %d sizeof(y)=%d\n", sizeof(x), sizeof(y)); // 4 4


    return 0;
}
