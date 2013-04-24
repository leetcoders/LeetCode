/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 24, 2013
 Problem:    N-Queens
 Difficulty: Medium
 Source:     http://leetcode.com/onlinejudge#question_51
 Notes:
 The n-queens puzzle is the problem of placing n queens on an n*n chessboard such that no two queens attack each other.
 Given an integer n, return all distinct solutions to the n-queens puzzle.
 Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.
 For example,
 There exist two distinct solutions to the 4-queens puzzle:
 [
 [".Q..",  // Solution 1
 "...Q",
 "Q...",
 "..Q."],

 ["..Q.",  // Solution 2
 "Q...",
 "...Q",
 ".Q.."]
 ]

 Solution: Recursion (DFS).
 */

class Solution {
public:
    vector<vector<string>> res;
    int *column;
    vector<vector<string>> solveNQueens(int n) {
        res.clear();
        column = new int[n];
        memset(column, -1, n*sizeof(int));
        solveNQueensRe(n, 0);
        return res;
    }

    void solveNQueensRe(int n, int row)
    {
        if (row == n) {
            vector<string> sol(n, string(n, '.'));
            for (int i = 0; i < n; ++i)
                sol[column[i]][i] = 'Q';
            res.push_back(sol);
            return;
        }
        for (int j = 0; j < n; ++j)
        {
            if (!isValid(n, row, j)) continue;
            column[j] = row;
            solveNQueensRe(n, row + 1);
            column[j] = -1;
        }
    }

    bool isValid(int n, int row, int col)
    {
        if (column[col] != -1) return false;
        for (int i = 0; i < n; ++i)
        {
            if (column[i] == -1) continue;
            if (column[i] + i == row + col) return false;
            if (column[i] - row == i - col) return false;
        }
        return true;
    }
};