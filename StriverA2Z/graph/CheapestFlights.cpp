/*There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.

You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.

 

Example 1:


Input: n = 4, flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]], src = 0, dst = 3, k = 1
Output: 700
Explanation:
The graph is shown above.
The optimal path with at most 1 stop from city 0 to 3 is marked in red and has cost 100 + 600 = 700.
Note that the path through cities [0,1,2,3] is cheaper but is invalid because it uses 2 stops.
Example 2:


Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 1
Output: 200
Explanation:
The graph is shown above.
The optimal path with at most 1 stop from city 0 to 2 is marked in red and has cost 100 + 100 = 200.
Example 3:


Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 0
Output: 500
Explanation:
The graph is shown above.
The optimal path with no stops from city 0 to 2 is marked in red and has cost 500.
 

*/

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Create an adjacency list where each node stores a list of {destination, weight}
        vector<pair<int, int>> adj[n];
        for (auto it : flights) {
            adj[it[0]].push_back({it[1], it[2]}); // Add edge from it[0] to it[1] with weight it[2]
        }

        // Queue to store {stops, {current_node, current_distance}}
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}}); // Start from src with 0 stops and distance 0

        // Distance array initialized with a large value (infinity)
        vector<int> dist(n, 1e9);
        dist[src] = 0; // Distance to source is 0

        // BFS-style traversal with at most k stops
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int stops = it.first;         // Current number of stops
            int node = it.second.first;   // Current node
            int dis = it.second.second;   // Current distance

            // Explore all adjacent nodes
            for (auto i : adj[node]) {
                int adjNode = i.first;    // Neighbor node
                int ew = i.second;        // Edge weight

                // If the new distance is smaller and within allowed stops, update and push
                if (dis + ew < dist[adjNode] && stops <= k) {
                    dist[adjNode] = dis + ew;
                    q.push({stops + 1, {adjNode, dis + ew}});
                }
            }
        }

        // If destination remains unreachable, return -1
        return (dist[dst] == 1e9) ? -1 : dist[dst];
    }
};
