#include <bits/stdc++.h>
using namespace std;
int n,m,e;
const int N=1005;
vector<int>g[N];//邻接表:g[u]存储左部点u能够连接的所有右部点
int match[N];//match[v]=u,表示右部点v当前匹配的是左部点u
bool vis[N];//vis[v],表示本轮DFS中右部点v是否已经访问过
//尝试给左部点u寻找一个匹配对象
bool find(int u){
	for(int v:g[u]){
		//本轮已经访问过v,避免重复搜索
		if(vis[v])
			continue;
		//标记本轮已经访问
		vis[v]=1;
		//情况1:v没有匹配对象
		//情况2:v原来的主人可以重新找到匹配
		if(match[v]==0||find(match[v])){
			//当前u占据v
			match[v]=u;
			return true;
		}
	}
	//所有能够连接的点都尝试失败
	return false;
}
//left_Cnt:左部点数量
int hungarian(int left_Cnt){
	int ans=0;
	//依次给每个左部点寻找匹配
	for(int u=1;u<=left_Cnt;u++){
		//每次寻找都重新开始访问标记
		memset(vis,0,sizeof(vis));
		//成功匹配
		if(find(u))
			ans++;
	}
	//返回最大匹配数
	return ans;

}
int main(){
    cin>>n>>m>>e;
	for(int i=1;i<=e;i++){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
	}
	cout<<hungarian(n);//括号里填的内容要根据题目而定
    return 0;
}