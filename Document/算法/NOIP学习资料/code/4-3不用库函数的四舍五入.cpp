#include<bits/stdc++.h>
using namespace std;
int main()
{
	//û�п⺯���Ļ�����Ҫ��������ʵ����������
	double a = 3.14159;
	double b = (int)(a * 1000 + 0.5)/1000.0;//�Ȱ�a�Ŵ�1000����Ȼ��+0.5�����������������룬���������2.6�Ļ��������0.6�ͻᱻ��ȫ������޷����3��
	cout << b << endl;
	//����round�������������� 
	cout << round(a*1000)/1000.0 << endl;
	return 0;
}
