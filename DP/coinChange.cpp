// Given an integer array of coins [] of size N representing diff types of currency and the integer sum 
// THe task is to find the number of ways to make the sum using the diff combination from coins[]. Assume that you have an infinite supply of each type of coin

#include<bits/stdc++.h>
using namespace std;

int fbu(vector<int> &v , int x , int n){
    // int n = v.size();
    vector<int> dp(1000005, 0);
    int MOD=1e9+7;
    dp[0] = 1;
    for(int i = 1; i < n; i++){
        for(int j = 1; j <= x; j++){
            if(i - v[j] < 0) continue;
            dp[i] = (dp[i]%MOD + dp[i - v[j]]%MOD)%MOD;
        }
    }
    return dp[x];
}

int main(){
    int n;
    cin>>n;
    int x;
    cin>>x;
    vector<int> v(n);
    for(int i = 0 ; i < n ; i++){
        cin>>v[i];
    }
    cout<<fbu(v , x , n)<<endl;
    return 0;
}