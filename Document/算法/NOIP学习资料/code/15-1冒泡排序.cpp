#include<bits/stdc++.h>
using namespace std;

inline void swap(int*p,int*q) //����swapһֱѹջ��ջ 
{
	int t = *p;
	*p = *q;
	*q = t;
}

void sort(int* buf,int n)
{
	for(int i=0;i<n;i++)
	{
		if(buf[i] > buf[i+1])
		{
			swap(buf+i,buf+i+1);
		}
	}
}

int main()
{
	int n;
	cin >> n;
	int* buf = new int [n];
	for(int i=0;i<n;i++)
	{
		cin >> buf[i];//buf[i]��ʾ��������*(buf+i) 
	}
	for(int i=n-1;i>0;i--)
	{
		sort(buf,i);
	}
	for(int i=0;i<n;i++)
	{
		cout << buf[i] << " ";
	}
	delete [] buf;//�ͷſռ� 
	return 0;
}
