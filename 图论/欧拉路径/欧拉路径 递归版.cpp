#include <bits/stdc++.h>
using namespace std;
//递归版本，内存可能会炸 
int n,m;
const int maxn=200010;
vector<int> g[maxn];
int in[maxn];//入度 
int out[maxn];//出度 
vector<int> ans;//结果，先倒着存 
void dfs(int u){
	//只要有边没走过，就继续走 
	while(!g[u].empty()){
		int v=g[u].back();//当前最小的点 
		g[u].pop_back();//便用了->删掉 
		dfs(v);
	}
	//无边可走时->应加在答案后面 
	ans.push_back(u);
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		g[x].push_back(y);
		out[x]++;
		in[y]++;
	}
	int s=-1;//起点 
	int cnt1=0,cnt2=0;//入度和出度计数器 
	for(int i=1;i<=n;i++){
		//做起点 
		if(out[i]==in[i]+1){
			cnt1++;
			s=i;
		}
		//做终点 
		else if(in[i]==out[i]+1){
			cnt2++;
		}
		else if(in[i]!=out[i]){
			cout<<"No";
			return 0;
		}
	}
	if(!((cnt1==1&&cnt2==1)||(cnt1==0&&cnt2==0))){
		cout<<"No";
		return 0;
	}
	if(cnt1==0){
		for(int i=1;i<=n;i++){
			if(out[i]>0){
				s=i;
				break;
			}
		}
	}
	for(int i=1;i<=n;i++){
		sort(g[i].begin(),g[i].end(),greater<int>());
	}
	//如果一条边都没有，随便输出一个点 
	if(m==0){
		cout<<1;
		return 0;
	}
	dfs(s);
	//翻转过来 
	reverse(ans.begin(),ans.end());
	if(ans.size()!=m+1){
		cout<<"No";
		return 0;
	}
	for(int x:ans)
		cout<<x<<' ';
	return 0;
} 
