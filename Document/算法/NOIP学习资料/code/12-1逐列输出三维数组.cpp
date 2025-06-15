#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a[3][4];
	int i=0, j=0;
	int n=1;
	do{
		a[i][j] = n++;
		i++;
		if(i==3){
			i=0;
			j++;
		}		
	}while(j<4);
	
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<4;j++)
		{
			cout << setw(3) << a[i][j];//setw(3)就是指定输出宽度为3，这样子相邻两个元素之间就会自动间隔三个字符，不用专门去打出来 
		}
		cout << endl;
	}
	return 0;
} 
