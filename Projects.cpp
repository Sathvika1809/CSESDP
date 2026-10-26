#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
    int n;
    cin>>n;
    vector<pair<int,pair<int,int>>>vec;
    for(int i=0;i<n;i++){
        int a,b,p;
        cin>>a>>b>>p;
        vec.push_back({b,{a,p}});
    }
    sort(vec.begin(),vec.end());
    vector<ll>ends(n);

    for(int i=0;i<n;i++){
        ends[i] = vec[i].first;
    }
    vector<ll>dp(n+1,0);
    for(int i=1;i<=n;i++){
        ll st = vec[i-1].second.first;
        ll rew = vec[i-1].second.second;

        // Compatible prev project with the current st as their end is less so there is possibility
        int j = lower_bound(ends.begin(), ends.begin()+(i-1), st)-ends.begin();

        dp[i] = max(dp[i-1] , dp[j]+rew);
    }
    cout<<dp[n]<<'\n';
    return 0;
}