#include<bits/stdc++.h>
using namespace std;

struct Point{
	int x;
	int y;
};
//struct 也可以写成下面的class：
/*
class Point{
public：              //这里就要加一个public声明，才可以访问到它 
	int x;
	int y; 
};
*/ 

struct Rect{
	Point p1;
	Point p2;
};

int area(const Rect* p) //传递一个指针过来，这样就不用拷贝一份了，可以提高效率
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
