/*You are given an n x n binary matrix grid. You are allowed to change at most one 0 to be 1.

Return the size of the largest island in grid after applying this operation.

An island is a 4-directionally connected group of 1s.

 

Example 1:

Input: grid = [[1,0],[0,1]]
Output: 3
Explanation: Change one 0 to 1 and connect two 1s, then we get an island with area = 3.
Example 2:

Input: grid = [[1,1],[1,0]]
Output: 4
Explanation: Change the 0 to 1 and make the island bigger, only one island with area = 4.
Example 3:

Input: grid = [[1,1],[1,1]]
Output: 4
Explanation: Can't change any 0 to 1, only one island with area = 4.*/

class DisjointSet {
public:
    vector<int> rank, parent, size;

    // Constructor to initialize the Disjoint Set with 'n' elements
    DisjointSet(int n) {
        rank.resize(n + 1, 0);  // Initialize rank to 0
        parent.resize(n + 1);    // Parent array to track leaders
        size.resize(n + 1, 1);   // Size array to track component sizes
        for (int i = 0; i <= n; i++) {
            parent[i] = i;  // Initially, each element is its own parent
        }
    }

    // Find function with path compression to optimize future lookups
    int find(int node) {
        if (node == parent[node]) {
            return node;  // If the node is its own parent, return it
        }
        return parent[node] = find(parent[node]);  // Path compression
    }

    // Union function based on rank (to keep tree balanced)
    void unionByrank(int u, int v) {
        int rootU = find(u);  // Find ultimate parent of u
        int rootV = find(v);  // Find ultimate parent of v
        if (rootU == rootV) return;  // Already in the same component

        // Merge smaller tree into the larger one
        if (rank[rootU] < rank[rootV]) {
            parent[rootU] = rootV;
            size[rootV] += size[rootU];  // Update size of rootV
        } else if (rank[rootV] < rank[rootU]) {
            parent[rootV] = rootU;
            size[rootU] += size[rootV];  // Update size of rootU
        } else {
            parent[rootV] = rootU;  // Merge V into U
            rank[rootU]++;          // Increase rank of U
            size[rootU] += size[rootV];  // Update size of rootU
        }
    }
};

class Solution {
private:
    // Function to check if a given row, col index is within grid bounds
    bool isValid(int r, int c, int n) {
        return r >= 0 && c >= 0 && r < n && c < n;
    }
    
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n * n);  // Disjoint set for n*n elements (flattened grid)

        int dr[4] = {-1, 0, 1, 0};  // Directions for row (Up, Right, Down, Left)
        int dc[4] = {0, 1, 0, -1};  // Directions for col (Up, Right, Down, Left)

        // Step 1: Merge all existing 1s into connected components
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 0) continue;  // Ignore water cells (0)

                int nodeNo = r * n + c;  // Convert 2D index to 1D

                // Check all 4 directions
                for (int i = 0; i < 4; i++) {
                    int nr = r + dr[i];  // Neighbor row
                    int nc = c + dc[i];  // Neighbor col
                    if (isValid(nr, nc, n) && grid[nr][nc] == 1) {
                        int adjNodeNo = nr * n + nc;  // Convert neighbor to 1D index
                        ds.unionByrank(nodeNo, adjNodeNo);  // Merge components
                    }
                }
            }
        }

        // Step 2: Try flipping a 0 to 1 and calculate max possible island
        int mx = 0;  // Variable to store max island size
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 1) continue;  // Skip land cells (1)

                set<int> components;  // Store unique component parents (to avoid duplicates)

                // Check all 4 directions for adjacent islands
                for (int i = 0; i < 4; i++) {
                    int nr = r + dr[i];
                    int nc = c + dc[i];
                    if (isValid(nr, nc, n) && grid[nr][nc] == 1) {
                        components.insert(ds.find(nr * n + nc));  // Find parent of neighbor
                    }
                }

                int total = 1;  // Include the flipped cell in the island size
                for (int parent : components) {
                    total += ds.size[parent];  // Add size of each unique component
                }

                mx = max(mx, total);  // Update max island size
            }
        }

        // Step 3: If the entire grid is already 1s, find the max existing island
        for (int i = 0; i < n * n; i++) {
            if (ds.find(i) == i) {  // Only consider root components
                mx = max(mx, ds.size[i]);
            }
        }

        return mx;  // Return the maximum island size possible
    }
};
