#include <stdio.h>

/**
 qt可以在项目 运行 command line arguments里设置
 */
int main (int argc, char *argv[]) {

   printf("argc=%d\n", argc); //argc=1

   for(int i=0;i<argc;i++){
       printf("argv[%d] = %s\n", i,argv[i]); //argv[0] = E:\coding\clang\build-05cpuMem-Desktop_Qt_5_9_2_MinGW_32bit-Debug\debug\05cpuMem.exe
   }

   return 0;
}
