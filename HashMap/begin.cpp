#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[] = {1,1,1,1,1,2,3,3};
    map<int,int> m;

    for(int i = 0 ; i < 8 ; i++){
        m[arr[i]]++;
    }

    for(auto i : m){
        cout<<i.first<<" - "<<i.second<<endl;
    }
    int sum = 0;
    for(auto i : m){
        sum += (i.second - 1);
    }

    cout<<sum<<endl;
}