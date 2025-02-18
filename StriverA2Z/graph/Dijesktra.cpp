/*Given a weighted, undirected and connected graph where you have given adjacency list adj. You have to find the shortest distance of all the vertices from the source vertex src, and return a list of integers denoting the shortest distance between each node and source vertex src.

Note: The Graph doesn't contain any negative weight edge.

Examples:

Input: adj = [[[1, 9]], [[0, 9]]], src = 0
Output: [0, 9]
Explanation:

The source vertex is 0. Hence, the shortest distance of node 0 is 0 and the shortest distance from node 0 to 1 is 9.
Input: adj = [[[1, 1], [2, 6]], [[2, 3], [0, 1]], [[1, 3], [0, 6]]], src = 2
Output: [4, 3, 0]
Explanation:

For nodes 2 to 0, we can follow the path 2-1-0. This has a distance of 1+3 = 4, whereas the path 2-0 has a distance of 6. So, the Shortest path from 2 to 0 is 4.
The shortest distance from 0 to 1 is 1 .*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to find the shortest distance of all vertices from the source vertex src.
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
        // Min-heap priority queue: (distance, node)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        int n = adj.size(); // Number of vertices
        vector<int> dist(n, 1e9); // Initialize all distances to "infinity"
        
        dist[src] = 0; // Distance to source is 0
        pq.push({0, src}); // Push source to priority queue
        
        while (!pq.empty()) {
            int curr = pq.top().second; // Current node
            int currDist = pq.top().first; // Current node's distance
            pq.pop();
            
            // Explore all neighbors of the current node
            for (auto it : adj[curr]) {
                int node = it.first;  // Neighboring node
                int ewt = it.second;  // Edge weight
                
                // If a shorter path to 'node' is found, update it
                if (currDist + ewt < dist[node]) {
                    dist[node] = currDist + ewt; // Update shortest path
                    pq.push({dist[node], node}); // Push updated node to priority queue
                }
            }
        }
        
        return dist; // Return the shortest distance array
    }
};
