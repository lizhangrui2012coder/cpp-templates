#include <bits/stdc++.h>

using namespace std;

struct node{
    int v,w; 
};

int main() {
    int N,V;
    cin >>N>>V;
    vector<node> goods;
    

    for (int i=0;i<N;++i) {
        int v,w,s;
        cin >>v>>w>>s;
        
        for (int k = 1; k <= s; k *= 2) {
            goods.push_back({v * k, w * k});
            s -= k;
        }
        if (s > 0) {
            goods.push_back({v * s, w * s});
        }
    }

    // 标准的 0/1 背包
    vector<int> dp(V + 1, 0);
    for (const auto& g:goods) {
        for (int j=V; j>=g.v;--j) {
            dp[j] =max(dp[j],dp[j-g.v]+g.w);
        }
    }

    cout <<dp[V]<<endl;
    return 0;
}
