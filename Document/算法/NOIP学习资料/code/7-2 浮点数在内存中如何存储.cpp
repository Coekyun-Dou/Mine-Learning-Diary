//���֪��a���ڴ�������ô�洢��
#include<bits/stdc++.h>
using namespace std;
int main()
{
    float a =12345;
    unsigned char* p = (unsigned char*)&a;//ǿ������ת�������⡰�������ؿ���
    
    printf("%02x\n",*p);//ʮ�����Ƶķ�ʽ%02x
    p++;printf("%02x\n",*p);
    p++;printf("%02x\n",*p);
    p++;printf("%02x\n",*p);
    return 0;
}
