#include<bits/stdc++.h> //����ͷ
using namespace std;//Ϊ��ʡ�Ա�׼��ĺ����Ͷ���ͷ
int main()
{
    double x;
    cin >> x;
    double a = atan(1.0/x) * 180 /3.1416 ; 
    //atanҪ�õ�<math.h>����<cmath>,���������õ�����ͷ�����Բ��迼��
    //�������*180/3.1416 �����������ֵת�ɽǶȡ�
    cout << a << endl;
    return 0;
    
}
