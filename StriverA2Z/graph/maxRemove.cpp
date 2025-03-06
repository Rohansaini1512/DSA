/*On a 2D plane, we place n stones at some integer coordinate points. Each coordinate point may have at most one stone.

A stone can be removed if it shares either the same row or the same column as another stone that has not been removed.

Given an array stones of length n where stones[i] = [xi, yi] represents the location of the ith stone, return the largest possible number of stones that can be removed.

 

Example 1:

Input: stones = [[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]
Output: 5
Explanation: One way to remove 5 stones is as follows:
1. Remove stone [2,2] because it shares the same row as [2,1].
2. Remove stone [2,1] because it shares the same column as [0,1].
3. Remove stone [1,2] because it shares the same row as [1,0].
4. Remove stone [1,0] because it shares the same column as [0,0].
5. Remove stone [0,1] because it shares the same row as [0,0].
Stone [0,0] cannot be removed since it does not share a row/column with another stone still on the plane.
Example 2:

Input: stones = [[0,0],[0,2],[1,1],[2,0],[2,2]]
Output: 3
Explanation: One way to make 3 moves is as follows:
1. Remove stone [2,2] because it shares the same row as [2,0].
2. Remove stone [2,0] because it shares the same column as [0,0].
3. Remove stone [0,2] because it shares the same row as [0,0].
Stones [0,0] and [1,1] cannot be removed since they do not share a row/column with another stone still on the plane.
Example 3:

Input: stones = [[0,0]]
Output: 0
Explanation: [0,0] is the only stone on the plane, so you cannot remove it.
 */

class DisjointSet{
    public:
        vector<int> rank, parent, size;
        
        // Constructor to initialize the DSU structure
        DisjointSet(int n){
            rank.resize(n+1, 0);    // Ranks initialized to 0
            parent.resize(n+1);     // Parent array initialized
            size.resize(n+1, 1);    // Size array initialized to 1
            
            // Initially, each node is its own parent
            for(int i = 0; i <= n; i++){
                parent[i] = i;
            }
        }

        // Find the ultimate parent of a node with path compression
        int find(int node){
            if(node == parent[node]){
                return node;       // If node is parent of itself
            }
            return parent[node] = find(parent[node]);  // Path compression
        }

        // Union two components based on rank
        void unionByrank(int u, int v){
            int ulp_u = find(u);  // Find ultimate parent of u
            int ulp_v = find(v);  // Find ultimate parent of v
            
            if(ulp_u == ulp_v) return;  // Already in the same component
            
            // Union by rank
            if(rank[ulp_u] < rank[ulp_v]){
                parent[ulp_u] = ulp_v;  // Attach smaller tree under larger tree
            }
            else if(rank[ulp_v] < rank[ulp_u]){
                parent[ulp_v] = ulp_u; 
            }
            else{
                parent[ulp_v] = ulp_u;  // If ranks are equal, attach one under the other
                rank[ulp_u]++;         // Increase rank
            }
        }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int maxRow = 0;
        int maxCol = 0;
        
        // Step 1: Find the maximum row and column values
        for(auto it : stones){
            maxRow = max(maxRow, it[0]);  // Maximum row index
            maxCol = max(maxCol, it[1]);  // Maximum column index
        }

        // Step 2: Create Disjoint Set with size (maxRow + maxCol + 1)
        DisjointSet ds(maxRow + maxCol + 1);
        unordered_map<int, int> mp;  // To track unique nodes
        
        // Step 3: Connect nodes using union operations
        for(auto it : stones){
            int nodeRow = it[0];               // Row index
            int nodeCol = it[1] + maxRow + 1;  // Column index (offset added)
            
            ds.unionByrank(nodeRow, nodeCol);  // Union operation
            mp[nodeRow] = 1;                  // Mark row as present
            mp[nodeCol] = 1;                  // Mark column as present
        }

        // Step 4: Count number of connected components
        int cnt = 0;
        for(auto it : mp){
            if(ds.find(it.first) == it.first){  // If node is its own parent
                cnt++;
            }
        }

        // Step 5: Maximum stones removed = Total stones - Number of components
        return stones.size() - cnt;
    }
};
