/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 16, 2013
 Update:     Sep 27, 2013
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

 Solution: Binary-search.
 */

class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        return searchMatrix_2(matrix, target);
    }
    
    // Solution 1.
    bool searchMatrix_1(vector<vector<int> > &matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        int N = matrix.size(), M = matrix[0].size();
        int i = 0, j = N-1;
        while (i <= j)
        {
            int mid = (i + j) / 2;
            if (matrix[mid][0] == target) return true;
            else if (matrix[mid][0] < target) i++;
            else j--;
        }
        int row = j;
        if (row < 0) return false;
        i = 0, j = M - 1;
        while (i <= j)
        {
            int mid = (i + j) / 2;
            if (matrix[row][mid] == target) return true;
            else if (matrix[row][mid] < target) i++;
            else j--;
        }
        return false;
    }
    
    // Solution 2.
    bool searchMatrix_2(vector<vector<int> > &matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        int N = matrix.size(), M = matrix[0].size();
        int i = 0, j = M * N - 1;
        while (i <= j)
        {
            int mid = (i + j) / 2;
            int row = mid / M, col = mid % M;
            if (matrix[row][col] == target) return true;
            else if (matrix[row][col] < target) i = mid + 1;
            else j = mid - 1;
        }
        return false;
    }
};