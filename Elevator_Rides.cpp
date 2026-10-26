#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    long long x;
    cin>>n>>x;
    vector<long long>w(n);
    for(int i=0;i<n;i++){
        cin>>w[i];
    }
    vector<pair<int,long long>>dp(1<<n,{n+1,0});
    dp[0] = {1,0};
    for(int mask=0;mask<(1<<n);mask++){

        for(int i=0;i<n;i++){
            if(mask & (1<<i)){
                continue;
            }
            int newMask = mask | (1<<i);
            
            int rides = dp[mask].first;
            long long last = dp[mask].second;
            int newRides;
            long long newLastWeight;
            if(last + w[i] <= x){
                newRides = rides;
                newLastWeight = last + w[i];
            }else{
                newRides = rides + 1;
                newLastWeight = w[i];
            }
            
            dp[newMask] = min(dp[newMask], make_pair(newRides,newLastWeight));
        }
    }
    cout<<dp[(1<<n)-1].first<<'\n';
    return 0;
}