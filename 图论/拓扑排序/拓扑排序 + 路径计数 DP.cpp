#include<bits/stdc++.h>
using namespace std;
const int maxn=5005;
const int mod=80112002;//题目有要求就用，没要求删掉
int n,m;
vector<int> g[maxn];//g[u]存u能到达的点
int in_deg[maxn];//入度
int out_deg[maxn];//出度
int dp[maxn];//dp[i]表示从所有起点出发，走到i的路径条数
int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);//建边u->v
        out_deg[u]++;//u多一条出边
        in_deg[v]++;//v多一个前驱
    }
    queue<int> q;//维护当前入度为0、可以处理的点
    for(int i=1;i<=n;i++){
        if(in_deg[i]==0){
            dp[i]=1;//每个起点本身算1条路径
            q.push(i);
        }
    }
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int v:g[u]){
            dp[v]=(dp[v]+dp[u])%mod;//到u的路径都能接到v
            in_deg[v]--;//u这个前驱处理完了
            if(in_deg[v]==0)
                q.push(v);//v的所有前驱都处理完
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(out_deg[i]==0){//只统计终点
            ans=(ans+dp[i])%mod;
        }
    }
    cout<<ans;
    return 0;
}