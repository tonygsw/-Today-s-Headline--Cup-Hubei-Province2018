/*
	data:2018.4.19
	author:gsw
	link:http://arena.whuacm.vo-ov.cn/contest/index.html
	account:team417
*/ 
#include<queue>
#include<math.h>
#include<vector>
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<map>
#include<queue>
using namespace std;
#define maxn 100005
#define ll long long
int Stack[maxn];int dfn[maxn];int low[maxn];
int belong[maxn];bool flag[maxn];int cnt[maxn];int in[maxn];
int depth[maxn];
int top=-1;int cont=1;
int n,m;int num=0;
vector<int> ma[maxn];
vector<int> rema[maxn];
inline void init()
{
    memset(dfn,0,sizeof(dfn));
    memset(low,0,sizeof(low));
    memset(belong,0,sizeof(belong));
    memset(flag,0,sizeof(flag));
    memset(cnt,0,sizeof(cnt));
    memset(in,0,sizeof(in));
    memset(depth,0,sizeof(depth));
    top=-1;cont=1;num=0;
}
void tarjan(int u)
{
    dfn[u]=low[u]=cont++;
    flag[u]=1;Stack[++top]=u;
    for(int i=0;i<ma[u].size();i++)
    {
        int v=ma[u][i];
        if(!dfn[v])
        {
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else if(flag[v])
            low[u]=min(low[u],dfn[v]);
    }
    if(dfn[u]==low[u])
    {
        num++;int x;
        do
        {
            x=Stack[top--];
            flag[x]=0;
            belong[x]=num;
            cnt[num]++;
        }while(x!=u);
    }
    return;
}
int ans()
{
	for(int i=1;i<=n;i++)
		for(int j=0;j<ma[i].size();j++)
		{
			int k=ma[i][j];	
			if(belong[i]!=belong[k])
			{
				rema[belong[i]].push_back(belong[k]);
				in[belong[k]]++;
			}
		}
	queue<int>way;
	for(int i=1;i<=num;i++)
	{
		depth[i]=cnt[i];
		if(!in[i])	way.push(i);
	}
	while(!way.empty())
	{
		int i=way.front();
		way.pop();
		for(int j=0;j<rema[i].size();j++)
		{
			int k=rema[i][j];
			depth[k]=max(depth[k],depth[i]+cnt[k]);
			in[k]--;
			if(!in[k])way.push(k);
		}
	}	//cout<<1<<endl;
	int anx=0;
	for(int i=0;i<=num;i++)
		anx=max(anx,depth[i]);
	return anx;
}
int main()
{
	int a,b;init();
	//freopen("tem.in","r",stdin); 
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&a,&b);
        ma[a].push_back(b);
    }
    for(int i=1;i<=n;i++)
        if(!dfn[i])tarjan(i);

	printf("%d\n",ans());
    return 0;
}
