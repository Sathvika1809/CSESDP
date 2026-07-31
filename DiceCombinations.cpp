#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
int findWays(int n,vector<int>&dp){
    dp[0] = 1;
    dp[1] = 1;
    for(int i=2;i<=n;i++){
        for(int j=1;j<=6;j++){
            if(i-j >= 0){
                dp[i] = (dp[i]+dp[i-j])%mod;
            }
        }
    }
    return dp[n];
}
int main(){
    int n;
    cin>>n;
    vector<int>dp(n+1,0);
    cout<<findWays(n,dp);
    return 0;
}