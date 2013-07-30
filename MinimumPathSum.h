/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 17, 2013
 Update:     Jul 30, 2013
 Problem:    Minimum Path Sum
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_64
 Notes:
 Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right 
 which minimizes the sum of all numbers along its path.
 Note: You can only move either down or right at any point in time.

 Solution: Dynamic Programming. Space O(N).
 */

class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        if (grid.empty()) return INT_MIN;
        int M = grid.size(), N = grid[0].size();
        int dp[N];
        dp[0] = grid[0][0];
        for (int i = 1; i < N; ++i)
            dp[i] = grid[0][i] + dp[i-1];
        
        for (int i = 1; i < M; ++i)
        {
            dp[0] += grid[i][0];
            for (int j = 1; j < N; ++j)
                dp[j] = min(dp[j-1], dp[j]) + grid[i][j];
        }
        
        return dp[N-1];
    }
};
