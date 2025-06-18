#include<bits/stdc++.h> 
using namespace std;

int main()
{
	//如果想要打开一个文件来读取呢？ 
	freopen("3.txt","r",stdin);  //这就是重定向，用只读的方式打开文件，关联standin，这样从键盘输入就关联到文件了
	freopen("out.txt","w",stdout);//输出到文件中 
	
	int c = 0;
	int x;
	while(true){
		cin >> x;  //cin结束,ctrl+z（Windows中，模拟文件流结束，Linux是ctrl+d 
		if(!cin) break;
		c += x; 
	}	
	cout << c << endl;
} 
