#include <bits/stdc++.h>
using namespace std;
const int maxn=500010; 
const int maxm=2000010;
int dfn[maxn];//初次见面时间 
int low[maxn];//能追溯到的最早祖先
int timer=0;//记录时间 
bool is_bridge[maxm];//标记是不是桥 
int bcc_cnt=0;//染色计数器
int bcc [maxn];//记录染色 (点属于哪个分量(分量：极大的连通子图)) 
struct node{
	int to;
	int id;
};
vector<node> g[maxn];
int n,m;
void tarjan(int u,int fa_edge_id){
	dfn[u]=low[u]=++timer;
	for(auto &e:g[u]){
		int v=e.to;
		int id=e.id;
		if(id==fa_edge_id)//跳过父边 
			continue;
		if(!dfn[v]){
			tarjan(v,id);
			low[u]=min(low[u],low[v]);
			if(low[v]>dfn[u]){//变u-v是桥
				is_bridge[id]=true;
			}
		}
		else if(dfn[v]<dfn[u]){
			low[u]=min(low[u],dfn[v]);
		}	
	}
} 
void dfs_colour(int u,int colour){
	bcc[u]=colour;
	for(auto &e:g[u]){
		int v=e.to;
		int id=e.id;
		if(bcc[v]||is_bridge[id]){//跳过已染色或为桥的边 
			continue;
		}
		dfs_colour(v,colour);
	}
}
int main(){ 
 	ios::sync_with_stdio(false);
    cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		g[x].push_back({y,i});
		g[y].push_back({x,i});
	} 
	for(int i=1;i<=n;i++){
		if(!dfn[i])
			tarjan(i,-1);
	}
	for(int i=1;i<=n;i++){
		if(!bcc[i]){
			bcc_cnt++;
			dfs_colour(i,bcc_cnt);
		}
	}
	vector<vector<int> > points(bcc_cnt+1);
	for(int i=1;i<=n;i++){
		points[bcc[i]].push_back(i);
	}
	cout<<bcc_cnt<<'\n';
	for(int i=1;i<=bcc_cnt;i++){
		sort(points[i].begin(),points[i].end());
		cout<<points[i].size();
		for(int x:points[i]){
			cout<<' '<<x;
		}
		cout<<'\n';
	}
	return 0;
} 
