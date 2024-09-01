#include<bits/stdc++.h>
using namespace std;

int maxLength(vector<int> &v){
    unordered_map<int, int>m;
    int sum = 0;
    int maxLen = INT_MIN;
    
    for(int i = 0 ; i < v.size() ; i++){
        sum += v[i];
        if(sum == 0){
            maxLen++;
        }

        if(m.find(sum) != m.end()){
            maxLen = max(maxLen, i - m[sum]);
        }
        else{
            m[sum] = i;
        }
    }
    return maxLen;
}

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i = 0 ; i < n ; i++){
        cin>>a[i];
    }
    cout<<maxLength(a)<<endl;
}