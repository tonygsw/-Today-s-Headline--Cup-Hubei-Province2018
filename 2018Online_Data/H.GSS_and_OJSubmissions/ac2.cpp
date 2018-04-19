#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;
long long l = 1000000000000000l;
int f[20010];
unsigned long long a,b,s0,temp;
int k,n,tot;
unsigned long long s[10100000];
int main()
{
	cin >> a >> b >> k >> n >> s0;
	temp = s0;
	for (int i = 1;i <= n;i++)
	{
		f[temp/l]++;
		temp = temp * a + b;
	}
	int t = 0;
	for (t = 0;t <= 20000;t++)
		{
			if (f[t] < k)
				k-=f[t];
			else
				break;
		}
	temp = s0;
	for (int i = 1;i <= n;i++)
	{
		if (temp / l == (unsigned long long)t)	s[++tot]=temp;
		temp = temp * a + b;
	}
	sort(s+1,s+1+tot);
	cout << s[k] << endl;
		
	
}