/*Given start, end and an array arr of n numbers. At each step, start is multiplied with any number in the array and then mod operation with 100000 is done to get the new start.

Your task is to find the minimum steps in which end can be achieved starting from start. If it is not possible to reach end, then return -1.

Example 1:

Input:
arr[] = {2, 5, 7}
start = 3, end = 30
Output:
2
Explanation:
Step 1: 3*2 = 6 % 100000 = 6 
Step 2: 6*5 = 30 % 100000 = 30
Example 2:

Input:
arr[] = {3, 4, 65}
start = 7, end = 66175
Output:
4
Explanation:
Step 1: 7*3 = 21 % 100000 = 21 
Step 2: 21*3 = 63 % 100000 = 63 
Step 3: 63*65 = 4095 % 100000 = 4095 
Step 4: 4095*65 = 266175 % 100000 = 66175*/

int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        queue<pair<int,int>>q;
        if(start == end) return 0;
        q.push({start,0});
        vector<int>dist(100000,1e9);
        dist[start] = 0;
        int mod = 100000;
        while(!q.empty()){
            int curr = q.front().first;
            int step = q.front().second;
            q.pop();
            for(auto it:arr){
                int num = (curr*it)%mod;
                if(step+1 < dist[num]){
                    dist[num] = step+1;
                    if(num == end) return step+1;
                    q.push({num,step+1});
                }
            }
        }
        return -1;
    }