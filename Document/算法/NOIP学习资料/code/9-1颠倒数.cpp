#include<bits/stdc++.h>
using namespace std;
int main()
{
	int x;
	cin >> x;
	while(1)
	{
		cout << x % 10;
		x = x/10;//��x��ĩλ˦��
		if(x == 0) break; 
	}	
	return 0;
} 
