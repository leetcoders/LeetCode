/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Jul 13, 2013
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
        pair<int, int> res = make_pair(0, 0);

        for (int i = N-1; i >= 0; --i)
        {
            for (int j = i; j < N; ++j)
            {
                if (j == i)
                    dp[i][j] = true;
                else if (j == i + 1)
                    dp[i][j] = s[i] == s[j];
                else
                    dp[i][j] = s[i] == s[j] && dp[i+1][j-1];

                if (dp[i][j] && j - i > res.second - res.first)
                    res = make_pair(i, j);
            }
        }

        return s.substr(res.first, res.second - res.first + 1);
    }

    string longestPalindrome_2(string s) {
        int N = s.size();
        bool dp_1[N], dp_2[N];
        pair<int, int> res = make_pair(N-1, N-1);

        for (int i = N-1; i >= 0; --i)
        {
            bool *last = (i % 2 == 0) ? dp_1 : dp_2;
            bool *cur = (i % 2 == 0) ? dp_2 : dp_1;

            for (int j = i; j < N; ++j)
            {
                if (j == i)
                    cur[j] = true;
                else if (j == i + 1)
                    cur[j] = s[i] == s[j];
                else
                    cur[j] = s[i] == s[j] && last[j-1];

                if (cur[j] && j - i > res.second - res.first)
                    res = make_pair(i, j);
            }
        }

        return s.substr(res.first, res.second - res.first + 1);
    }

    string longestPalindrome_3(string s) {
        int N = s.size();
        pair<int, int> res = make_pair(N-1, N-1);

        for (int i = N-1; i >= 0; --i)
        {
            for (int j = 0; j <= 1; ++j)
            {
                bool dp = s[i] == s[i+j];
                if (dp && j > res.second - res.first)
                    res = make_pair(i, i+j);

                for (int k = 1; dp && i - k >= 0; ++k)  // check 'dp' for efficiency
                {
                    dp = s[i-k] == s[i+j+k];
                    if (dp && k * 2 + j > res.second - res.first)
                        res = make_pair(i-k, i+j+k);
                }
            }

            if (res.second - res.first + 1 == N)  // check result
                break;
        }

        return string(s.begin() + res.first, s.begin() + res.second + 1);
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