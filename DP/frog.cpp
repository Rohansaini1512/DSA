#include<bits/stdc++.h>
using namespace std;

vector<int> dp;
int f(vector<int> &heights , int i , int k){
    if(i == heights.size() - 1) return 0;
    if(dp[i] != -1) return dp[i];
    int ans = INT_MAX;
    for(int j = 1; j <= k; j++){
        if(i + j >= heights.size()) break;
        ans = min(ans , abs(heights[i] - heights[i+j]) + f(heights , i+j , k));
    }
    return dp[i] = ans;
}

int fbu(vector<int> &heights , int k){
    int n = heights.size();
    dp[n-1] = 0;
    for(int i = n-2; i >= 0; i--){
        int ans = INT_MAX;
        for(int j = 1; j <= k; j++){
            if(i + j >= heights.size()) break;
            ans = min(ans , abs(heights[i] - heights[i+j]) + dp[i+j]);
        }
        dp[i] = ans;
    }
    return dp[0];
}

int main(){
    int n;
    cin>>n;
    dp.resize(100005, INT_MAX);
    int k;
    cin>>k;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin>>v[i];
    }
    cout<<f(v,0,k)<<endl;
    return 0;
}