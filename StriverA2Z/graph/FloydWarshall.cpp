/*The problem is to find the shortest distances between every pair of vertices in a given edge-weighted directed graph. 
The graph is represented as an adjacency matrix. mat[i][j] denotes the weight of the edge from i to j. If mat[i][j] = -1, 
it means there is no edge from i to j.
Note: Modify the distances for every pair in place.

Examples :

Input: mat = [[0, 25], [-1, 0]]

Output: [[0, 25], [-1, 0]]

Explanation: The shortest distance between every pair is already given(if it exists).
Input: mat = [[0, 1, 43],[1, 0, 6], [-1, -1, 0]]

Output: [[0, 1, 7], [1, 0, 6], [-1, -1, 0]]

Explanation: We can reach 2 from 0 as 0->1->2 and the cost will be 1+6=7 which is less than 43.*/

void shortestDistance(vector<vector<int>>& mat) {
    // Get the number of vertices in the graph
    int n = mat.size();

    // Step 1: Initialize the matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // If there is no direct path, set distance to a large value (infinity)
            if (mat[i][j] == -1) {
                mat[i][j] = 1e9;  
            }
            // Distance to itself is always 0
            if (i == j) mat[i][j] = 0;  
        }
    }

    // Step 2: Apply Floyd-Warshall Algorithm
    for (int k = 0; k < n; k++) {  // Intermediate node
        for (int i = 0; i < n; i++) {  // Source node
            for (int j = 0; j < n; j++) {  // Destination node
                // Relaxation step: Update the shortest path from i to j using k
                mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
            }
        }
    }

    // Step 3: Convert large values (infinity) back to -1 (for unreachable nodes)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == 1e9) {
                mat[i][j] = -1;
            }
        }
    }
}

