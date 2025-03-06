/*Given a weighted, undirected, and connected graph with V vertices and E edges, your task is to find the sum of 
the weights of the edges in the Minimum Spanning Tree (MST) of the graph. The graph is represented by an adjacency list, 
where each element adj[i] is a vector containing vector of integers. Each vector represents an edge, with the first integer 
denoting the endpoint of the edge and the second integer denoting the weight of the edge.

Input:
3 3
0 1 5
1 2 3
0 2 1

Output: 4
Explanation:

The Spanning Tree resulting in a weight
of 4 is shown above.
Input: 
2 1
0 1 5

  

Output: 5 

Explanation: Only one Spanning Tree is possible which has a weight of 5.*/

class Solution {
  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        // code here
        priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>vis(V,0);
        int sum = 0;
        //  {wt,edge}
        pq.push({0,0});
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int node = it.second;
            int wt = it.first;
            
            if(vis[node] == 1) continue;
            vis[node] = 1;
            sum += wt;
            for(auto i:adj[node]){
                int adjNode = i[0];
                int adjwt = i[1];
                if(!vis[adjNode]){
                    pq.push({adjwt,adjNode});
                }
            }
        }
        return sum;
    }
};
