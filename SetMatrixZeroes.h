/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       May 25, 2013
 Update:     Jul 23, 2013
 Problem:    Set Matrix Zeroes
 Difficulty: Medium
 Source:     http://leetcode.com/onlinejudge#question_73
 Notes:
 Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
 Follow up:
 Did you use extra space?
 A straight forward solution using O(mn) space is probably a bad idea.
 A simple improvement uses O(m + n) space, but still not the best solution.
 Could you devise a constant space solution?

 Solution: Use first row and column as auxiliary spaces instead of newly allocating ones.
*/

class Solution {
public:
    void setZeroes(vector<vector<int>> &matrix) {
        if (matrix.empty()) return;
        int N = matrix.size(), M = matrix[0].size();
        bool setFirstRowZero = false;
        bool setFirstColZero = false;

        for (int i = 0; i < N && !setFirstColZero; ++i)
            setFirstColZero = (matrix[i][0] == 0);
        for (int j = 0; j < M && !setFirstRowZero; ++j)
            setFirstRowZero = (matrix[0][j] == 0);

        for (int i = 1; i < N; ++i)
            for (int j = 1; j < M; ++j)
                if (matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }

        for (int i = 1; i < N; ++i)
            if (matrix[i][0] == 0)
                for (int j = 1; j < M; ++j)
                    matrix[i][j] = 0;

        for (int j = 1; j < M; ++j)
            if (matrix[0][j] == 0)
                for (int i = 1; i < N; ++i)
                    matrix[i][j] = 0;

        if (setFirstRowZero)
            for (int j = 0; j < M; ++j)
                matrix[0][j] = 0;

        if (setFirstColZero)
            for (int i = 0; i < N; ++i)
                matrix[i][0] = 0;
    }
};
