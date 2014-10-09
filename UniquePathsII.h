/*
 Author:     Annie Kim, anniekim.pku@gmail.com : King, higuige@gmail.com
 Date:       Apr 9, 2013
 Update:     Oct 9, 2014
 Problem:    Unique Paths II
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_63
 Notes:
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
 Note: m and n will be at most 100.

 Solution: Dynamic programming.
 */

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        int dp[m][n];
        if (obstacleGrid[0][0] == 1) return 0;
        dp[0][0] = 1;
        for (int i = 1; i < m; i++)
            dp[i][0] = obstacleGrid[i][0] == 1 ? 0 : dp[i-1][0];
        for (int j = 1; j < n; j++)
            dp[0][j] = obstacleGrid[0][j] == 1 ? 0 : dp[0][j-1];
        
        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                dp[i][j] = obstacleGrid[i][j] == 1 ? 0: dp[i-1][j] + dp[i][j-1];
        
        return dp[m-1][n-1];
    }
    int uniquePathsWithObstacles_2(vector<vector<int> > &obstacleGrid) {
        int m = obstacleGrid.size();
        if (m == 0) return 0;
        int n = obstacleGrid[0].size();
        vector<int> dp(n+1,0);
        if(obstacleGrid[0][0] || obstacleGrid[m-1][n-1]) return 0;
        dp[1] = 1;
        for (int i = 1; i <= m; ++i) {
            dp[1] = obstacleGrid[i-1][0] ? 0 : dp[1];
            for(int j = 2; j <= n; ++j) {
                 dp[j] = obstacleGrid[i - 1][j - 1] == 1 ? 0: dp[j] + dp[j-1];
            }
        }
        return dp[n];
    }
};
