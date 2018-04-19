#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;

int rk[30];

vector<int> getRank(vector<int> who)
{
	vector<int> ret;
	for (int i = 0; i < 5; i++)
	{
		int rank = 1;
		for (int j = 0; j < 5; j++)
			rank += (rk[who[j]] < rk[who[i]] ? 1 : 0);
		ret.push_back(rank);
	}
	return ret;
}

int main(int argc, char *argv[])
{
	setName("Interactor pony");
	registerInteraction(argc, argv);
	for (int i = 1; i <= 25; i++)
		rk[i] = inf.readInt();
	int ans[2];
	int qry = 0;
	while (true)
	{
		vector<int> w;
		for (int i = 0; i < 5; i++)
			w.push_back(ouf.readInt(0, 25));
		if (w[2] == w[3] && w[3] == w[4] && w[4] == 0)
		{
			ans[0] = w[0];
			ans[1] = w[1];
			break;
		}
		vector<int> t = getRank(w);
		for (int i = 0; i < 5; i++)
			cout << t[i] << ' ';
		cout << endl;
		cout.flush();
		qry++;
	}
	if (qry > 7)
		quitf(_wa, "too many quries");
	if (rk[ans[0]] != 1 || rk[ans[1]] != 2)
		quitf(_wa, "wrong answer");
	quitf(_ok, "accepted");
	return 0;
}
