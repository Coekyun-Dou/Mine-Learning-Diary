#include<bits/stdc++.h>
using namespace std;

int strlen(char* p)
{
	if(p==0) return 0;//��ָ�루ָ�������һ���ַ�\0�� 
	if(*p==0) return 0;//�մ� 
	return 1 + strlen(p+1); 
}

int main()
{
	const char* p = "1234567";
	cout << strlen(p) <<endl;
	return 0;
}
