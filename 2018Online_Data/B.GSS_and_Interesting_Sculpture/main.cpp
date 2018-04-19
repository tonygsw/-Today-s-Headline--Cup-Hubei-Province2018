#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1);
double sqr(double x) {return x * x;}
double calc_area(double t1, double t2)
{
	return cos(t1) - cos(t2);
}

double sol(double r, double R, double L)
{
	double x1 = (sqr(R) - sqr(r) + sqr(L)) / (2 * R * L);
	double x2 = (sqr(r) - sqr(R) + sqr(L)) / (2 * r * L);
	double area1 = x1 + 1;
	double area2 = x2 + 1;
	return 2 * pi * (area1 * sqr(R) + area2 * sqr(r));
}

int main()
{
	int r, R, L;
	while (~scanf("%d%d%d", &r, &R, &L))
		printf("%.12f\n", sol(r, R, L));
	return 0;
}
