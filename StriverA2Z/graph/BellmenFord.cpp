/*Given a weighted and directed graph of v vertices and edges, Find the shortest distance of all the vertex's from the source vertex, 
src and return a list of integers where the ith integer denotes the distance of the ith node from the source node. If a vertices can't be reach from 
the s then mark the distance as 10^8.
Note: If there exist a path to a negative weighted cycle from the source node then return {-1}.

Examples:

Input: edges = [[0,1,9]], src = 0

Output: [0, 9]
Explanation: Shortest distance of all nodes from source is printed.
Input: edges = [[0,1,5], [1,0,3], [1,2,-1], [2,0,1]], src = 2

Output: [1, 6, 0]
Explanation: For nodes 2 to 0, we can follow the path: 2-0. This has a distance of 1. 
For nodes 2 to 1, we cam follow the path: 2-0-1, which has a distance of 1+5 = 6,*/

vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
    vector<int> dist(V, 1e8); // Initialize distances to "infinity"
    dist[src] = 0; // Distance to source is 0

    // Relax all edges V-1 times
    for (int i = 0; i < V - 1; i++) {
        for (auto &edge : edges) {
            int u = edge[0], v = edge[1], wt = edge[2];
            if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
                dist[v] = dist[u] + wt;
            }
        }
    }

    // Check for negative weight cycle
    for (auto &edge : edges) {
        int u = edge[0], v = edge[1], wt = edge[2];
        if (dist[u] != 1e8 && dist[u] + wt < dist[v]) {
            cout << "Negative weight cycle detected!" << endl;
            return {}; // Return empty vector if a negative cycle is found
        }
    }

    return dist;
}

TC -> O(V*E);