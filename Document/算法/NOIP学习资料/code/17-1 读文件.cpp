#include<bits/stdc++.h> 
#include<fstream> 
using namespace std;
int main()
{
	ifstream in("1.txt"); //input file stream�ļ�д in��һ������ 
	if(!in.is_open()) return 1;
	int x;
	while(!in.eof())//��in.eof()�����Ա�����ж��Ƿ�β��
	{
		in >> x;
		if(!in)  break;//�ж��ܲ��ܶ��ɹ� ע�⣬��һ�����ܺ��ԣ���Ȼ��������лس��Ļ����ظ������һ����!! 
		cout << x << endl;
	} 
	return 0; 
}
