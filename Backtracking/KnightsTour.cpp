#include <bits/stdc++.h>
using namespace std;

bool f(vector<vector<int>> &grid, int i, int j, int n, int m, int cnt) {
    if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] >= 0) {
        return false;
    }
    if (cnt == n * m) { // Corrected termination condition
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }
        return true;
    }
    grid[i][j] = cnt;
    // Attempt to move the knight in all 8 possible directions
    if (f(grid, i + 2, j + 1, n, m, cnt + 1) ||
        f(grid, i + 2, j - 1, n, m, cnt + 1) ||
        f(grid, i - 2, j + 1, n, m, cnt + 1) ||
        f(grid, i - 2, j - 1, n, m, cnt + 1) ||
        f(grid, i + 1, j + 2, n, m, cnt + 1) ||
        f(grid, i + 1, j - 2, n, m, cnt + 1) ||
        f(grid, i - 1, j + 2, n, m, cnt + 1) ||
        f(grid, i - 1, j - 2, n, m, cnt + 1)) {
        return true;
    }
    grid[i][j] = -1; // Mark the cell as unvisited
    return false;
}

int main() {
    int n = 3; // Size of the grid
    vector<vector<int>> grid(n, vector<int>(n, -1));
    if (!f(grid, 0, 0, n, n, 0)) {
        cout << "No solution found" << endl;
    }
    return 0;
}
