#include<bits/stdc++.h>
using namespace std; 
int main()
{
	char a = 'A';//字符的字面量表达用：单引号，不能包括汉字，或多个字母
	char b = 65;
	int c = a;
	char x = ',';

	cout << a << x << b << x << c << endl;

//有些字符表示不出来，需要转义
	a = '\t';
	b = '\n';
//强制类型转换，一个是输出字符本身，一个是输出字符对应的整数
	cout << a << (int)a << endl;
	cout << b  <<(int)b << endl;
	cout << '\\' << endl; //这表示反斜杠本身
 	return 0;
}
