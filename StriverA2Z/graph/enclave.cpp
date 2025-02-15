/*You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.

A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.

Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.

 

Example 1:


Input: grid = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
Output: 3
Explanation: There are three 1s that are enclosed by 0s, and one 1 that is not enclosed because its on the boundary.
Example 2:


Input: grid = [[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]
Output: 0
Explanation: All 1s are either on the boundary or can reach the boundary.*/

class Solution {
    int drow[4] = {-1,0,1,0};
    int dcol[4] = {0,-1,0,1};
    void dfs(int r, int c, vector<vector<int>>& g , vector<vector<int>>&vis){
        vis[r][c] = 1;
        int n = g.size();
        int m = g[0].size();
        for(int i = 0 ; i < 4 ; i++){
            int nrow = r+drow[i];
            int ncol = c+dcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && g[nrow][ncol] == 1){
                dfs(nrow,ncol,g,vis);
            }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));

        for(int i = 0 ; i < m ; i++){
            if(!vis[0][i] && grid[0][i] == 1){
                dfs(0,i,grid,vis);
            }
            if(!vis[n-1][i] && grid[n-1][i] == 1){
                dfs(n-1,i,grid,vis);
            }
        }
        for(int i = 0 ; i < n ; i++){
            if(!vis[i][0] && grid[i][0] == 1){
                dfs(i,0,grid,vis);
            }
            if(!vis[i][m-1] && grid[i][m-1] == 1){
                dfs(i,m-1,grid,vis);
            }
        }
        int res = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(!vis[i][j] && grid[i][j] == 1) res++;
            }
        }
        return res;
    }
};