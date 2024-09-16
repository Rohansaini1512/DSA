#include<bits/stdc++.h>
using namespace  std;

int main(){
    int n;
    cin>>n;

    vector<int> input(n);

    for(int i = 0 ; i < n ; i++){
        cin>>input[i];
    }
    map<int,int>m;
    for(int i = 0 ; i < n ; i++){
        //  storing frequency of every element in input array
        m[input[i]]++;
    }

    // [1,2], [7,1]
    // m[1]++
    // m[1]++
    // m[7]++

    int sum = 0;
    for(auto ele:m){
        if(ele.second > 1){
            sum += ele.first;
        }
    }

    cout<<sum;
}