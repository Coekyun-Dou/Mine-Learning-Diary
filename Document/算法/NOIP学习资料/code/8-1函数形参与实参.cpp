#include<bits/stdc++.h>
using namespace std;

int f(int x)
{
	x *= 100;
    return x*2;     	
}


int main()
{
	int a = 10;
	int b = f(a);
	cout << b << endl;
	cout << a << endl; //a的值不变：形参的改变不影响实参 
} 

