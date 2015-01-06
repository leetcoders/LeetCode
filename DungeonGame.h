/*
 Author:     King, wangjingui@outlook.com
 Date:       Jan 6, 2015
 Problem:    Dungeon Game
 Difficulty: Easy
 Source:     https://oj.leetcode.com/problems/dungeon-game/
 Notes:
 The demons had captured the princess (P) and imprisoned her in the bottom-right corner of a dungeon. The dungeon consists of M x N rooms laid out in a 2D grid. Our valiant knight (K) was initially positioned in the top-left room and must fight his way through the dungeon to rescue the princess.

 The knight has an initial health point represented by a positive integer. If at any point his health point drops to 0 or below, he dies immediately.

 Some of the rooms are guarded by demons, so the knight loses health (negative integers) upon entering these rooms; other rooms are either empty (0's) or contain magic orbs that increase the knight's health (positive integers).

 In order to reach the princess as quickly as possible, the knight decides to move only rightward or downward in each step.


 Write a function to determine the knight's minimum initial health so that he is able to rescue the princess.

 For example, given the dungeon below, the initial health of the knight must be at least 7 if he follows the optimal path RIGHT-> RIGHT -> DOWN -> DOWN.

 -2 (K)  -3  3
 -5  -10 1
 10  30  -5 (P)

 Notes:

 The knight's health has no upper bound.
 Any room can contain threats or power-ups, even the first room the knight enters and the bottom-right room where the princess is imprisoned.

 Solution: ...
 */
class Solution {
public:
    int calculateMinimumHP(vector<vector<int> > &dungeon) {
        int M = dungeon.size(), res = 0;
        if (M == 0) return res;
        int N = dungeon[0].size();
        vector<vector<int>> dp(M, vector<int>(N,0));
        dp[M-1][N-1] = 1 - min(0, dungeon[M-1][N-1]);
        for (int i = M - 2; i >= 0; --i) {
            if (dp[i+1][N-1] - dungeon[i][N-1] < 0) dp[i][N-1] = 1;
            else dp[i][N-1] = dp[i+1][N-1] - dungeon[i][N-1]; 
        }
        for (int j = N - 2; j >= 0; --j) {
            if (dp[M-1][j+1] - dungeon[M-1][j] < 0) dp[M-1][j] = 1;
            else dp[M-1][j] = dp[M-1][j+1] - dungeon[M-1][j];
        }
        for (int i = M - 2; i >= 0; --i) {
            for (int j = N - 2; j >= 0; --j) {
                int val = min(dp[i+1][j], dp[i][j+1]);
                if (dungeon[i][j] > val) dp[i][j] = 1;
                else dp[i][j] = val - dungeon[i][j];
            }
        }
        return max(1,dp[0][0]);
    }
};