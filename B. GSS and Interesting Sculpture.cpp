#include<queue>
#include<math.h>
#include<vector>
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
#define ll long long
#define IO ios_base::sync_with_stdio(0);
int R,r,l;
double pi=3.1415926535897932384626433832795;
int main()
{
	while(~scanf("%d%d%d",&R,&r,&l))
	{
		double h1=0,h2=0;
		h1=double(R*R+l*l-r*r)/(double(2*l));
		h2=l-h1;
		h1=R-h1;h2=r-h2;
		double area=2*pi*R*h1+2*pi*r*h2;
		cout<<h1<<" "<<h2<<endl;
		area=double(4*pi*R*R+4*pi*r*r)-area;
		printf("%.8f\n",area);
	}
}
