#include<bits/stdc++.h>
using namespace std;

bool canWePlace(vector<vector<char>> &grid, int i , int j){
    if(i - 2 >= 0 && j - 1 >= 0 && grid[i - 2][j - 1] == 'K'){
        return false;
    }
    if(i - 2 >= 0 && j + 1 < grid[0].size() && grid[i - 2][j + 1] == 'K'){
        return false;
    }
    if(i - 1 >= 0 && j - 2 >= 0 && grid[i - 1][j - 2] == 'K'){
        return false;
    }
    if(i - 1 >= 0 && j + 2 < grid[0].size() && grid[i - 1][j + 2] == 'K'){
        return false;
    }
    return true;
}

void knights(int m , int n , vector<vector<char>> &grid , int k , int i , int j){
    if(k == 0){
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }
        // cout<<endl;
        return;
    }
    if(j == n){
        return knights(m, n, grid, k, i + 1, 0);
    }
    if(i == m){
        return ;
    }
    for (int row = i ; row < m ; row++){
        for(int col = (row == i ? j : 0) ; col < n ; col++){
            if(canWePlace(grid, row, col)){
                grid[row][col] = 'K';
                knights(m, n, grid, k - 1, row, col + 1);
                grid[row][col] = '.';
            }
        }
    }
    // if(canWePlace(grid , i , j)){
    //     grid[i][j] = 'K';
    //     knights(m, n, grid, k , i, j + 1);
    //     grid[i][j] = '.';
    // }
}

int main(){
    int m , n , k;
    cin>>m>>n>>k;
    vector<vector<char>> grid(m, vector<char>(n, '.'));
    knights(m, n, grid, k, 0, 0);
    return 0;
}