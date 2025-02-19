/*Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return -1.

A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:

All the visited cells of the path are 0.
All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).
The length of a clear path is the number of visited cells of this path.

 

Example 1:


Input: grid = [[0,1],[1,0]]
Output: 2
Example 2:


Input: grid = [[0,0,0],[1,1,0],[1,1,0]]
Output: 4
Example 3:

*/

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(grid[0][0] != 0 || grid[n-1][m-1] != 0) return -1;
        if (n == 1 && m == 1) return 1;

        vector<vector<int>>dis(n,vector<int>(m,1e9));
        dis[0][0] = 1;
        int drow[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dcol[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
        queue<pair<int ,pair<int,int>>>q;
        q.push({1,{0,0}});
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int dist = it.first;
            int r = it.second.first;
            int c = it.second.second;

            for(int i = 0 ; i < 8 ; i++){
                int nrow = r+drow[i];
                int ncol = c+dcol[i];
                if(nrow < n && nrow >= 0 && ncol < m && ncol >= 0 && grid[nrow][ncol] == 0 && dist + 1 < dis[nrow][ncol]){
                    dis[nrow][ncol] = 1 + dist;
                    if(nrow == n-1 && ncol == m-1) return 1+dist;
                    q.push({1+dist , {nrow,ncol}});
                }

            }
        }
        return -1;
    }
};