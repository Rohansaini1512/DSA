/*You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

Example 1:


Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4
Example 2:

Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
Example 3:

Input: grid = [[0,2]]
Output: 0
Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.
*/

#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();    // Number of rows
        int m = grid[0].size(); // Number of columns

        queue<pair<pair<int, int>, int>> q; // Queue stores ((row, col), time)
        vector<vector<int>> vis(n, vector<int>(m, 0)); // Visited array

        // Step 1: Initialize queue with all initially rotten oranges
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {  // If the orange is rotten
                    q.push({{i, j}, 0});
                    vis[i][j] = 2; // Mark as visited
                }
            }
        }

        int tm = 0;  // Maximum time required for all oranges to rot

        // Arrays to move in 4 directions: up, left, down, right
        int drow[4] = {-1, 0, 1, 0};  
        int dcol[4] = {0, -1, 0, 1};

        // Step 2: Perform BFS to spread rot
        while (!q.empty()) {
            int r = q.front().first.first;  // Current row
            int c = q.front().first.second; // Current column
            int t = q.front().second;       // Time taken
            q.pop();
            tm = max(tm, t);  // Track the maximum time taken

            // Explore the 4 possible directions
            for (int i = 0; i < 4; i++) {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];

                // Check valid grid bounds and if the orange is fresh
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m 
                    && vis[nrow][ncol] != 2 && grid[nrow][ncol] == 1) {
                    
                    q.push({{nrow, ncol}, t + 1}); // Push to queue with updated time
                    vis[nrow][ncol] = 2; // Mark as rotten
                }
            }
        }

        // Step 3: Check if there are any fresh oranges left
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && vis[i][j] != 2) { 
                    return -1; // If a fresh orange is left, return -1
                }
            }
        }
        return tm; // Return the time required for all oranges to rot
    }
};
