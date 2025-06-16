#include<bits/stdc++.h>
using namespace std;

int strlen(char* p)
{
	if(p==0) return 0;//空指针（指到了最后一个字符\0） 
	if(*p==0) return 0;//空串 
	return 1 + strlen(p+1); 
}

int main()
{
	const char* p = "1234567";
	cout << strlen(p) <<endl;
	return 0;
}
