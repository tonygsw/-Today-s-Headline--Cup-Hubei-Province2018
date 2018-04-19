#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000000 + 5;
int rt[maxn], vl[maxn];

int main()
{
    int n;
    char buf[10];
    int x;
    int cur = 0, nd = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%s%d", buf, &x);
        if (buf[1] == 'o') // commit
        {
            rt[i] = nd;
            vl[i] = x ^ vl[i - 1];
        } else { // checkout
            vl[i] = vl[x];
        }
        printf("%d\n", vl[i]);
    }
    return 0;
}