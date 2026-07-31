#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
const int maxm = 1e6;

long long dp[maxm+1][2];



int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    dp[1][0] = 1;
    dp[1][1] = 1;

    for(int i=2;i<=maxm;i++){
        dp[i][0] = (4LL*dp[i-1][0] + dp[i-1][1])%mod;
        dp[i][1] = (dp[i-1][0]+2LL*dp[i-1][1])%mod;
    }
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<(dp[n][0]+dp[n][1])%mod<<'\n';
    }
    return 0;
}