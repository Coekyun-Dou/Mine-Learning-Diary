#include<bits/stdc++.h>
using namespace std;
int main()
{
	//没有库函数的话，需要靠这样来实现四舍五入
	double a = 3.14159;
	double b = (int)(a * 1000 + 0.5)/1000.0;//先把a放大1000倍，然后+0.5（这样才能四舍五入，否则如果是2.6的话，后面的0.6就会被完全舍掉，无法变成3了
	cout << b << endl;
	//用了round函数来四舍五入 
	cout << round(a*1000)/1000.0 << endl;
	return 0;
}
