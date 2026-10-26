#include <bits/stdc++.h>
using namespace std;

// set<int> findWays(vector<int>&x,int n){
//     set<int>sub;
//     for(int mask=0;mask<(1<<n);mask++){
//         int ans = 0;
//         for(int i=0;i<n;i++){
//             if(mask & (1<<i)){
//                 ans+=x[i];
//             }
//         }
//         sub.insert(ans);
//     }
//     sub.erase(0);
//     return sub;
// }
int main(){
    int n;
    cin>>n;
    vector<int>x(n);
    int tot = 0;
    for(int i=0;i<n;i++){
        cin>>x[i];
        tot += x[i];
    }
    vector<bool>dp(tot+1,false);
    dp[0] = true;
    for(int i=0;i<n;i++){
        for(int s = tot;s>=x[i];s--){
            if(dp[s-x[i]]){
                dp[s] = true;
            }
        }
    }
    vector<int>res;
    for(int s = 1;s<=tot;s++){
        if(dp[s]){
            res.push_back(s);
        }
    }
    cout<<res.size()<<'\n';
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
    cout<<'\n';
    // set<int>sub = findWays(x,n);
    // vector<int>res(sub.begin(),sub.end());
    // cout<<res.size()<<'\n';
    // for(int i=0;i<res.size();i++){
    //     cout<<res[i]<<" ";
    // }
    
    return 0;
}