#include<bits/stdc++.h> 
using namespace std;

int main()
{
	//�����Ҫ��һ���ļ�����ȡ�أ� 
	freopen("3.txt","r",stdin);  //������ض�����ֻ���ķ�ʽ���ļ�������standin�������Ӽ�������͹������ļ���
	freopen("out.txt","w",stdout);//������ļ��� 
	
	int c = 0;
	int x;
	while(true){
		cin >> x;  //cin����,ctrl+z��Windows�У�ģ���ļ���������Linux��ctrl+d 
		if(!cin) break;
		c += x; 
	}	
	cout << c << endl;
} 
