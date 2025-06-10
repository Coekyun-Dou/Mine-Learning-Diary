#include<bits/stdc++.h>
using namespace std; 
int main()
{
	int a; //没有赋值，但变量还在，内容为空
	short b;
	long c;
	cout << sizeof(a) << " "
	 	 << sizeof(b) << " "
	 	 << sizeof(c) << endl;
	cout << sizeof(int) << endl; //也是可以的，因为不是函数
	return 0;
}
