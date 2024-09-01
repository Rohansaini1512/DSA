#include<bits/stdc++.h>
using namespace std;

vector<int> targetSumpair(vector<int>&v,int targetsum){
    unordered_map<int,int>mp;
    vector<int>ans;
    for(int i = 0 ; i < v.size() ; i++){
        if(mp.find(targetsum-v[i])!=mp.end()){
            ans.push_back(mp[targetsum-v[i]]);
            ans.push_back(i);
            return ans;
        }
        mp[v[i]] = i;
    }
    return ans;
}

int main(){
    int n;
    cin >> n;

    vector<int> v(n);
    for(int i = 0 ; i < n ; i++){
        cin>>v[i];
    }
    int targetsum;
    cin>>targetsum;
    vector<int>ans = targetSumpair(v,targetsum);
    cout<<ans[0]<<" "<<ans[1]<<endl;
}