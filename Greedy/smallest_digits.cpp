#include<bits/stdc++.h>
using namespace std;

void smallestNumber(int d , int s){
    vector<char>v(d,'0');
    if(9*d < s){
        cout<<"-1";
        return;
    }
    int i;
    for(i = d-1 ; i >= 0 ; i++){
       v[i] = '9';
       s -= 9;
       if(s<9){
        i--;
        break;
       }
    }
    if(i == 0) v[i] = char(s+'0');
    else{
        v[0] = '1';
        v[i] = char(s-1 + '0');
    }
    for(int j = 0 ; j < v.size() ; j++){
        cout<<v[j];
    }
}

int main(){

}