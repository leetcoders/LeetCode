/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Jun 19, 2013
 Problem:    Sudoku Solver
 Difficulty: Medium
 Source:     http://leetcode.com/onlinejudge#question_37
 Notes:
 Write a program to solve a Sudoku puzzle by filling the empty cells.
 Empty cells are indicated by the character '.'.
 You may assume that there will be only one unique solution.

 Solution: back-tracking..
 */

class Solution {
public:
    void solveSudoku(vector<vector<char>> &board) {
        solveSudokuRe(board, 0, 0);
    }

    bool solveSudokuRe(vector<vector<char>> &board, int row, int col) {
        getNextMissing(board, row, col);
        if (row >= 9)
            return true;
        for (char c = '1'; c <= '9'; ++c)
        {
            board[row][col] = c;
            if (isValidSudoku(board, row, col))
                if (solveSudokuRe(board, row, col + 1))
                    return true;
        }
        board[row][col] = '.';
        return false;
    }

    void getNextMissing(vector<vector<char>> &board, int &row, int &col)
    {
        while (row < 9) {
            while (col < 9) {
                if (board[row][col] == '.')
                    return;
                col++;
            }
            if (col == 9)
                col = 0;
            row++;
        }
    }

    // here, check board[r][c] only for efficiency
    // may use code from 'Valid Sudoku' problem instead..
    bool isValidSudoku(const vector<vector<char>> &board, int r, int c) {
        int row = 0, col = 0, box = 0;
        // row
        for (int j = 0; j < 9; ++j)
        {
            if (board[r][j] == '.')
                continue;
            int bit = 1 << (board[r][j] - '0');
            if (row & bit)
                return false;
            row |= bit;
        }
        // col
        for (int i = 0; i < 9; ++i)
        {
            if (board[i][c] == '.')
                continue;
            int bit = 1 << (board[i][c] - '0');
            if (col & bit)
                return false;
            col |= bit;
        }
        // box
        int box_i_start = r / 3 * 3;
        int box_j_start = c / 3 * 3;
        for (int i = box_i_start; i < box_i_start + 3; ++i)
        {
            for (int j = box_j_start; j < box_j_start + 3; ++j)
            {
                if (board[i][j] == '.')
                    continue;
                int bit = 1 << (board[i][j] - '0');
                if (box & bit)
                    return false;
                box |= bit;
            }
        }
        return true;
    }
};
