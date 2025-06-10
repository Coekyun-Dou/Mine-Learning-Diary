#include<bits/stdc++.h> //万能头
using namespace std;//为了省略标准库的函数和定义头
int main()
{
    double x;
    cin >> x;
    double a = atan(1.0/x) * 180 /3.1416 ; 
    //atan要用到<math.h>或者<cmath>,但是这里用的万能头，可以不予考虑
    //求出来后*180/3.1416 将求出来的数值转成角度。
    cout << a << endl;
    return 0;
    
}
