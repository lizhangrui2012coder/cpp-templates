#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > mp;
vector<vector<int> > vis;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int n,m;
int end_x,end_y;
void dfs(int x,int y){
	if(x==end_x&&y==end_y){
		return;
	}
	for(int i=0;i<4;i++){
		int nx=dx[i]+x;
		int ny=dy[i]+y;
		if(mp[nx][ny]!=1&&nx>=1&&ny>=1&&nx<=n&&ny<=m&&!vis[nx][ny]){
			vis[nx][ny]=1;
			dfs(nx,ny);
			vis[nx][ny]=0;
		}
	}
}
int main(){
	cin>>n>>m;
	mp.resize(n+1,vector<int>(m+1,0));
	vis.resize(n+1,vector<int>(m+1,0));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>mp[i][j];
		}
	}
	cin>>end_x>>end_y;
	vis[1][1]=1;
	dfs(1,1);
	return 0;
} 
