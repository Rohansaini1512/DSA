/*Given an undirected graph with V vertices labelled from 0 to V-1 and E edges, check whether the graph contains any cycle or not. The Graph is represented as an adjacency list, where adj[i] contains all the vertices that are directly connected to vertex i.

NOTE: The adjacency list represents undirected edges, meaning that if there is an edge between vertex i and vertex j, both j will be adj[i] and i will be in adj[j].

Examples:

Input: adj = [[1], [0,2,4], [1,3], [2,4], [1,3]] 
Output: 1
Explanation: 

1->2->3->4->1 is a cycle.
Input: adj = [[], [2], [1,3], [2]]
Output: 0
Explanation: 

No cycle in the graph.*/

// DFS 

#include <vector>
using namespace std;

class Solution {
private:
    bool dfs(int node, int par, vector<int>& vis, vector<vector<int>>& adj) {
        vis[node] = 1; // Mark as visited

        for (auto neigh : adj[node]) {
            if (!vis[neigh]) { 
                if (dfs(neigh, node, vis, adj)) {
                    return true; // Cycle found
                }
            } else if (neigh != par) { 
                return true; // Cycle detected (not a parent)
            }
        }
        return false;
    }

public:
    bool isCycle(vector<vector<int>>& adj) {
        int n = adj.size(); // Get number of nodes
        vector<int> vis(n, 0); // Visited array

        for (int i = 0; i < n; i++) { 
            if (!vis[i]) { // Check all components
                if (dfs(i, -1, vis, adj)) {
                    return true; // Cycle found
                }
            }
        }
        return false; // No cycle
    }
};


// BFS
class Solution {
    bool detect(int st , vector<vector<int>>&adj , vector<int>&vis){
        queue<pair<int,int>>q;
        q.push({st,-1});
        vis[st] = 1;
        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            
            for(auto neigh:adj[node]){
                if(!vis[neigh]){
                    vis[neigh] = 1;
                    q.push({neigh , node});
                }else if(neigh != parent){
                    return true;
                }
            }
        }
        return false;
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(vector<vector<int>>& adj) {
        // Code here
        int n = adj.size();
        vector<int> vis(n, 0); // Visited array

        for (int i = 0; i < n; i++) {
            if (!vis[i]) { // Check all components
                if (detect(i, adj, vis)) {
                    return true;
                }
            }
        }
        return false;
    }
};