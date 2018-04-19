#include <bits/stdc++.h>

using namespace std;

int rank[25];
vector<int> rk[5];

int fst, snd;

int main()
{
	for (int i = 0; i <= 20; i += 5)
	{
		for (int j = 1; j <= 5; j++)
		{
			cout << i + j << ' ';
			rk[i / 5].push_back(0);
		}
		cout << endl;
		cout.flush();
		for (int j = 1; j <= 5; j++)
		{
			int t;
			cin >> t;
			rk[i / 5][t - 1] = i + j;
		}
	}
	for (int i = 0; i < 5; i++)
		cout << rk[i][0] << ' ';
	cout << endl;
	cout.flush();
	for (int i = 0; i < 5; i++)
	{
		int t;
		cin >> t;
		if (t == 1)
		{
			fst = rk[i][0];
			swap(rk[i][0], rk[i][1]);
		}
		cout << rk[i][0] << ' ';
	}
	cout << endl;
	cout.flush();
	for (int i = 0; i < 5; i++)
	{
		int t;
		cin >> t;
		if (t == 1)
		{
			snd = rk[i][0];
		}
	}
	cout << fst << ' ' << snd << " 0 0 0\n";
	cout << endl;
    return 0;
}
