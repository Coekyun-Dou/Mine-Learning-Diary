#include<bits/stdc++.h>
#include<fstream> 
using namespace std;
int main()
{
	ifstream in("2.txt");
	char buf[100];
	while(in.getline(buf,sizeof(buf))) //����һ�㶼�������ַ��� 
	{
		cout << buf << endl; 
	}
	return 0;
}
