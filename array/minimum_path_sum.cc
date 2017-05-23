/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.
Note: You can only move either down or right at any point in time.
*/

#include <vector>
#include <iostream>

int minPathSum(std::vector<std::vector<int>>& grid) {
    int row = grid.size();
    if (row <= 0) {
        return 0;
    }
    int col = grid[0].size();
    int dp[row][col];
    dp[0][0] = grid[0][0];
    for(int i = 1; i < row; i++) {
        dp[i][0] = dp[i-1][0] + grid[i][0];
    }

    for(int j = 1; j < col; j++) {
        dp[0][j] = dp[0][j-1] + grid[0][j];
    }

    for(int i = 1; i < row; i++) {
        for(int j = 1; j < col; j++) {
            dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j]; 
        }
    }

    return dp[row-1][col-1]
}

int minPathSum(std::vector<std::vector<int>>& grid) {
    int row = grid.size();
    if (row <= 0) {
        return 0;
    }
    int col = grid[0].size();
    int dp[row];
    dp[0] = grid[0][0];

    for(int i = 1; i < row; i++) {
        dp[i] = dp[i-1] + grid[i][0];
    }

    for(int j = 1; j < col; j++) {
        dp[0] += grid[0][j];
        for(int i = 1; i < row; i++) {
            dp[i] = min(dp[i-1], dp[i]) + grid[i][j];
        }
    }
    return dp[row-1];
}



