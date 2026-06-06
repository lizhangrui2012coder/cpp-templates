#include <bits/stdc++.h>
using namespace std;
const int maxn=500010; 
int dfn[maxn];//初次见面时间 
int low[maxn];//能追溯到的最早祖先
int timer=0;//记录时间 
int bcc_cnt=0;//分量计数器 
int top_idx=0;//数组(假栈)的下标 
int st[maxn];//存一个点(点栈) 未归类的点
      //用普通数组cos栈，减少内存开销 
vector<vector<int> > bcc;
struct node{
	int to;
	int id;
};
vector<node> g[maxn];
void tarjan(int u,int fa_edge_id){
	dfn[u]=low[u]=++timer;
	st[++top_idx]=u;
	int child=0;
	for(auto &e:g[u]){
		int v=e.to;
		int id=e.id;
		if(id==fa_edge_id)//跳过父边 
			continue;
		if(!dfn[v]){
			child++;
			tarjan(v,id);
			low[u]=min(low[u],low[v]);
			if(low[v]>=dfn[u]){//如果死活回不到非父祖先->割点 
				bcc_cnt++;
				vector<int> cur;
				while(true){
					int x=st[top_idx--];
					cur.push_back(x);
					if(x==v)
						break;
				}
				cur.push_back(u);
				bcc.push_back(cur);
			}
		}
		else if(dfn[v]<dfn[u]){
			low[u]=min(low[u],dfn[v]);
		}	
	}
	if(fa_edge_id==-1&&child==0){//是否为孤立点->没有根节点和子节点 
		bcc_cnt++;
		top_idx--;
		vector<int> cur;
		cur.push_back(u);
		bcc.push_back(cur);
	}
} 
int main(){ 
 	ios::sync_with_stdio(false);
    cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		g[x].push_back({y,i});
		g[y].push_back({x,i});
	} 
	fill(dfn,dfn+n+1,0);
    fill(low,low+n+1,0);
    timer=0;
    bcc_cnt=0;
    top_idx=0;
	for(int i=1;i<=n;i++){
		if(!dfn[i])
			tarjan(i,-1);
	}
	
	return 0;
} 
