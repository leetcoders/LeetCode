/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       May 13, 2013
 Update:     Aug 24, 2013
 Problem:    Spiral Matrix II
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_59
 Notes:
 Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.
 For example,
 Given n = 3,
 You should return the following matrix:
 [
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
 ]

 Solution: ...
 */

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n));
        int imin = 0, imax = n-1, jmin = 0, jmax = n-1;
        int i = 0, j = -1;
        int num = 1;
        while (true)
        {
            while (j < jmax) matrix[i][++j] = num++;
            imin++;
            if (imin > imax) break;
            
            while (i < imax) matrix[++i][j] = num++;
            jmax--;
            if (jmin > jmax) break;
            
            while (j > jmin) matrix[i][--j] = num++;
            imax--;
            if (imin > imax) break;
            
            while (i > imin) matrix[--i][j] = num++;
            jmin++;
            if (jmin > jmax) break;
        }
        return matrix;
    }
};
