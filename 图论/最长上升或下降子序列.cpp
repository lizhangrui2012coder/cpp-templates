#include <bits/stdc++.h>
using namespace std;
int dp[1010];//以a[i]结尾的最长上升/下降子序列
int ans=0;
int n;
int a[1010];//存储数组
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for (int i=1;i<=n;i++) {
        dp[i]=1;
        for (int j=1;j<i;j++) {//上升
            if (a[j]<a[i]) {//说明a[i]可以a[j]后面
                dp[i]=max(dp[i],dp[j]+1);//既然a[j]后面能接a[i]，
                //那“以j结尾的最长上升子序列”长度再加1,就是一种以i结尾的方案。
            }
        }
        ans = max(ans, dp[i]);
    }
    /*for (int i=1;i<=n;i++) {//下降
        dp[i]=1;
        for(int j=1;j<i;j++) {
            if (a[j]>a[i]) {
                dp[i]=max(dp[i], dp[j] + 1);
            }
        }
        ans=max(ans,dp[i]);
    }*/
   cout<<ans<<endl;
    return 0;
}