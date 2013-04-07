/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 7, 2013
 Problem:    Edit Distance
 Difficulty: Medium
 Source:     http://leetcode.com/onlinejudge#question_72
 Notes:
 Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)
 You have the following 3 operations permitted on a word:
 a) Insert a character
 b) Delete a character
 c) Replace a character

 Solution: Dynamic Programming.
		   Time complexity: O(mn)
		   Space complexity: O(mn)
 */

class Solution {
public:
    int minDistance(string word1, string word2) {
        size_t M = word1.size();
        size_t N = word2.size();
        
        int dp[N+1][M+1];
        for (int j = 0; j <= M; j++)
            dp[0][j] = j;
        for (int i = 0; i <= N; i++)
            dp[i][0] = i;
        
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= M; j++)
                if (word2[i-1] == word1[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j])) + 1;
        
        return dp[N][M];
    }
};