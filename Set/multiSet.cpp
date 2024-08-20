#include<bits/stdc++.h>
using namespace std;

int main(){
    multiset<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(2);
    s.insert(4);
    s.insert(3);

    for(auto value: s){
        cout<<value<<" ";
    }cout<<endl;
}