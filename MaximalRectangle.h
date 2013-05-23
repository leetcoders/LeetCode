/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       May 23, 2013
 Problem:    Maximal Rectangle
 Difficulty: Medium
 Source:     http://leetcode.com/onlinejudge#question_85
 Notes:
 Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing all ones and return its area.

 Solution: dp. 
           1. dp[i][j] records the number of consecutive '1' on the left and up of the element matrix[i][j].
           2. For each element(i,j), calculate the area of rectangle including the element itself (O(n)).
           3. Total time complexity O(n^3) (72 milli secs for the large).
 */

class Solution {
public:
    int maximalRectangle(vector<vector<char>> &matrix) {
        if (matrix.empty()) return 0;
        int N = matrix.size(), M = matrix[0].size();
        pair<int, int> dp[N][M];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = make_pair(matrix[0][0] - '0', matrix[0][0] - '0');
        int res = dp[0][0].first;
        for (int i = 1; i < N; ++i)
        {
            if (matrix[i][0] == '1')
            {
                dp[i][0] = make_pair(1, dp[i-1][0].second + 1);
                res = max(res, dp[i][0].second);
            }

        }
        for (int j = 1; j < M; ++j)
        {
            if (matrix[0][j] == '1')
            {
                dp[0][j] = make_pair(dp[0][j-1].first + 1, 1);
                res = max(res, dp[0][j].first);
            }
        }
        for (int i = 1; i < N; ++i)
        {
            for (int j = 1; j < M; ++j)
            {
                if (matrix[i][j] == '0')
                    continue;

                dp[i][j] = make_pair(dp[i][j-1].first + 1, dp[i-1][j].second + 1);
                res = max(res, dp[i][j].first);
                res = max(res, dp[i][j].second);

                int minHeight = dp[i][j].second;
                for (int k = j - 1; k > j - dp[i][j].first; --k)
                {
                    minHeight = min(minHeight, dp[i][k].second);
                    res = max(res, minHeight * (j - k + 1));
                }
            }
        }
        return res;
    }
};