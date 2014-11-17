/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Jul 13, 2013
 Update:      Nov 17, 2014 : By wangjingui@outlook.com
 Problem:    Longest Palindromic Substring
 Difficulty: Medium
 Source:     http://leetcode.com/onlinejudge#question_5
 Notes:
 Given a string S, find the longest palindromic substring in S. 
 You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.

 Solution: 1. Time O(n^2), Space O(n^2)
           2. Time O(n^2), Space O(n)
           3. Time O(n^2), Space O(1) (actually much more efficient than 1 & 2)
           4. Time O(n), Space O(n) (Manacher's Algorithm)
 */

class Solution {
public:
    string longestPalindrome(string s) {
        return longestPalindrome_4(s);
    }
    string longestPalindrome_1(string s) {
        int N = s.size();
        bool dp[N][N];
        pair<int, int> res = make_pair(0, 0); // start pos and length
        for (int k = 0; k < N; ++k) // length
        {
            for (int i = 0; i < N-k; ++i) // start pos
            {
                if (k == 0 || k == 1) 
                    dp[i][i+k] = s[i] == s[i+k];
                else 
                    dp[i][i+k] = (s[i] == s[i+k]) ? dp[i+1][i+k-1] : false;
                
                if (dp[i][i+k] && k+1 > res.second)
                    res = make_pair(i, k+1);
            }
        }
        return s.substr(res.first, res.second);
    }

    string longestPalindrome_2(string s) {
        int N = s.size();
        bool dp[2][N];
        pair<int, int> res = make_pair(0, 0);
        int cur = 1, last = 0;
        for (int i = 0; i < N; ++i)
        {
            cur = !cur; last = !last;
            for (int j = i; j >= 0; --j)
            {
                if (j == i || j == i-1)
                    dp[cur][j] = s[j] == s[i];
                else
                    dp[cur][j] = s[j] == s[i] && dp[last][j+1];

                if (dp[cur][j] && i-j+1 > res.second)
                    res = make_pair(j, i-j+1);
            }
        }
        return s.substr(res.first, res.second);
    }

    string longestPalindrome_3(string s) {
        int N = s.size();
        pair<int, int> res = make_pair(0, 0); // start pos and length
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j <= 1; ++j) {
                bool isP = true;
                for (int k = 0; i-k >= 0 && i+j+k < N && isP; ++k) {
                    isP = s[i-k] == s[i+j+k];
                    if (isP && j+1+k*2 > res.second)
                        res = make_pair(i-k, j+1+k*2);
                }
            }
        }
        return s.substr(res.first, res.second);
    }

    string longestPalindrome_4(string s) {
        int N = s.size();
        int dp[2 * N + 1];
        int id = 0, mx = 0;
        for (int i = 0; i < 2 * N + 1; ++i)
        {
            int j = 2 * id - i;
            dp[i] = mx > i ? min(dp[j], mx - i) : 1;
            int left = i - dp[i], right = i + dp[i];
            for (; left >= 0 && right <= 2 * N; left--, right++)
            {
                if (left % 2 == 0 || s[left/2] == s[right/2]) // padding or char
                    dp[i]++;
                else
                    break;
            }
            if (i + dp[i] > mx)
            {
                id = i;
                mx = id + dp[id];
            }
        }

        int res = 0;
        for (int i = 1; i < 2 * N + 1; ++i)
            if (dp[i] > dp[res])
                res = i;

        return s.substr(res / 2 - (dp[res] - 1) / 2, dp[res] - 1);
    }
};
