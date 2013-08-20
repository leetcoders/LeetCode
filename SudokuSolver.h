/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Jun 19, 2013
 Update:     Aug 20, 2013
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
        pair<int, int> next = (board[0][0] == '.') ? make_pair(0, 0) : 
                                                     getNextMissing(board, 0, 0);
        solveSudokuRe(board, next.first, next.second);
    }

    bool solveSudokuRe(vector<vector<char>> &board, int row, int col) {
        if (row == 9) return true;
        pair<int, int> next = getNextMissing(board, row, col);
        vector<char> possible;
        getPossibleValues(board, row, col, possible);
        for (int i = 0; i < possible.size(); ++i)
        {
            board[row][col] = possible[i];
            if (solveSudokuRe(board, next.first, next.second))
                return true;
        }
        board[row][col] = '.';
        return false;
    }

    pair<int, int> getNextMissing(vector<vector<char>> &board, int row, int col)
    {
        while (true)
        {
            row = (col == 8) ? row + 1 : row;
            col = (col + 1) % 9;
            if (row == 9 || board[row][col] == '.')
                return make_pair(row, col);
        }
    }

    void getPossibleValues(vector<vector<char>> &board, int row, int col, vector<char> &possible)
    {
        bool value[9] = {false};
        for (int i = 0; i < 9; ++i)
        {
            if (board[i][col] != '.') value[board[i][col]-'1'] = true;
            if (board[row][i] != '.') value[board[row][i]-'1'] = true;
            char c = board[row/3*3+i/3][col/3*3+i%3];
            if (c != '.') value[c-'1'] = true;
        }
        for (int i = 0; i < 9; ++i)
            if (!value[i]) possible.push_back(i+'1');
    }
};
