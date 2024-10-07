#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<char>>& grid, int i, int j) {
    int m = grid.size();
    int n = grid[0].size();

    if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != '1') {
        return;
    }

    grid[i][j] = '0'; // Mark as visited

    dfs(grid, i + 1, j); 
    dfs(grid, i - 1, j);
    dfs(grid, i, j + 1);
    dfs(grid, i, j - 1);
}

int numIslands(vector<vector<char>>& grid) {
    int m = grid.size();
    if (m == 0) {
        return 0;
    }
    int n = grid[0].size();
    int count = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '1') {
                dfs(grid, i, j);
                count++; 
            }
        }
    }

    return count;
}

int main() {
    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '1', '0', '0'},
        {'0', '1', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };

    cout << numIslands(grid) << endl; 

    return 0;
}
