//如何知道a在内存中是怎么存储的
#include<bits/stdc++.h>
using namespace std;
int main()
{
    float a =12345;
    unsigned char* p = (unsigned char*)&a;//强制类型转换，故意“歪曲”地看待
    
    printf("%02x\n",*p);//十六进制的方式%02x
    p++;printf("%02x\n",*p);
    p++;printf("%02x\n",*p);
    p++;printf("%02x\n",*p);
    return 0;
}
