#include<bits/stdc++.h>
using namespace std;

int leastInterval(vector<char>tasks , int n){
    // 1. count freq of tasks
    unordered_map<char, int> freq;
    for(auto task : tasks){
        freq[task]++;
    }

    // 2. insert freq to max heap
    priority_queue<int> pq;
    for(auto f : freq){
        pq.push(f.second);
    }

    // 3. finding time until pq is empty
    int totalTime  = 0;
    while(!pq.empty()){
        vector<int> temp;
        int time = 0;
        for(int i = 0; i <= n; i++){
            if(!pq.empty()){
                int freq = pq.top();
                pq.pop();
                
                if(freq>1){
                    temp.push_back(freq - 1);
                }
            }
            totalTime++;

            if(pq.empty() && temp.empty()){
                return totalTime;// all tasks have been executed
            }
        }
        for(auto t : temp){
            pq.push(t); // adding back remaining tasks
        }
    }
    return totalTime;
}

int main(){
    vector<char> tasks = {'A', 'A', 'A', 'B', 'B', 'B'};
    int cooldown = 2;

    int leastTime = leastInterval(tasks, cooldown);
    cout<<"Least number of units of time: "<<leastTime<<endl;

}