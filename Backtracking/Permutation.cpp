// Write a program to print all permutations of a given string s in lexicographically sorted order.
#include<bits/stdc++.h>
using namespace std;

void f(string &str , int i){
    if(i == str.size()){
        cout<<str<<endl;
        return;
    }
    for(int j = i ; j < str.size() ; j++){
        swap(str[i] , str[j]);
        f(str , i+1);
        swap(str[i] , str[j]);
    }
}

int main(){
    string str = "abc";
    f(str , 0);
    return 0;
}