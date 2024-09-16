#include<iostream>
#include<vector>
using namespace std;

bool canWeGo(int a , int b , vector<vector<int>> &grid){
    return a >= 0 && a < grid.size() && b >= 0 && b < grid[0].size() && grid[a][b] == 1;
}

int f(int i , int j , vector<vector<int>> &grid){
    int n = grid.size();
    if(i == n - 1 && j == n - 1){
        return 1;
    }
    int ans = 0;
    grid[i][j] = 2;
    if(canWeGo(i + 1, j, grid)){
        ans = ans + f(i + 1, j, grid);
    }
    if(canWeGo(i, j + 1, grid)){
        ans = ans + f(i, j + 1, grid);
    }
    if(canWeGo(i - 1, j, grid)){
        ans = ans + f(i - 1, j, grid);
    }
    if(canWeGo(i, j - 1, grid)){
        ans = ans + f(i, j - 1, grid);
    }
    grid[i][j] = 1;
    return ans;
    
}

int main(){
    vector<vector<int>> grid = {{1, 1, 1, 1},
                                 {1, 1, 0, 1},
                                 {0, 1, 0, 1},
                                 {1, 1, 1, 1}};
    cout<<f(0, 0, grid)<<endl;
    return 0;
}