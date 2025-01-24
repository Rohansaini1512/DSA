/*There is a directed graph of n nodes with each node labeled from 0 to n - 1. The graph is represented by a 0-indexed 2D integer array graph where graph[i] is an integer array of nodes adjacent to node i, meaning there is an edge from node i to each node in graph[i].

A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to a terminal node (or another safe node).

Return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.

 

Example 1:

Illustration of graph
Input: graph = [[1,2],[2,3],[5],[0],[5],[],[]]
Output: [2,4,5,6]
Explanation: The given graph is shown above.
Nodes 5 and 6 are terminal nodes as there are no outgoing edges from either of them.
Every path starting at nodes 2, 4, 5, and 6 all lead to either node 5 or 6.
Example 2:

Input: graph = [[1,2,3,4],[1,2],[3,4],[0,4],[]]
Output: [4]
Explanation:
Only node 4 is a terminal node, and every path starting at node 4 leads to node 4.
*/


class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> rev(n);
        vector<int>inDeg(n,0);
        queue<int>q;

        // // Build the reversed graph and calculate in-degrees
        for(int u = 0 ; u < n ; u++){
            for(int v : graph[u]){
                rev[v].push_back(u);
                inDeg[u]++;
            }
        }

        // Initialize queue with nodes having in-degree 0 (terminal nodes)
        for(int i = 0 ; i < n ; i++){
            if(inDeg[i] == 0) q.push(i);
        }

        // Topological sort using the reversed graph
        vector<int>safe;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            safe.push_back(node);
            for (int neigh : rev[node]) {
                inDeg[neigh]--;
                if (inDeg[neigh] == 0) q.push(neigh);
            }
        }

        // Sort safe nodes in ascending order
        sort(safe.begin() , safe.end());
        return safe;
    }
};