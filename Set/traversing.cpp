#include<bits/stdc++.h>
using namespace std;

int main(){
    set<int> s;

    s.insert(1);
    s.insert(2);
    s.insert(4);
    s.insert(3);
    cout<<s.size()<<endl;

    // set<int>::iterator it;
    // for(it = s.begin(); it != s.end(); it++){
    //     cout<<*it<<" ";
    // }
    // cout<<endl;
    

    for(auto value: s){
        cout<<value<<" ";
    }
    cout<<endl;

    // deleting an element
    // s.erase(2);
    // auto itr = s.begin();
    // advance(itr, 2);
    // s.erase(itr);

    auto start = s.begin();
    start++;

    auto end = s.begin();
    advance(end, 3);

    s.erase(start, end);

    for(auto value: s){
        cout<<value<<" ";
    }
    cout<<endl;
}