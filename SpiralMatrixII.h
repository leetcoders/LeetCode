/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       May 13, 2013
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

 Solution: Spirally traverse the matrix (right->down->left->up->right.....).
           Update the min and max values of x/y at each turning point.
 */

class Solution {
public:
    enum DIR {RIGHT, LEFT, UP, DOWN};
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        DIR dir = RIGHT;
        int x = 0, y = 0;
        int x_min = 0, x_max = n - 1;
        int y_min = 0, y_max = n - 1;
        int num = 1;
        while (x_min <= x_max && y_min <= y_max)
        {
            res[x][y] = num++;
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