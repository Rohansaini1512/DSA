/*Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.
The graph is represented as an adjacency list, where adj[i] contains a list of vertices that are directly reachable from vertex i. Specifically, adj[i][j] represents an edge from vertex i to vertex j.

Example 1:

Input:



Output: 1
Explanation: 3 -> 3 is a cycle
Example 2:
Input:


Output: 0
Explanation: no cycle in the graph*/

class Solution {
    bool dfs(int i, vector<int>& vis, vector<int>& pathVis, vector<vector<int>>& adj) {
        vis[i] = 1;
        pathVis[i] = 1;

        for (auto it : adj[i]) {
            if (!vis[it]) {  // Corrected from vis[i] to vis[it]
                if (dfs(it, vis, pathVis, adj)) return true;
            } else if (pathVis[it]) {  // Corrected from pathVis[i] to pathVis[it]
                return true;
            }
        }

        pathVis[i] = 0;  // Backtracking
        return false;
    }

public:
    bool isCyclic(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> vis(n, 0);
        vector<int> pathVis(n, 0);

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {  
                if (dfs(i, vis, pathVis, adj)) return true;
            }
        }
        return false;
    }
};


//  Kahn's Algorithm

class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(vector<vector<int>> &adj) {
        int n = adj.size(); // Number of nodes in the graph
        vector<int> deg(n, 0); // Array to store in-degree of nodes

        // Compute in-degree for each node
        for (int i = 0; i < n; i++) {
            for (auto it : adj[i]) { // Corrected syntax: adj[i] instead of adj(i)
                deg[it]++; // Increment in-degree for destination nodes
            }
        }

        queue<int> q;
        // Push all nodes with in-degree 0 into the queue
        for (int i = 0; i < n; i++) {
            if (deg[i] == 0) q.push(i);
        }

        vector<int> topo; // Stores the topological order
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            
            topo.push_back(curr); // Add to topological order
            
            // Reduce the in-degree of its neighbors
            for (auto it : adj[curr]) {
                deg[it]--;
                if (deg[it] == 0) q.push(it);
            }
        }

        // If all nodes are in the topological order, no cycle exists
        return topo.size() != n; // If topo.size() < n, cycle exists
    }
};
