#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b)
{
	if(b==0) return a;
	return gcd(b, a%b);
}

int main()
{
	int a,b;
	cin >> a >> b;
	cout << gcd(a,b) << endl; //最大公约数 
	cout << a*b/gcd(a,b)<<endl;//最小公倍数 
	return 0;
}
