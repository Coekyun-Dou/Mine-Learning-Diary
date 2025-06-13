#include<bits/stdc++.h>
using namespace std;
int main()
{
	char s[100];
	cin >> s;
	char* p = s;
	char* q = s;
	while(*q) q++;
	q--;
	while(p<q){
		char t = *p;
		*p = *q;
		*q = t;
		p++;
		q--;
	}	
	cout << s << endl;
	return 0;
} 
