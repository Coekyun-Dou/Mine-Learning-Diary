#include<bits/stdc++.h>
using namespace std;
int main()
{
	double a = 1.0;
	double b = 0.1; //用二进制表示就会是一个无限不循环小数，去减的话，会约掉一些东西，所以不会等于0.9
	cout << (a-b == 0.9) << endl; //这个比较不成立  
	cout << (fabs(a-b)-0.9 < 1e-8) <<endl;//fabs：对一个浮点数求绝对值（如果是整数就abs即可）;1e-8表示的是我们计算的一个精度
 	return 0;
 }
  
