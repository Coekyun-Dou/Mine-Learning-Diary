#include<bits/stdc++.h>
using namespace std; 
int main()
{
	char a = 'A';//�ַ�������������ã������ţ����ܰ������֣�������ĸ
	char b = 65;
	int c = a;
	char x = ',';

	cout << a << x << b << x << c << endl;

//��Щ�ַ���ʾ����������Ҫת��
	a = '\t';
	b = '\n';
//ǿ������ת����һ��������ַ�����һ��������ַ���Ӧ������
	cout << a << (int)a << endl;
	cout << b  <<(int)b << endl;
	cout << '\\' << endl; //���ʾ��б�ܱ���
 	return 0;
}
