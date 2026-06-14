#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;
int n,m;
vector<int> g[maxn];//g[u]存u能到达的点
int in_deg[maxn];//in_deg[i]表示点i的入度
vector<int> topo;//记录拓扑序
int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);//建边u->v
        in_deg[v]++;//v多了一个前驱(入度)
    }
    queue<int> q;//维护当前入度为0、可以处理的点
    for(int i=1;i<=n;i++){
        if(in_deg[i]==0)
            q.push(i);
    }
    while(!q.empty()){
        int u=q.front();//取出当前可以处理的点
        q.pop();
        topo.push_back(u);//加入拓扑序
        for(int v:g[u]){
            in_deg[v]--;//删除u->v，相当于v少一个前驱
            if(in_deg[v]==0)q.push(v);//前驱都处理完，v入队
        }
    }
    if((int)topo.size()<n){
        cout<<"有环，不能拓扑排序\n";
    }
    else{
        for(int x:topo)cout<<x<<" ";
    }
    return 0;
}