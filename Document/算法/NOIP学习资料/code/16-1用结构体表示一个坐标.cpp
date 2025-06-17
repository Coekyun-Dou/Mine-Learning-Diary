#include<bits/stdc++.h>
using namespace std;

struct Point{
	int x;
	int y;
};

int main()
{
	Point a;
	a.x = 3;
	a.y = 4;
	cout << a.x << " " << a.y << endl;
	Point* p = new Point();
	p->x = 100;
	p->y = 200;
	cout << p->x << " " << p->y << endl;
	delete p; 
	return 0;
}
