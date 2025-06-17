#include<bits/stdc++.h> 
#include<fstream> 
using namespace std;
int main()
{
	ifstream in("1.txt"); //input file stream的简写 in是一个对象 
	if(!in.is_open()) return 1;
	int x;
	while(!in.eof())//用in.eof()这个成员行数判断是否到尾了
	{
		in >> x;
		if(!in)  break;//判断能不能读成功 注意，这一步不能忽略，不然底下如果有回车的话会重复读最后一个数!! 
		cout << x << endl;
	} 
	return 0; 
}
