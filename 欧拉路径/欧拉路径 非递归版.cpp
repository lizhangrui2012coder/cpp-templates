#include <bits/stdc++.h>
using namespace std;
//非递归版本，优化内存 
int n,m;
const int maxn=200010;
vector<int> g[maxn];
int in[maxn];//入度 
int out[maxn];//出度 
vector<int> ans;//结果，先倒着存 
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
	stack<int> st;
	st.push(s);
	while(!st.empty()){
		int u=st.top();//当前点 
		if(!g[u].empty()){
			int v=g[u].back();//取最小的终点 
			g[u].pop_back();//删边，表示已走过 
			st.push(v);//继续往前走 
		}
		else{
			ans.push_back(u);//没变可走，计入答案 
			st.pop();//回退 
		}
	}
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
