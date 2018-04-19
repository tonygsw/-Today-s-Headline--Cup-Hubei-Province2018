	#include <bits/stdc++.h>
	#include <ctime>
	using namespace std;

	const int N = 1e5 + 8;

	int dfn[N], low[N], st[N], belong[N], num[N];
	bool instack[N];
	vector <int> vec[N], eg[N];
	int deg[N], dp[N];
	int n, m;
	int top, cnt, id;
	int tot = 0;
	void init()
	{
		for (int i = 1; i <= n; ++i) vec[i].clear();
		for (int i = 1; i <= m; ++i)
		{
			int u, v; scanf("%d %d", &u, &v);
			vec[u].push_back(v);
		}
	}
	void tarjan(int u)
	{
		dfn[u] = low[u] = ++id;
		instack[u] = true;
		st[++top] = u;
		for (auto v : vec[u])
		{
			if (!dfn[v])
			{
				tarjan(v);
				low[u] = min(low[v], low[u]);
			}
			else if (instack[v])
				low[u] = min(dfn[v], low[u]);
		}
		if (low[u] == dfn[u])
		{
			cnt++;
			int j;
			do
			{
				num[cnt]++;
				j = st[top--];
				instack[j] = false;
				belong[j] = cnt;
			}while (j != u);
		}
	}
	void rebuild()
	{
		top = cnt = id = 0;
		for (int i = 1; i <= n; ++i) instack[i] = dfn[i] = num[i] = 0;
		for (int i = 1; i <= n; ++i)
			if (!dfn[i])
				tarjan(i);
		for (int i = 1; i <= cnt; ++i) eg[i].clear();
		for (int u = 1; u <= n; ++u)
			for (auto v : vec[u])
				if (belong[u] != belong[v])
				eg[belong[u]].push_back(belong[v]);
	}
	void solve()
	{
		static queue <int> Q;
		for (int i = 1; i <= cnt; ++i) dp[i] = deg[i] = 0;
		for (int u = 1; u <= cnt; ++u)
			for (auto v : eg[u])
				deg[v]++;
		for (int i = 1; i <= cnt; ++i) 
			if (deg[i] == 0)
			{
				Q.push(i);
				dp[i] = num[i];
			}
		while (!Q.empty())
		{
			int u = Q.front(); Q.pop();
			for (auto v : eg[u])
			{
				deg[v]--;
				dp[v] = max(dp[v], dp[u] + num[v]);
				if (deg[v] == 0) Q.push(v);
			}
		}
		int ans = 0;
		for (int u = 1; u <= cnt; ++u)
			ans = max(ans, dp[u]);
		cout << ans << endl;
	}
	int main()
	{
		while (~scanf("%d %d", &n, &m))
		{
			init();
			rebuild();
			solve();
		}
		return 0;
	}
