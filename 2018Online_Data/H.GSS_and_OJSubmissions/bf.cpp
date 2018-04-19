#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

ull A, B, s0;

inline ull next_random() {
	ull ret = s0;
	s0 = A * s0 + B;
	return ret;
}

vector<ull> v;

#define MX_PART 30

ull divide[MX_PART + 5];
ll cnt[MX_PART + 5];
ll part;

void add_to_part(ull ss) {
	cnt[upper_bound(&divide[0], &divide[MX_PART], ss) - &divide[0] - 1]++;
}

ull get_kth_2(ull ts0, ll n, ll cn, ll k, ull lb, ull ub)
{
	s0 = ts0;
//	cerr << k << " -th in range " << lb << " " << ub << endl;
	v.reserve(cn);
	v.clear();
	for (ll i = 0; i < n; i++) {
		ull t = next_random();
		if (lb <= t && t <= ub) {
			v.push_back(t);
		}
	}
	nth_element(v.begin(), v.begin() + k, v.end());
//	sort(v.begin(), v.end());
	return v[k];
}

ull get_kth(ull ts0, ll n, ll k)
{
	return get_kth_2(ts0, n, n, k, 0, 0xffffffffffffffff);
/*	s0 = ts0;
	if (n < MX_PART) {
		s0 = ts0;
		v.reserve(n);
		v.clear();
		for (int i = 0; i < n; i++)
		{
			v.push_back(next_random());
		}
		sort(v.begin(), v.end());
		return v[k];
	} else 
	{
		s0 = ts0;
//		cerr << k << "-th" << endl;
		divide[0] = 0;
		for (int i = 1; i < MX_PART; i++)
			divide[i] = next_random();
		memset(cnt, 0, sizeof cnt);
		sort(&divide[0], &divide[MX_PART]);
//		for (int i = 0; i < MX_PART; i++)
//			cerr << divide[i] << endl;
		s0 = ts0;
		//--
		for (int i = 0; i < n; i++)
		{
//			if (i % 1000000 == 0)
//				cerr << "add_to_part " << i << endl;
			add_to_part(next_random());
		}
//		for (int i = 0; i < MX_PART; i++)
//			cerr << i << "-th part: " << cnt[i] << "\t\n"[i % 5 == 0];
//		cerr << "\n";
		//--
		for (int i = 0; i < MX_PART; i++)
			if (k < cnt[i])
			{
//				cerr << i << "-th part with " << cnt[i] << " numbers.\n";
				return get_kth_2(ts0, n, cnt[i], k, divide[i], divide[i + 1] - 1);
			}
			else
				k -= cnt[i];
		assert(0);
	}
*/
}

int main()
{
	ll L, n;
	cin >> A >> B >> L >> n >> s0;
	cout << get_kth(s0, n, L - 1) << endl;
	return 0;
}
