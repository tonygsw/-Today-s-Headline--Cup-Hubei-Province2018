#include <bits/stdc++.h>
using namespace std;
int main()
{
	random_device rd;
	for (int i = 0; i < 1000; i++)
	{
		while (true)
		{
			int r = rd() % 100 + 1;
			int R = rd() % 100 + 1;
			int L = rd() % 100 + 1;
			if (r > R) swap(r, R);
			if (L > r + R || R > L + r || r > L + R) continue;
			int tr = rd() % 2;
			if (tr) swap(r, R);
			printf("%d %d %d\n", r, R, L);
			break;
		}
	}
	return 0;
}
