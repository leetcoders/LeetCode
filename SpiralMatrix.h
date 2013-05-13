/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       May 13, 2013
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

 Solution: Spirally traverse the matrix (right->down->left->up->right.....).
           Update the min and max values of x/y at each turning point.
 */

class Solution {
public:
    enum DIR {RIGHT, LEFT, UP, DOWN};
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> res;
        if (matrix.empty()) return res;
        DIR dir = RIGHT;
        int x = 0, y = 0;
        int x_min = 0, x_max = matrix.size() - 1;
        int y_min = 0, y_max = matrix[0].size() - 1;
        while (x_min <= x_max && y_min <= y_max)
        {
            res.push_back(matrix[x][y]);
            switch (dir)
            {
            case RIGHT:
                if (y == y_max) {
                    x_min++;
                    dir = DOWN;
                    x++;
                } else {
                    y++;
                }
                break;
            case LEFT:
                if (y == y_min) {
                    x_max--;
                    dir = UP;
                    x--;
                } else {
                    y--;
                }
                break;
            case UP:
                if (x == x_min) {
                    y_min++;
                    dir = RIGHT;
                    y++;
                } else {
                    x--;
                }
                break;
            case DOWN:
                if (x == x_max) {
                    y_max--;
                    dir = LEFT;
                    y--;
                } else {
                    x++;
                }
                break;
            }
        }
        return res;
    }
};
