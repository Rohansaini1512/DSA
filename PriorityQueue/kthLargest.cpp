#include<bits/stdc++.h>
using namespace std;

int kthLargest(vector<int> &a , int n , int k){
    priority_queue<int , vector<int> , greater<int>> pq; // min heap
    for(int i = 0 ; i < n ; i++){
        pq.push(a[i]);
        if(pq.size() > k){
            pq.pop(); // removing the smallest eleement from the heap
        }
    }
    return pq.top();
}

int main(){
    int n , k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i = 0 ; i < n ; i++){
        cin>>a[i];
    }
    cout<<kthLargest(a , n , k)<<endl;
}