#include<bits/stdc++.h>
using namespace std;

bool divmod(int a,int b,int* x,int* y)
{
	if(b==0) return false;
	*x = a/b;
	*y = a%b;
	return true; 
}

int main()
{
	int a,b;
	cin >> a >> b;
	int x,y;
	bool t = divmod(a,b,&x,&y);
	if(t)
		cout << x << "," << y;
	else
		cout << "ERROR" << endl;
	return 0;
}
