#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e16;
ll findWays(int l,int r,int n,vector<ll>&a,vector<vector<ll>>&dp){
    if(l>r)return 0;
    if(l==r){
        return dp[l][r]  = a[l];
    }
    if(dp[l][r]!=-INF){
        return dp[l][r];
    }
    ll takeleft = a[l]+min(findWays(l+2,r,n,a,dp),findWays(l+1,r-1,n,a,dp));
    ll takeright = a[r]+min(findWays(l+1,r-1,n,a,dp),findWays(l,r-2,n,a,dp));
    return dp[l][r] = max(takeleft,takeright);
}

int main(){
    int n;
    cin>>n;
    vector<ll>x(n);
    for(int i=0;i<n;i++){
        cin>>x[i];
    }
    vector<vector<ll>>dp(n,vector<ll>(n,-INF));
    cout<<findWays(0,n-1,n,x,dp)<<'\n';
    return 0;
}