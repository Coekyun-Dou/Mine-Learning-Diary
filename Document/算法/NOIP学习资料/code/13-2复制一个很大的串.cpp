#include<bits/stdc++.h>
using namespace std;

bool doubleit(const char* p,char** buf)//开辟大空间一般名字叫buf 传给buf的是一个char* 类型的地址 
{
	if(p==0) return false;//空指针 
	if(*p==0) return false;//空串 
	int n = strlen(p);//对串求长度
	*buf = new char[2*n+1]; //加1是因为串结尾有/0
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
