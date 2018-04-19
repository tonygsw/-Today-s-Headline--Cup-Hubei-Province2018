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
/*
vector<ull> v;

#define MX_PART 100

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
	sort(v.begin(), v.end());
	return v[k];
}
*/

ull get_kth(ull ts0, ll n, ll k)
{
	ull i   = 0x8000000000000000ull;
	ull ans = 0xffffffffffffffffull;
	for (; i; i >>= 1)
	{
		s0 = ts0;
		ull tans = ans - i;
		ll cnt = 0;
		for (ll j = 0; j < n; j++) {
			ull nxt = next_random();
			if (nxt <= tans) cnt++;
		}
		if (cnt >= k) ans -= i;
	}
	return ans;
}

int main()
{
	ll L, n;
	cin >> A >> B >> L >> n >> s0;
	cout << get_kth(s0, n, L) << endl;
	return 0;
}
