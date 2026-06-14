#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;
int n,m;
vector<int> g[maxn];//g[u]存u能到达的点
int in_deg[maxn];//入度
int w[maxn];//点权
int dp[maxn];//dp[i]表示走到i时能获得的最大权值和
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>w[i];
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);//建边u->v
        in_deg[v]++;
    }
    queue<int> q;//维护当前入度为0、可以处理的点
    for(int i=1;i<=n;i++){
        dp[i]=w[i];//每个点都可以作为起点
        if(in_deg[i]==0)
            q.push(i);
    }
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int v:g[u]){
            dp[v]=max(dp[v],dp[u]+w[v]);//先到u再到v是否更优
            in_deg[v]--;//删除u->v
            if(in_deg[v]==0)
                q.push(v);
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        ans=max(ans,dp[i]);//最大路径可能结束在任意点
    }
    cout<<ans;
    return 0;
}