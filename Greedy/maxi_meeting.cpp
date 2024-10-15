#include<bits/stdc++.h>
using namespace std;

struct meeting{
    int start;
    int end;
    int idx;
};
bool cmp(meeting m1 , meeting m2){
    return m1.end < m2.end;
}

void print_max(vector<meeting> &arr){
    sort(arr.begin() , arr.end() , cmp);
    cout<<arr[0].idx<<" ";
    meeting last = arr[0];
    for(int i = 1 ; i < arr.size() ; i++){
        if(arr[i].start > last.end){
            cout<<arr[i].idx<<" ";
            last = arr[i];
        }
    }
}
