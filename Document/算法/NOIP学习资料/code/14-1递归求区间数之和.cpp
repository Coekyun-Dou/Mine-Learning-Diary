#include<bits/stdc++.h>
using namespace std;

int sum(int a,int b)
{
	if(a>b) return 0;
	return a + sum(a+1,b); //����ǵݹ�ʵ�� 
}
//����sum(1,3) = 1 + sum(2,3) = 1 + 2 + sum(3,3) = 1 + 2 + 3 + sum(4,3) =1+2 +3 

int main()
{
	cout << sum(1,100) << endl;
	return 0; 
}
