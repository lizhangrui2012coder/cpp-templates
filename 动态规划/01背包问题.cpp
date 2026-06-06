#include <bits/stdc++.h>
using namespace std;
int n,m;
int dp[13000];
vector<int> cost;
vector<int> value;
int main(){
	cin>>n>>m;
	cost.resize(n+1);
	value.resize(n+1);
	for(int i=1;i<=n;i++){
		cin>>cost[i]>>value[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=m;j>=0;j--){
			if(j>=cost[i])
				dp[j]=max(dp[j],value[i]+dp[j-cost[i]]);
		}
	}
	cout<<dp[m]; 
	return 0; 
} 
