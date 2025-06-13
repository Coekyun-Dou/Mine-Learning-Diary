#include<bits/stdc++.h>
using namespace std;

int f(int x)
{
	x *= 100;
    return x*2;     	
}
//有时候会产生一个假象
void g(int* p)
{
	*p = 100;//但是这句话不是在改变形参，我们改变的是*p而不是形参p 
}


int main()
{
	int a = 10;
	int b = f(a);
	cout << b << endl;
	cout << a << endl; //a的值不变：形参的改变不影响实参 
	
	g(&a);//实参是a的地址，我们是不可能改变a的地址的 
	cout << a << endl;//这样a就会改变
	
	return 0; 
} 

