#include<bits/stdc++.h>
using namespace std;

int f(int x)
{
	x *= 100;
    return x*2;     	
}
//��ʱ������һ������
void g(int* p)
{
	*p = 100;//������仰�����ڸı��βΣ����Ǹı����*p�������β�p 
}


int main()
{
	int a = 10;
	int b = f(a);
	cout << b << endl;
	cout << a << endl; //a��ֵ���䣺�βεĸı䲻Ӱ��ʵ�� 
	
	g(&a);//ʵ����a�ĵ�ַ�������ǲ����ܸı�a�ĵ�ַ�� 
	cout << a << endl;//����a�ͻ�ı�
	
	return 0; 
} 

