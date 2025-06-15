#include<bits/stdc++.h>
using namespace std;
int main()
{
	const int N = 10; //要输出十行 
	int a[N][N+1];
	for(int i=0;i<N;i++)
	{
		a[i][0] = 1;
		a[i][i] = 1;
		for(int j=1;j<i;j++)
			a[i][j] = a[i-1][j-1] + a[i-1][j];
	}
		
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<=i;j++)
		{
			cout << setw(4) << a[i][j];
		}
		cout << endl;
	}
	
	return 0;
} 
