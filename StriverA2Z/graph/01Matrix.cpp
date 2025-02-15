/*Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

The distance between two cells sharing a common edge is 1.

 

Example 1:


Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
Output: [[0,0,0],[0,1,0],[0,0,0]]
Example 2:


Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
Output: [[0,0,0],[0,1,0],[1,2,1]]
 

*/

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> res(n, vector<int>(m, INT_MAX));  // Initialize with large value
        queue<pair<int, int>> q;

        // **Fix 1:** Push all 0s into the queue first, mark them as visited
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    q.push({i, j});
                    res[i][j] = 0;  // Distance for 0s is 0
                }
            }
        }

        int drow[4] = {-1, 0, 1, 0};
        int dcol[4] = {0, -1, 0, 1};

        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];

                // **Fix 2:** Process only unvisited or cells where a shorter distance is found
                if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m) {
                    if (res[nrow][ncol] > res[r][c] + 1) {
                        res[nrow][ncol] = res[r][c] + 1;
                        q.push({nrow, ncol});
                    }
                }
            }
        }
        return res;
    }
};
