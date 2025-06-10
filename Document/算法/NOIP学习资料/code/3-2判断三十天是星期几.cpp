//题目概述：【例】今天星期五，求30天后是星期几？ 
#include<bits/stdc++.h>
using namespace std; 
int main()
{
	int a = 5;
	int b = (a+30) % 7;//此时的星期表达法，是从0~6的表达法，0表示星期日
	cout << b << endl;
	return 0;
}
