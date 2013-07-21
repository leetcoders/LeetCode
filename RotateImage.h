/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 9, 2013
 Update:     Jul 21, 2013 (Add solution 2)
 Problem:    Rotate Image
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_48
 Notes:
 You are given an n x n 2D matrix representing an image.
 Rotate the image by 90 degrees (clockwise).
 Follow up:
 Could you do this in-place?

 Solution: 1. Rotate one-fourth of the image clockwise.
           2. 123   ->  147   ->   741    (preferable)
              456       258        852
              789       369        963
 */

class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        rotate_2(matrix);
    }
    
    void rotate_1(vector<vector<int> > &matrix) {
        int n = matrix.size();
        for (int i = 0; i < (n + 1) / 2; i++)
            for (int j = 0; j < n / 2; j++)
                rotateElement(matrix, i, j);
    }
    void rotateElement(vector<vector<int> > &matrix, int row, int col)
    {
        int temp = matrix[row][col];
        for (int i = 0; i < 3; i++)
        {
            int c = row;
            int r = matrix.size() - 1 - col;
            matrix[row][col] = matrix[r][c];
            row = r;
            col = c;
        }
        matrix[row][col] = temp;
    }
    
    void rotate_2(vector<vector<int> > &matrix) {
        int N = matrix.size();
        for (int i = 0; i < N; ++i)
            for (int j = i+1; j < N; ++j)
                swap(matrix[i][j], matrix[j][i]);
        for (int j = 0; j < N/2; ++j)
            for (int i = 0; i < N; ++i)
                swap(matrix[i][j], matrix[i][N-j-1]);
    }
};
