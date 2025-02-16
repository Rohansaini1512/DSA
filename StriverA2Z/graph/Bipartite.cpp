/*There is an undirected graph with n nodes, where each node is numbered between 0 and n - 1. You are given a 2D array graph, where graph[u] is an array of nodes that node u is adjacent to. More formally, for each v in graph[u], there is an undirected edge between node u and node v. The graph has the following properties:

There are no self-edges (graph[u] does not contain u).
There are no parallel edges (graph[u] does not contain duplicate values).
If v is in graph[u], then u is in graph[v] (the graph is undirected).
The graph may not be connected, meaning there may be two nodes u and v such that there is no path between them.
A graph is bipartite if the nodes can be partitioned into two independent sets A and B such that every edge in the graph connects a node in set A and a node in set B.

Return true if and only if it is bipartite.

 

Example 1:


Input: graph = [[1,2,3],[0,2],[0,1,3],[0,2]]
Output: false
Explanation: There is no way to partition the nodes into two independent sets such that every edge connects a node in one and a node in the other.
Example 2:


Input: graph = [[1,3],[0,2],[1,3],[0,2]]
Output: true
Explanation: We can partition the nodes into two sets: {0, 2} and {1, 3}.
 */

class Solution {
    bool dfs(int i, int col, vector<int>& colour, vector<vector<int>>& graph) {
        colour[i] = col;

        for (auto it : graph[i]) {
            if (colour[it] == -1) { // If not colored, color it with opposite color
                if (!dfs(it, !col, colour, graph)) return false;
            } else if (colour[it] == col) { // If adjacent node has same color, not bipartite
                return false;
            }
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colour(n, -1); // Fix: Initialize vector correctly

        for (int i = 0; i < n; i++) {
            if (colour[i] == -1) { // Check all components
                if (!dfs(i, 0, colour, graph)) return false;
            }
        }
        return true;
    }
};
