/*
Follow up for "Unique Paths":
Now consider if some obstacles are added to the grids. How many unique paths would there be?
An obstacle and empty space is marked as 1 and 0 respectively in the grid.
For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.
[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.
*/

#include <vector>
#include <iostream>
#define min(a,b) (((a) < (b)) ? (a) : (b))

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int row = obstacleGrid.size();
    if(row <= 0) {
        return 0;
    }
    int col = obstacleGrid[0].size();
    std::vector<std::vector<int>> dp(row, std::vector<int>(col, 0));

    for(int j = 1; j < col; j++) {
        if(obstacleGrid[0][j] != 1) {
            dp[0][j] = 1;
        } else {
            break;
        }
    }

    for(int i = 0; i < row; i++) {
        if(obstacleGrid[i][0] != 1) {
            dp[i][0] = 1;
        } else {
            break;
        }
    }


    for(int i = 1; i < row; i++) {
        for(int j = 1; j < col; j++) {
            if(obstacleGrid[i][j] != 1) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
    }
    return dp[row-1][col-1];
}