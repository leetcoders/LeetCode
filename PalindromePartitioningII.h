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
        int N = s.size();
        bool isP[N];
        int dp[N];
        dp[0] = 0;
        for (int i = 1; i < N; ++i) 
        {
            isP[i] = true;
            dp[i] = dp[i-1] + 1;
            for (int j = 0; j < i; ++j) 
            {
                isP[j] = (s[i] == s[j]) ? isP[j+1] : false; // isP[j] == true   -> [j...i] is a palindrome
                                                            // isP[j+1] == true -> [j+1...i-1] is a palindrome
                if (isP[j])
                    dp[i] = (j == 0) ? 0 : min(dp[i], dp[j-1] + 1);  // dp[i] -> minCount for [0...i]
            }
        }
        return dp[N-1];
    }
};
