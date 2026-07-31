#include <bits/stdc++.h>
using namespace std;
const int maxn=100010;
int level[maxn];//bfs到第几层
int cur[maxn];//dfs是当前点枚举到那条边->避免重复搜索
struct Edge{
    int to;
    int rev;
    int cap;
};
vector <Edge> g[maxn];
void addEdge(int u,int v,int cap){// 添加一条容量为 cap 的边 u→v，并自动建立反向边
    int uIndex=g[u].size();// 正向边加入后在 g[u] 中的位置
    int vIndex=g[v].size();// 反向边加入后在 g[v] 中的位置
    // rev 存储的是"对方邻接表中的下标"，因此要记录对方即将插入的位置
    Edge forward={v,vIndex,cap};// 正向边的反向边，将放在 g[v][vIndex]
    Edge backward={u,uIndex,0};// 反向边的反向边，就是 g[u][uIndex]
    g[u].push_back(forward);
    g[v].push_back(backward);
}
int dfs(int u,int T,int flow) {//flow：当前还需要继续尝试发送的量
    if (u == T) {
        return flow;
    }
    int sent=0;//已经送出去的量
    for (int &i=cur[u];i<(int)g[u].size();i++) {
        Edge &e=g[u][i];

        if (e.cap>0&&level[e.to]==level[u]+1) {
            int pushed=dfs(e.to,T,min(flow,e.cap));
            if (pushed>0) {
                e.cap-=pushed;
                g[e.to][e.rev].cap+=pushed;
                sent+=pushed;
                flow-=pushed;
                if(flow==0)
                    break;
            }
        }
    }
    if(sent==0)
        level[u]=-1;
    return sent;
}
bool bfs(int S,int T){
    memset(level,-1,sizeof level);
    queue <int> q;
    q.push(S);
    level[S]=0;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        if(u==T){
            return true;
        }
        for(auto &v:g[u]){
            if(level[v.to]==-1&&v.cap>0){
                level[v.to]=level[u]+1;
                q.push(v.to);
            }
        }
    }
    return false;
}
int main(){
    int S=0,T;
    cin>>T;
    int maxflow=0;
    while(bfs(S,T)){
        memset(cur,0,sizeof cur);
        while(int a=dfs(S,T,1e9)){
            maxflow+=a;
        }
    }
    cout<<maxflow;
    return 0;
}