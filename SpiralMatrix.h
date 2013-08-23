/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       May 13, 2013
 Update:     Aug 24, 2013
 Problem:    Spiral Matrix
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_54
 Notes:
 Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
 For example,
 Given the following matrix:
 [
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
 ]
 You should return [1,2,3,6,9,8,7,4,5].

 Solution: ...
 */

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> res;
        if (matrix.empty() || matrix[0].empty()) return res;
        int M = matrix.size(), N = matrix[0].size();
        int imin = 0, imax = M-1, jmin = 0, jmax = N-1;
        int i = 0, j = -1;
        while (true)
        {
            while (j < jmax) res.push_back(matrix[i][++j]);
            imin++;
            if (imin > imax) break;
            
            while (i < imax) res.push_back(matrix[++i][j]);
            jmax--;
            if (jmin > jmax) break;
            
            while (j > jmin) res.push_back(matrix[i][--j]);
            imax--;
            if (imin > imax) break;
            
            while (i > imin) res.push_back(matrix[--i][j]);
            jmin++;
            if (jmin > jmax) break;
        }
        return res;
    }
};
