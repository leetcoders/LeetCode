/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       May 6, 2013
 Problem:    Interleaving String
 Difficulty: Medium
 Source:     http://leetcode.com/onlinejudge#question_97
 Notes:
 Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.
 For example,
 Given:
 s1 = "aabcc",
 s2 = "dbbca",
 When s3 = "aadbbcbcac", return true.
 When s3 = "aadbbbaccc", return false.

 Solution: 1. Recursion. Okay for Small but too time-consuming for Large Test data.
           2. dp. O(MN) time & space. 'dp[i][j] == true' means that there is at least a way to form 
              the string s3[0...i+j-1] by interleaving s1[0...j-1] and s2[0...i-1].
           3. dp. This is the first dp version that I wrote. You may ignore this version since it is
              a little complicated and also uses an extra <stack> to record the back-track point.
 */

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        return isInterleave1(s1, s2, s3);
    }

    bool isInterleave1(string s1, string s2, string s3) {
        return isInterleaveRe(s1.c_str(), s2.c_str(), s3.c_str());
    }

    bool isInterleaveRe(const char *s1, const char *s2, const char *s3)
    {
        if (*s1 == '\0' && *s2 == '\0' && *s3 == '\0') return true;
        if (*s3 == '\0') return false;
        if (*s1 == '\0') return strcmp(s2, s3) == 0;
        if (*s2 == '\0') return strcmp(s1, s3) == 0;

        return *s1 == *s3 && isInterleaveRe(s1+1, s2, s3+1) || 
            *s2 == *s3 && isInterleaveRe(s1, s2+1, s3+1);
    }

    bool isInterleave2(string s1, string s2, string s3) {
        int M = s1.size(), N = s2.size(), K = s3.size();
        if (M + N != K) return false;
        if (K == 0) return true;
        int dp[N+1][M+1];
        dp[0][0] = true;

        for (int i = 1; i <= N; ++i)
            dp[i][0] = s2[i-1] == s3[i-1];
        for (int j = 1; j <= M; ++j)
            dp[0][j] = s1[j-1] == s3[j-1];

        for (int i = 1; i <= N; ++i)
            for (int j = 1; j <= M; ++j)
                dp[i][j] = dp[i-1][j] && s2[i-1] == s3[i+j-1] ||
                           dp[i][j-1] && s1[j-1] == s3[i+j-1];

        return dp[N][M];
    }

    bool isInterleave3(string s1, string s2, string s3) {
        int M = s1.size(), N = s2.size(), K = s3.size();
        if (M + N != K) return false;
        if (K == 0) return true;
        int dp[N+1][M+1];
        memset(dp, -1, sizeof(dp));
        int i = 0, j = 0, k = 0;
        bool found1 = false, found2 = false;
        stack<pair<int, int>> roll_back;
        while (k < K)
        {
            found1 = found2 = false;
            if (s2[i] == s3[k])
            {
                if (dp[i+1][j] != k)
                    found1 = true;
                dp[i+1][j] = k;
            }
            if (s1[j] == s3[k])
            {
                if (dp[i][j+1] != k)
                    found2 = true;
                dp[i][j+1] = k;
            }
            if (!found1 && !found2)
            {
                if (!roll_back.empty())
                {
                    pair<int, int> roll = roll_back.top();
                    roll_back.pop();
                    i = roll.first;
                    j = roll.second;
                    k = dp[i][j] + 1;
                    continue;
                }
                else
                    return false;
            }
            else if (found1 && found2)
            {
                roll_back.push(make_pair(i+1, j));
                j++;
            }
            else if (found1)
                i++;
            else if (found2)
                j++;
            k++;
        }
        return dp[N][M] == K - 1;
    }
};