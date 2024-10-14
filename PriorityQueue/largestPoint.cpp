#include<bits/stdc++.h>
using namespace std;

int largestPoint(vector<int> a ,int n, int k){
    priority_queue<int , vector<int>, greater<int>> pq;
    for(auto i : a){
        pq.push(i);
    }
    while(k--){
        int firstele = pq.top();
        pq.pop();
        int secondele = pq.top();
        pq.pop();
        int product = firstele * secondele;
        pq.push(product);
    }
    int sum = 0;
    while(pq.size() > 1){
        pq.pop();
    }
    return pq.top();
}

int main(){
    int n , k;
    cin>>n>>k;
    vector<int> a(n);
    for(auto &x : a){
        cin>>x;
    }
    cout<<largestPoint(a, n, k)<<endl;
}