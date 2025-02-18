/*Given a Directed Acyclic Graph of V vertices from 0 to n-1 and a 2D Integer array(or vector) edges[ ][ ] of length E, 
where there is a directed edge from edge[i][0] to edge[i][1] with a distance of edge[i][2] for all i.

Find the shortest path from src(0) vertex to all the vertices and if it is impossible to reach any vertex, then return -1 for that vertex.

Examples :

Input: V = 4, E = 2, edges = [[0,1,2], [0,2,1]]
Output: [0, 2, 1, -1]
Explanation: Shortest path from 0 to 1 is 0->1 with edge weight 2. Shortest path from 0 to 2 is 0->2 with edge weight 1. 
There is no way we can reach 3, so it's -1 for 3.
Input: V = 6, E = 7, edges = [[0,1,2], [0,4,1], [4,5,4], [4,2,2], [1,2,3], [2,3,6], [5,3,1]]
Output: [0, 2, 3, 6, 1, 5]
Explanation: Shortest path from 0 to 1 is 0->1 with edge weight 2. Shortest path from 0 to 2 is 0->4->2 with edge weight 1+2=3. 
Shortest path from 0 to 3 is 0->4->5->3 with edge weight 1+4+1=6. 
Shortest path from 0 to 4 is 0->4 with edge weight 1.Shortest path from 0 to 5 is 0->4->5 with edge weight 1+4=5.*/
class Solution {
  private:
    // DFS function for topological sorting
    void dfs(int i, vector<pair<int, int>> adj[], vector<int>& vis, stack<int>& st) {
        vis[i] = 1;  // Mark node as visited
        for (auto it : adj[i]) {
            int v = it.first;
            if (!vis[v]) {
                dfs(v, adj, vis, st);
            }
        }
        st.push(i);  // Push the node into the stack after visiting all its neighbors
    }

  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // Step 1: Convert edge list to adjacency list
        vector<pair<int, int>> adj[V];
        for (int i = 0; i < E; i++) {  // Fix: Iterate over edges, not vertices
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v, wt}); // Directed edge from u → v with weight wt
        }

        // Step 2: Perform Topological Sort using DFS
        vector<int> vis(V, 0);
        stack<int> st;
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, adj, vis, st);
            }
        }

        // Step 3: Find shortest path using the topological order
        vector<int> dist(V, 1e9);  // Initialize distance array with "infinity"
        dist[0] = 0;  // Source node has distance 0
        
        while (!st.empty()) {
            int curr = st.top();
            st.pop();
            
            // Process all adjacent nodes of the current node
            if (dist[curr] != 1e9) { // Only process if the node was reachable
                for (auto it : adj[curr]) {
                    int v = it.first;
                    int wt = it.second;
                    if (dist[curr] + wt < dist[v]) {
                        dist[v] = dist[curr] + wt; // Relaxation step
                    }
                }
            }
        }

        // Step 4: Convert "infinity" (1e9) to -1 for unreachable nodes
        for (int i = 0; i < V; i++) {
            if (dist[i] == 1e9) {
                dist[i] = -1;
            }
        }
        
        return dist;  // Return the final shortest path distances
    }
};
