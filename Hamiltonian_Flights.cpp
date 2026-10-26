#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj(n);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        a--;
        b--;
        adj[a].push_back(b);
    }
    vector<vector<int>>dp((1<<n), vector<int>(n,0));
    // starting from 1 
    dp[1][0] = 1;
    for(int mask = 1;mask < (1<<n); mask++){
        //starting city must be included
        if(!(mask & 1))continue;
        //city n-1 is reached but not visited all n-1 cities
        if((mask & (1 << (n-1))) && mask != (1<<n)-1){
            continue;
        }
        for(int u=0;u<n;u++){
            if(!(mask & (1<<u))){
                continue;
            }
            if(dp[mask][u] == 0)continue;
            for(int v: adj[u]){
                if(mask & (1<<v)){
                    continue;
                }
                int newMask = mask | (1<<v);
                dp[newMask][v] = (dp[newMask][v]+dp[mask][u])%mod;
            }
        }
    }
        cout << dp[(1<<n)-1][n-1]<<'\n';
    

    return 0;
}