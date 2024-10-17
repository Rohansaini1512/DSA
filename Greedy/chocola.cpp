#include<bits/stdc++.h>
using namespace std;

#define ll long long int

bool cmp(int x , int y){
    return x>y;
}

ll minCost(int n , int m , vector<ll>&verticle , vector<ll>&horizontal){
    sort(verticle.begin() , verticle.begin() , cmp);
    sort(horizontal.begin() , horizontal.begin() , cmp);
    int hz = 1;
    int vz = 1;
    int h = 0 ,  v = 0;
    int ans = 0;
    while(h < horizontal.size() and v < verticle.size()){
        if(verticle[v] > horizontal[h]){
            ans += verticle[v]*vz;
            hz++;
            v++;
        }else{
            ans += horizontal[h]*hz;
            vz++;
            h++;
        }
    }
    while(h < horizontal.size()){
        ans += horizontal[h]*hz;
        vz++;
        h++;
    }
    while(v < verticle.size()){
        ans += verticle[v]*vz;
        hz++;
        v++; 
    }
    return ans;
}


int main(){
    int n , m;
    cin>>m>>n;
    
}