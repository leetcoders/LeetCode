/*
 Author:     Annie Kim, anniekim.pku@gmail.com : King, higuige@gmail.com
 Date:       May 23, 2013
 Update:     Oct 09, 2014
 Problem:    Maximal Rectangle
 Difficulty: Medium
 Source:     http://leetcode.com/onlinejudge#question_85
 Notes:
 Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing all ones and return its area.

 Solution: 1. dp. (72 milli secs for the large).
              a) dp[i][j] records the number of consecutive '1' on the left and up of the element matrix[i][j].
              b) For each element(i,j), calculate the area of rectangle including the element itself.
           2. calculate 'Largest Rectangle in Histogram' for each row.
           3. Time : O(n ^ 2), Space : O(n).
 */

class Solution {
public:
    int maximalRectangle(vector<vector<char>> &matrix) {
        return maximalRectangle_3(matrix);
    }
    
    int maximalRectangle_1(vector<vector<char>> &matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int N = matrix.size(), M = matrix[0].size();
        pair<int, int> dp[N][M];
        memset(dp, 0, sizeof(dp));
        int res = 0;
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < M; ++j)
            {
                if (matrix[i][j] == '0')
                    continue;
                
                int x = (j == 0) ? 1 : dp[i][j-1].first + 1;
                int y = (i == 0) ? 1 : dp[i-1][j].second + 1;
                dp[i][j] = make_pair(x, y);
                
                int minHeight = y;
                for (int k = j; k > j - x; --k)
                {
                    minHeight = min(minHeight, dp[i][k].second);
                    res = max(res, minHeight * (j - k + 1));
                }
            }
        }
        return res;
    }
    
    int maximalRectangle_2(vector<vector<char> > &matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int N = matrix.size(), M = matrix[0].size();
        vector<int> height(M+1, 0);
        int res = 0;
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < M; ++j)
                height[j] = (matrix[i][j] == '0') ? 0 : height[j] + 1;
            res = max(res, largestRectangleArea(height));
        }
        return res;
    }
    
    // a little different from 'Largest Rectangle in Histogram'
    // final 0 is already provided beforehand
    int largestRectangleArea(const vector<int> &height) {
        stack<int> stk;
        int res = 0, N = height.size();
        for (int i = 0; i < N; ++i)
        {
            int count = 0;
            while (!stk.empty() && stk.top() > height[i])
            {
                count++;
                res = max(res, count * stk.top());
                stk.pop();
            }
            while (count--)
                stk.push(height[i]);

            stk.push(height[i]);
        }
        return res;
    }

    int maximalRectangle_2(vector<vector<char> > &matrix) {
        if (matrix.empty()) return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        std::vector<int> H(n);
        std::vector<int> L(n);
        std::vector<int> R(n);
        int res = 0;
        for (int i = 0; i < m; ++i) {
            int left = 0, right = n;
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 1) {
                    ++H[j];
                    L[j] = max(left, L[j]);
                } else {
                    left = j + 1;
                    H[j] = 0; L[j] = 0; R[j] = n;
                }
            }
            for (int j = n - 1; j >= 0; --j) {
                if (matrix[i][j] == '1') {
                    R[j] = min(R[j], right);
                    res =  max(res, (R[j] - L[j]) * H[j]);
                } else {
                    right = j;
                }
            }
        }
        return res;
    }

};
