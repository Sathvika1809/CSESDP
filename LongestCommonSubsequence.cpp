#include <bits/stdc++.h>
using namespace std;
int findWays(int i,int j,int n,int m,vector<int>&a,vector<int>&b,vector<vector<int>>&dp){
    if(i == n || j==m){
        return 0;
    }
    if(dp[i][j]!=-1)return dp[i][j];
    int take = 0;
    int nottake = 0;
    if(a[i]==b[j]){
        take  = 1+findWays(i+1,j+1,n,m,a,b,dp);
    }else{
        nottake = max(findWays(i+1,j,n,m,a,b,dp),findWays(i,j+1,n,m,a,b,dp));
    }
    return dp[i][j] = max(take,nottake);
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<int>b(m);
    for(int i=0;i<m;i++){
        cin>>b[i];
    }
    vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
    cout<< findWays(0,0,n,m,a,b,dp)<<'\n';
    int i=0,j=0;
    vector<int>ans;
    while(i<n && j<m){
        if(dp[i+1][j] == -1)
            dp[i+1][j] = findWays(i+1,j,n,m,a,b,dp);

        if(dp[i][j+1] == -1)
            dp[i][j+1] = findWays(i,j+1,n,m,a,b,dp);

        if(a[i] == b[j]){
            ans.push_back(a[i]);
            i++;
            j++;
        }else if(dp[i+1][j] >= dp[i][j+1]){
            i++;
        }else{
            j++;
        }
    }
    if(ans.empty()){
        return 0;
    }
    for(int i=0;i<(int)ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<'\n';
    return 0;
}