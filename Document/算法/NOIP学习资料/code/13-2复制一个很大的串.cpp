#include<bits/stdc++.h>
using namespace std;

bool doubleit(const char* p,char** buf)//���ٴ�ռ�һ�����ֽ�buf ����buf����һ��char* ���͵ĵ�ַ 
{
	if(p==0) return false;//��ָ�� 
	if(*p==0) return false;//�մ� 
	int n = strlen(p);//�Դ��󳤶�
	*buf = new char[2*n+1]; //��1����Ϊ����β��/0
	memcpy(*buf,p,n);
	memcpy(*buf+n,p,n);
	*(buf+2*n) = 0;//buf[2*n] = 0
	return true; 
	 
} 

int main()
{
	const char* p = "hello noip";
	char* q;
	bool t = doubleit(p,&q);
	cout << q << endl;
	delete q;
	return 0;
}
