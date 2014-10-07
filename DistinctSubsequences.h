/*
 Author:     Annie Kim, anniekim.pku@gmail.com : King, higuige@gmail.com
 Date:       May 16, 2013
 Update:     Oct 07, 2014
 Problem:    Distinct Subsequences
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_115
 Notes:
 Given a string S and a string T, count the number of distinct subsequences of T in S.
 A subsequence of a string is a new string which is formed from the original string by deleting
 some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

 Here is an example:
 S = "rabbbit", T = "rabbit"
 Return 3.

 Solution: dp.
 */
class Solution {
public:
    int numDistinct(string S, string T) {
        return numDistinct_2(S, T);
    }
    int numDistinct_1(string S, string T) {
        int M = S.size();
        int N = T.size();
        vector<vector<int> > dp(M+1, vector<int>(N+1));
        for (int j = 0; j <= N; ++j) {
            dp[0][j] = 0;
        }
        for (int i = 0; i <= M; ++i) {
            dp[i][0] = 1;
        }
        for (int i = 1; i <= M; ++i) {
            for (int j = 1; j <= N; ++j) {
                dp[i][j] = dp[i-1][j] + (S[i-1] == T[j-1] ? dp[i-1][j-1] : 0);
            }
        }
        return dp[M][N];
    }
    int numDistinct_2(string S, string T) {
        int M = S.size();
        int N = T.size();
        vector<int> dp(N + 1);
        dp[0] = 1;
        for (int i = 1; i <= M; ++i) {
            for (int j = N; j >=1; --j) {
                dp[j] = dp[j] + (S[i-1] == T[j-1] ? dp[j-1] : 0);
            }
        }
        return dp[N];
    }
};