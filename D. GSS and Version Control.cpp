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
int n;
int check[2000005];
int main()
{
	IO;
	cin>>n;
	string a;int ch;
	check[0]=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>ch;
		if(a=="commit")
			check[i]=(check[i-1]^ch);
		else
			check[i]=check[ch];
	}
	for(int i=1;i<=n;i++)
		printf("%d\n",check[i]);
}
