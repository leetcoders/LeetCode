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
    vector<vector<int> > generateMatrix(int n) {
        if (n == 0) return vector<vector<int> >();
        vector<vector<int> > res(n, vector<int>(n));
        int imin = 0, imax = n-1, jmin = 0, jmax = n-1;
        int number = 1;
        while (true)
        {
            for (int j = jmin; j <= jmax; ++j) res[imin][j] = number++;
            if (++imin > imax) break;
            for (int i = imin; i <= imax; ++i) res[i][jmax] = number++;
            if (jmin > --jmax) break;
            for (int j = jmax; j >= jmin; --j) res[imax][j] = number++;
            if (imin > --imax) break;
            for (int i = imax; i >= imin; --i) res[i][jmin] = number++;
            if (++jmin > jmax) break;
        }
        return res;
    }
};
