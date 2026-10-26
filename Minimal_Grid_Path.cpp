#include <bits/stdc++.h>
using namespace std;

void findWays(int n,vector<vector<char>>&grid,string res,vector<vector<int>>&dp){
    
}



int main(){
    int n;
    cin>>n;
    vector<vector<char>>grid(n,vector<char>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
        }
    }
    vector<vector<char>>dp(n,vector<char>(n));
    string res = "";
    findWays(n,grid,res,dp);


    return 0;
}