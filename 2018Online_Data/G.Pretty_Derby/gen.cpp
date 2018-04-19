#include <bits/stdc++.h>
using namespace std;
int main()
{
	int rk[30];
	for (int i = 1; i <= 25; i++)
		rk[i - 1] = i;
	random_device rd;
	for (int i = 0; i < 25; i++)
		swap(rk[i], rk[rd() % (i + 1)]);
	for (int i = 0; i < 25; i++)
		cout << rk[i] << ' ';
	cout << endl;
	return 0;
}
