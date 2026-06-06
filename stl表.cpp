#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[100010];
struct node{
	int l;
	int r;
}ask;
int st[100010][20];
int lg[100010];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	lg[1]=0;
	for(int i=2;i<=n;i++){
		lg[i]=lg[i/2]+1;
	}
	for(int i=1;i<=n;i++){
		st[i][0]=a[i];
	}
	for(int j=1;j<=20;j++){
		for(int i=1;i+(1<<j)-1<=n;i++){
			st[i][j]=max(st[i][j-1],st[i+(1<<(j-1))][j-1]);
		}
	}
	for(int i=1;i<=m;i++){
		scanf("%d%d",&ask.l,&ask.r);
		int len=ask.r-ask.l+1;
		int k=lg[len];
		int ans=max(st[ask.l][k],st[ask.r-(1<<k)+1][k]);
		printf("%d\n",ans);
	}
	return 0;
} 
