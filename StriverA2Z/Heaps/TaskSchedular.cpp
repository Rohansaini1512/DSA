/*You are given an array of CPU tasks, each labeled with a letter from A to Z, and a number n. Each CPU interval can be idle or allow the completion of one task. Tasks can be completed in any order, but there's a constraint: there has to be a gap of at least n intervals between two tasks with the same label.

Return the minimum number of CPU intervals required to complete all tasks.

 

Example 1:

Input: tasks = ["A","A","A","B","B","B"], n = 2

Output: 8

Explanation: A possible sequence is: A -> B -> idle -> A -> B -> idle -> A -> B.

After completing task A, you must wait two intervals before doing A again. The same applies to task B. In the 3rd interval, neither A nor B can be done, so you idle. By the 4th interval, you can do A again as 2 intervals have passed.

Example 2:

Input: tasks = ["A","C","A","B","D","B"], n = 1

Output: 6

Explanation: A possible sequence is: A -> B -> C -> D -> A -> B.

With a cooling interval of 1, you can repeat a task after just one other task.*/
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>mp;

        for(auto &i:tasks){
            mp[i]++;
        }

        priority_queue<int>pq;
        for(auto e:mp){
            pq.push(e.second);
        }

        int total = 0;
        while(!pq.empty()){
            vector<int>temp;
            // looping one time frame = n+1 units of time 
            for(int i = 0 ; i <= n ; i++){
                if(!pq.empty()){
                    int freq = pq.top();
                    pq.pop();

                    if(freq>1){
                        temp.push_back(freq-1); // adding remaining tasks in temp vector
                    }
                }
                total++;
                if(pq.empty() && temp.empty()){
                    return total; // all tasks have been executed
                }
            }
            for(auto t:temp){
                pq.push(t); // adding back remaining tasks from temp vector to pq
            }
        }
        return total;
    }
};