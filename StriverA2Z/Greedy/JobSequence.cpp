/*You are given three arrays: id, deadline, and profit, where each job is associated with an ID, a deadline, and a profit. Each job takes 1 unit of time to complete, and only one job can be scheduled at a time. You will earn the profit associated with a job only if it is completed by its deadline.

Your task is to find:

The maximum number of jobs that can be completed within their deadlines.
The total maximum profit earned by completing those jobs.
Examples :

Input: id = [1, 2, 3, 4], deadline = [4, 1, 1, 1], profit = [20, 1, 40, 30]
Output: [2, 60]
Explanation: Job1 and Job3 can be done with maximum profit of 60 (20+40).
Input: id = [1, 2, 3, 4, 5], deadline = [2, 1, 2, 1, 1], profit = [100, 19, 27, 25, 15]
Output: [2, 127]
Explanation: Job1 and Job3 can be done with maximum profit of 127 (100+27).
Input: id = [1, 2, 3, 4], deadline = [3, 1, 2, 2], profit = [50, 10, 20, 30]
Output: [3, 100]
Explanation: Job1, Job3 and Job4 can be completed with a maximum profit of 100 (50 + 20 + 30).*/

class Solution {
    struct Data{
        int id;
        int deadline;
        int profit;
    };
    static bool cmp(Data val1 , Data val2){
        return val1.profit > val2.profit;
    }
  public:
    vector<int> JobSequencing(vector<int> &id, vector<int> &deadline,
                              vector<int> &profit) {
                                  
        // code here
        int n = id.size();
        vector<Data>v(n);
        for(int i = 0 ; i < n ; i++){
            v[i] = {id[i] , deadline[i] , profit[i]};
        }
        sort(v.begin() , v.end() , cmp);
        int maxDead = -1;
        for(int i = 0 ; i < n ; i++){
            maxDead = max(maxDead , v[i].deadline);
        }
        vector<int>d(maxDead+1 , -1);
        int jobCnt = 0 , totalPro = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = v[i].deadline ; j > 0 ; j--){
                if(d[j] == -1){
                    d[j] = v[i].id;
                    totalPro += v[i].profit;
                    jobCnt++;
                    break;
                }
            }
        }
        vector<int>res(2);
        res[0] = jobCnt;
        res[1] = totalPro;
        return res;
    }
};