#include <stdio.h>

//整形存储
#if 0
/*
 * 大小端考虑的时候，一定要以字节为单位
 * 小，小，小：地址高低，权值高低，小权值放在小地址
 */
int check_sys() {//小端
    int i = 1;
    return (*(char *) &i);
}

int main() {
    if(check_sys() == 1)
        printf("小端\n");
    else{
        printf("大端\n");
    }
    return 0;
}
#endif

#if 0
int main() {
    char a = -1;
    signed char b = -1;
    unsigned char c = -1;

    char d = -128;
    printf("a=%d,b=%d,c=%d,d=%u\n", a, b, c, d);

    int i = -20;
    unsigned j = 10;
    /*
     * 1000 0000 0000 0000 0000 0000 0001 0100--[-20源码]
     * 1111 1111 1111 1111 1111 1111 1110 1011--[-20反码]
     * 1111 1111 1111 1111 1111 1111 1110 1100--[-20补码]
     *
     * 0000 0000 0000 0000 0000 0000 0000 1010--[10源码]
     * ---------------------------------------
     * 1111 1111 1111 1111 1111 1111 1111 0110
     * 1000 0000 0000 0000 0000 0000 0000 1001
     * 1000 0000 0000 0000 0000 0000 0000 1010
     */
    printf("i+j=%d\n", i + j);

//    for (unsigned int i = 9; i >= 0; --i) {
//        printf("%u\n", i);
//    }

//    for (unsigned char i = 0; i <= 255; ++i) {
//        printf("Hello World\n");
//    }

    char e[1000];
    for (int i = 0; i < 1000; ++i) {
        //1111 1111--[-1补码]
        //1111 1111--[-127源码]
        //1000 0001--[-127补码]
        //----------------
        //1 1000 0000
        //1000 0000

        //1111 1111--[-1补码]
        //1000 0000--【128源码]
        //----------
        //1 0111 1111
        //0111 1111

        //1111 1111
        //1000 0001--[129源码]
        //1 1000 0001--【-129源码】
        //1 0111 1110--[-129反码]
        //0111 1111--[-129补码]
        //1 0111 1110
        //0111 1110
        e[i] = -1 - i;//-1~-127[0, 127] 128(res=127) 129(res=126) ... 255(0)
    }

    #include <string.h>
    printf("%d\n", strlen(e));
    return 0;
}
#endif










/*
 * 浮点数存储
 * 存
 * 1.转换为二进制
 * 2.转换为科学计数法
 * 3.提取S，M，E
 * 4.存放S，M，E+127
 *
 * 取
 * 1.取S，M，E-127
 * 2.代入科学计数法
 * 3.转化成二进制
 * 4.数据
 */
int main(){
    int n = 9;
    float *fp = (float *)&n;
    printf("int: %d\n", n);
    //0000 0000 0000 0000 0000 0000 0000 1001
    //0 00000000 00000000000000000001001
    //S  E        M
    printf("float: %f\n", *fp);

    *fp = 9.0;
    //1001.0
    //(-1)S1.001*2^3
    //S=-1, M=1.001, E=3
    //S=-1, M=001, E=130
    //0 10000010 00100000000000000000000
    printf("int: %d\n", n);
    printf("float: %f\n", *fp);
    return 0;
}