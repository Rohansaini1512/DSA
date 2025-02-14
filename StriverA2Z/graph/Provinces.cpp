/*Given an undirected graph with V vertices. We say two vertices u and v belong to a single province if there is a path from u to v or v to u. Your task is to find the number of provinces.

Note: A province is a group of directly or indirectly connected cities and no other cities outside of the group.

Example 1:

Input:
[
 [1, 0, 1],
 [0, 1, 0],
 [1, 0, 1]
]

Output:
2
Explanation:
The graph clearly has 2 Provinces [1,3] and [2]. As city 1 and city 3 has a path between them they belong to a single province. City 2 has no path to city 1 or city 3 hence it belongs to another province.
Example 2:
Input:
[
 [1, 1],
 [1, 1]
]

Output :
1*/

class Solution {
    void dfs(int i, vector<vector<int>>& list, vector<int>& vis) {
        vis[i] = 1;
        for (auto it : list[i]) {  // Iterate over neighbors of node i
            if (!vis[it]) {
                dfs(it, list, vis);
            }
        }
    }

public:
    int numProvinces(vector<vector<int>>& adj, int V) {
        vector<vector<int>> list(V); // Adjacency List Representation

        // Convert adjacency matrix to adjacency list
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (adj[i][j] == 1 && i != j) { // Avoid self-loops
                    list[i].push_back(j);
                }
            }
        }

        vector<int> vis(V, 0); // Use vector instead of array
        int cnt = 0;

        // Count the number of connected components (provinces)
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {  // If a node is not visited, it's a new province
                cnt++;
                dfs(i, list, vis);
            }
        }
        return cnt;
    }
};
