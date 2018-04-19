#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;
long long pow_mod(long long a, long long b)
{
    long long ret = 1;
    while (b)
    {
        if (b & 1) {
            ret = ret * a % mod;
        }
        a = a * a % mod;
        b >>= 1;
    }
    return ret;
}

int main()
{
    long long n;
    while (cin >> n)
    {
        long long ret = n * (n - 1) % mod;
        ret = ret * pow_mod(4, mod - 2) % mod;
        cout << ret << "\n";
    }
    return 0;
}