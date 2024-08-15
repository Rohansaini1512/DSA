// You are given an array of integer nums , there is a sliding window of 
// size k which is moving from the very left of the array to the very right. 
// You can only see the k numbers in the window. Each time the sliding window 
// moves right by one position. Return the max sliding window which basically contains the max element 
// in the window at each step.

#include<bits/stdc++.h>
using namespace std;

void max(vector<int>& arr, int k){
    deque<int>dq;
    for(int i = 0 ; i < k ; i++){
        while(not dq.empty() and arr[dq.back()] < arr[i]){
            dq.pop_back();
        }
        dq.push_back(i);
    }
    for(int i = k ; i < arr.size() ; i++){
        int curr = arr[i];
        if(dq.front() == i - k){
            dq.pop_front();
        }
        while(not dq.empty() and arr[dq.back()] < arr[i]){
            dq.pop_back();
        }
        dq.push_back(i);
    }
}

int main(){

}
