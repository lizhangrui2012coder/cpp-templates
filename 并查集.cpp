#include<bits/stdc++.h>
using namespace std;
int n,m;
int fa[200010];
int sz[200010];
void init(int t){
	for(int i=1;i<=t;i++){
		fa[i]=i;
		sz[i]=1;
	}
}
int find(int x){
	if(fa[x]==x)
		return x;
	else
	 	return fa[x]=find(fa[x]);
}
void join(int x,int y){
	int rx=find(x);
	int ry=find(y);
	if(rx==ry)
		return;
	if(sz[rx]<sz[ry]){
		fa[rx]=ry;
		sz[ry]+=sz[rx];
	}
	else{
		fa[ry]=rx;
		sz[rx]+=sz[ry];
	}
}
int main(){
	cin>>n>>m;
	init(n);
	for(int i=1;i<=m;i++){
		int z,x,y;
		cin>>z>>x>>y;
		if(z==1)
			join(x,y);
		else if(z==2){
			if(find(x)==find(y))
				cout<<'Y'<<endl;
			else
				cout<<'N'<<endl;
		}
	}
  	return 0;
}
