/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Jun 19, 2013
 Update:     Sep 29, 2013
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
    typedef vector<vector<char> > BOARDTYPE;
    
    void solveSudoku(BOARDTYPE &board) {
        solveSudokuRe(board, 0, 0);
    }
    
    bool solveSudokuRe(BOARDTYPE &board, int row, int col) {
        getNextEmpty(board, row, col);
        if (row == 9) return true;
        vector<bool> avail(9, true);
        getAvailable(board, avail, row, col);
        for (int i = 0; i < 9; ++i)
        {
            if (!avail[i]) continue;
            board[row][col] = i + '1';
            if (solveSudokuRe(board, row, col)) return true;
        }
        board[row][col] = '.';
        return false;
    }
    
    void getNextEmpty(BOARDTYPE &board, int &row, int &col) {
        do {
            if (board[row][col] == '.') return;
            row = (col == 8) ? row + 1 : row;
            col = (col + 1) % 9;
        } while (row < 9);
    }
    
    void getAvailable(BOARDTYPE &board, vector<bool> &avail, int row, int col) {
        for (int i = 0; i < 9; ++i) {
            if (board[row][i] != '.') avail[board[row][i]-'1'] = false;
            if (board[i][col] != '.') avail[board[i][col]-'1'] = false;
            int box_i = row/3*3 + i/3, box_j = col/3*3 + i%3;
            if (board[box_i][box_j] != '.') avail[board[box_i][box_j]-'1'] = false;
        }
    }
};