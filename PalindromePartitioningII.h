/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       May 23, 2013
 Update:     Sep 23, 2013
 Problem:    Palindrome Partitioning II
 Difficulty: Hard
 Source:     http://leetcode.com/onlinejudge#question_132
 Notes:
 Given a string s, partition s such that every substring of the partition is a palindrome.
 Return the minimum cuts needed for a palindrome partitioning of s.
 For example, given s = "aab",
 Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.

 Solution: dp. Contributed by 孙冕. Great job:)
 */

class Solution {
public:
    int minCut(string s) {
        int size = s.size();
        vector<int> dp(size + 1);
        vector<bool> isP(size, true);
        dp[size] = -1;
        for (int i = size -1; i >= 0; --i) {
            dp[i] = dp[i + 1] + 1;
            for (int j = size - 1; j >= i; --j) {
                isP[j] = false;
                if (s[i] == s[j] && ( j - i < 2 || isP[j-1])) {
                    isP[j] = true;
                    dp[i] = min(dp[i], dp[j + 1] + 1);
                }
            }
        }
        return dp[0];
    }
};