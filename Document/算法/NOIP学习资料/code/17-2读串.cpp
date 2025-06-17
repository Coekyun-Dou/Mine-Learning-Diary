#include<bits/stdc++.h>
#include<fstream> 
using namespace std;
int main()
{
	ifstream in("2.txt");
	char buf[100];
	while(in.getline(buf,sizeof(buf))) //读串一般都是用这种方法 
	{
		cout << buf << endl; 
	}
	return 0;
}
