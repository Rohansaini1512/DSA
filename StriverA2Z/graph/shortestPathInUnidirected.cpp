/*You are given an adjacency list, adj of Undirected Graph having unit weight of the edges, find the shortest path from src to all the vertex and if it is unreachable to reach any vertex, then return -1 for that vertex.

Examples :

Input: adj[][] = [[1, 3], [0, 2], [1, 6], [0, 4], [3, 5], [4, 6], [2, 5, 7, 8], [6, 8], [7, 6]], src=0
Output: [0, 1, 2, 1, 2, 3, 3, 4, 4]

Input: adj[][]= [[3], [3], [], [0, 1]], src=3
Output: [1, 1, -1, 0]

Input: adj[][]= [[], [], [], [4], [3], [], []], src=1
Output: [-1, 0, -1, -1, -1, -1, -1] */

class Solution {
  public:
    // Function to find the shortest path from the source node to all other nodes in an unweighted graph.
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        int n = adj.size();  // Get the number of nodes in the graph.
        
        // Initialize distance array with a large value (infinity), assuming nodes are unreachable.
        vector<int> dist(n, 1e9);
        dist[src] = 0;  // Distance to the source node itself is 0.
        
        queue<int> q;  // BFS queue to traverse the graph.
        q.push(src);    // Start BFS from the source node.
        
        while (!q.empty()) {
            int curr = q.front();  // Get the current node from the queue.
            q.pop();
            
            // Traverse all adjacent nodes (neighbors) of the current node.
            for (auto it : adj[curr]) {
                // If we find a shorter path to 'it' through 'curr', update it.
                if (dist[curr] + 1 < dist[it]) {
                    dist[it] = dist[curr] + 1;  // Update shortest distance.
                    q.push(it);  // Push the updated node into the queue for further processing.
                }
            }
        }
        
        // Prepare the final result array.
        vector<int> ans(n, -1);  // Initialize result with -1 (meaning unreachable).
        for (int i = 0; i < n; i++) {
            if (dist[i] != 1e9) {  // If a node is reachable, update its shortest distance.
                ans[i] = dist[i];
            }
        }
        
        return ans;  // Return the shortest path distances.
    }
};
