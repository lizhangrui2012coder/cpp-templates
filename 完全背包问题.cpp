#include <bits/stdc++.h>
using namespace std; 
int h,n;
int p[110];
int c[110];
vector<int> dp;
int main(){
	dp.resize(55010,2e9);//长度为h长度的最大值+p[i]的最大值 
	dp[0]=0;
	cin>>n>>h;
	for(int i=1;i<=n;i++){
		cin>>p[i]>>c[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=p[i];j<=55000;j++){
			dp[j]=min(dp[j],dp[j-p[i]]+c[i]);
		}
	}
	int ans=2e9;
	for(int i=h;i<=55000;i++){
		ans=min(ans,dp[i]);
	}
	cout<<ans;
	return 0;
} 
