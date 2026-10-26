#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;

int main(){
    int n;
    cin>>n;
    vector<vector<int>>a(n+1,vector<int>(n+1,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    int tot = (1<<n);
    vector<int>dp((1<<n),0);
    dp[0] = 1;
    for(int mask = 0; mask < tot; mask++){
        //identifies the next man 
        int man = __builtin_popcount((unsigned int)mask);
        if(man == n)continue;
        for(int w = 0;w<n;w++){
            if(mask & (1<<w))continue;
            if(a[man][w]==1){
                int newMask = mask | (1<<w);
                dp[newMask] = (dp[newMask]+dp[mask])%mod;
            }
        }
    }
    cout << dp[tot-1]<<'\n';
    return 0;
}