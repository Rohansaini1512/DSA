/*Given an adjacency list for a Directed Acyclic Graph (DAG) where adj[u] contains a list of all vertices v such that there exists a directed edge u -> v. Return topological sort for the given graph.

Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge u -> v, vertex u comes before v in the ordering.
Note: As there are multiple Topological orders possible, you may return any of them. If your returned Topological sort is correct then the output will be 1 else 0.

Examples:

Input: adj = [[], [0], [0], [0]] 

Output: 1
Explanation: The output 1 denotes that the order is valid. Few valid Topological orders for the given graph are:
[3, 2, 1, 0]
[1, 2, 3, 0]
[2, 3, 1, 0]
Input: adj = [[], [3], [3], [], [0,1], [0,2]]

Output: 1
Explanation: The output 1 denotes that the order is valid. Few valid Topological orders for the graph are:
[4, 5, 0, 1, 2, 3]
[5, 2, 4, 0, 1, 3]*/

class Solution {
  private:
    // Depth-First Search function for Topological Sorting
    void dfs(int i, vector<int>& vis, vector<vector<int>>& adj, stack<int>& st) {
        vis[i] = 1; // Mark the node as visited

        // Traverse all adjacent nodes
        for (auto it : adj[i]) {
            if (!vis[it]) {
                dfs(it, vis, adj, st); // Recursively visit unvisited nodes
            }
        }

        // After exploring all adjacent nodes, push the current node to the stack
        st.push(i);
    }

  public:
    // Function to return a list containing vertices in Topological order
    vector<int> topologicalSort(vector<vector<int>>& adj) {
        int n = adj.size(); // Number of nodes in the graph
        vector<int> vis(n, 0); // Visited array to keep track of visited nodes
        stack<int> st; // Stack to store topological order

        // Perform DFS for all unvisited nodes
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i, vis, adj, st);
            }
        }

        // Extract elements from stack to get the correct topological order
        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        return ans; // Return the topological order
    }
};


//  Kahn's Algorithm
class Solution {
  public:
    // Function to return list containing vertices in Topological order.
    vector<int> topologicalSort(vector<vector<int>>& adj) {
        int n = adj.size(); // Number of nodes in the graph
        vector<int> indeg(n, 0); // Array to store the in-degree of each node

        // Compute in-degree for each node
        for (int i = 0; i < n; i++) {
            for (auto it : adj[i]) {
                indeg[it]++; // Increment in-degree for destination nodes
            }
        }

        queue<int> q; // Queue for BFS traversal
        // Push all nodes with in-degree 0 into the queue
        for (int i = 0; i < n; i++) {
            if (indeg[i] == 0) q.push(i);
        }

        vector<int> topo; // Vector to store topological order
        while (!q.empty()) {
            int node = q.front(); // Extract the front node
            q.pop();
            
            topo.push_back(node); // Add the node to the topological order
            
            // Reduce the in-degree of all its adjacent nodes
            for (auto it : adj[node]) {
                indeg[it]--;
                // If in-degree becomes 0, push it into the queue
                if (indeg[it] == 0) q.push(it);
            }
        }

        return topo; // Return the final topological order
    }
};
 