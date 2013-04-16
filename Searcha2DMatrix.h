/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 16, 2013
 Problem:    Search a 2D Matrix
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_74
 Notes:
 Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

 Integers in each row are sorted from left to right.
 The first integer of each row is greater than the last integer of the previous row.
 For example,

 Consider the following matrix:

 [
    [1,   3,  5,  7],
    [10, 11, 16, 20],
    [23, 30, 34, 50]
 ]
 Given target = 3, return true.

 Solution: Binary-search in both row and column.
 */

class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        if (matrix.size() == 0) return false;

        int row = matrix.size();
        int col = matrix[0].size();
        // for deciding row
        int f = 0, l = row - 1;
        while (f <= l) {
            int mid = (f + l) / 2;
            if (matrix[mid][0] == target)
                return true;
            if (matrix[mid][0] > target)
                l = mid - 1;
            if (matrix[mid][0] < target)
                f = mid + 1;
        }
        if (l < 0) return false;
        int r = l;
        // search in row
        f = 0; l = col - 1;
        while (f <= l) {
            int mid = (f + l) / 2;
            if (matrix[r][mid] == target)
                return true;
            if (matrix[r][mid] > target)
                l = mid - 1;
            if (matrix[r][mid] < target)
                f = mid + 1;
        }
        return false;
    }
};