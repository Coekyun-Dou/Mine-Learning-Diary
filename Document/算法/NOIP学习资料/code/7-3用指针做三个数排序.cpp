#include<bits/stdc++.h>
using namespace std;
int main()
{
	double x,y,z;
	cin >> x >> y >> z;
	double* a = &x;
	double* b = &y;
	double* c = &z;
	if(*a > *b) swap(a,b);
	if(*b > *c) swap(b,c);
	if(*a > *b) swap(a,b);
	
	cout << *a << "," << *b << "," << *c;
	return 0;
}
