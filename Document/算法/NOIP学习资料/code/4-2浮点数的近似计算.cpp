#include<bits/stdc++.h>
using namespace std;
int main()
{
	double a = 1.0;
	double b = 0.1; //�ö����Ʊ�ʾ�ͻ���һ�����޲�ѭ��С����ȥ���Ļ�����Լ��һЩ���������Բ������0.9
	cout << (a-b == 0.9) << endl; //����Ƚϲ�����  
	cout << (fabs(a-b)-0.9 < 1e-8) <<endl;//fabs����һ�������������ֵ�������������abs���ɣ�;1e-8��ʾ�������Ǽ����һ������
 	return 0;
 }
  
