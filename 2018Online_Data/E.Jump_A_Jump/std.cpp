#include <bits/stdc++.h>
#define N 50005
#define MOD 1000000007
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
ll n,m,x,ans,d[N],b[N];
bool done[N];
priority_queue< pii,vector<pii>,greater<pii> > q;
int main()
{
	//freopen("10.in","r",stdin);
	//freopen("10.out","w",stdout);
	ans = 1e16;
    cin.sync_with_stdio(false);
    cin>>n>>m;
    for(int i = 1;i <= m;i++) cin>>b[i];
    sort(b+1,b+1+m);
    memset(d,0x3f,sizeof(d));
    memset(done,0,sizeof(done));
    d[0] = 0;
    q.push(make_pair(d[0],0));
    while(!q.empty())
    {
        int u = q.top().second;
        q.pop();
        if(done[u]) continue;
        done[u] = true;
        for(int i = 1;i <= m;i++)
         if(d[(b[i]+u) % b[1]] > d[u] + b[i])
         {
             d[(b[i]+u) % b[1]] = d[u] + b[i];
             q.push(make_pair(d[(b[i]+u) % b[1]],(b[i]+u) % b[1]));
         }
    }
    ll target = n % b[1];
    for(int i = 0;i < b[1];i++)
    {
	//	cout<<i<<" "<<d[i]<<endl;
		if(d[i] > n) 
		{
			ans = (d[i]-n) < ans ? d[i]-n : ans;
			continue;
		}
		ll Max = max(target,i*1ll),Min = min(target,i*1ll);
		ans = min(ans,min(Max-Min,b[1]-Max+Min));
	}
    cout<<ans<<endl;
}
