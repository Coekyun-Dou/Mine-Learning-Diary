#include<bits/stdc++.h>
using namespace std;

struct Point{
	int x;
	int y;
};
//struct Ҳ����д�������class��
/*
class Point{
public��              //�����Ҫ��һ��public�������ſ��Է��ʵ��� 
	int x;
	int y; 
};
*/ 

struct Rect{
	Point p1;
	Point p2;
};

int area(const Rect* p) //����һ��ָ������������Ͳ��ÿ���һ���ˣ��������Ч��
{
	int w = p->p2.x - p->p1.x;
	int h = p->p2.y - p->p1.y;
	return w*h;
} 

int main()
{
	Rect r;
	r.p1.x = 1;
	r.p1.y = 1;
	r.p2.x = 3;
	r.p2.y = 5;
	cout << sizeof(r) << endl; 
	cout << area(&r) <<endl;
	return 0;
} 
