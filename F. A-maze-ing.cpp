#include<queue>
#include<math.h>
#include<vector>
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;    
const int maxn = 1e5+5;  
vecotr<int>mp[maxn];  
int best, n, num[maxn];  
bool dfs(int *adj, int total, int cnt)  
{  
    int t[maxn], k;  
    if(total == 0)  
    {  
        if(cnt > best)  
        {  
            best = cnt;  
            return true;    //ºÙ÷¶4   
        }  
        return false;  
    }  
    for(int i = 0; i < total; ++i)  
    {  
        if(cnt+total-i <= best) return false;
        if(cnt+num[adj[i]] <= best) return false;
        k = 0;  
        for(int j = i+1; j < total; ++j)  
        if(mp[adj[i]][adj[j]]) t[k++] = adj[j];
        if(dfs(t, k, cnt+1)) return true;  
    }  
    return false;  
}  
int MaximumClique()  
{  
    int adj[maxn], k;  
    best = 0;  
    for(int i = n; i >= 1; --i)  
    {  
        k = 0;  
        for(int j = i+1; j <= n; ++j)  
        if(mp[i][j]) adj[k++] = j;  
        dfs(adj, k, 1);
        num[i] = best;
    }  
    return best;  
}  
int main()  
{  
    while(cin >> n && n)  
    {  
        cout << MaximumClique() << endl;  
    }  
    return 0;  
}  
