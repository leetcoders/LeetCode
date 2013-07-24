/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 24, 2013
 Update:     Jul 24, 2013
 Problem:    N-Queens II
 Difficulty: Medium
 Source:     http://leetcode.com/onlinejudge#question_52
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
           The second solution is 'bit' verstion. The idea is from http://www.matrix67.com/blog/archives/266 (in chinese).
 */

class Solution {
public:
    int totalNQueens(int n) {
        return totalNQueens_2(n);
    }
    
    // solution 1
    int totalNQueens_1(int n) {
        int res = 0;
        int column[n];
        memset(column, -1, n*sizeof(int));
        solveNQueensRe_1(n, 0, column, res);
        return res;
    }

    void solveNQueensRe_1(int n, int row, int *column, int &res)
    {
        if (row == n) {
            res++;
            return;
        }
        for (int j = 0; j < n; ++j)
        {
            if (!isValid(n, row, j, column)) continue;
            column[j] = row;
            solveNQueensRe_1(n, row + 1, column, res);
            column[j] = -1;
        }
    }

    bool isValid(int n, int row, int col, int *column)
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
    
    // solution 2: bit version
    int totalNQueens_2(int n) {
        int res = 0;
        totalNQueensRe_2(n, 0, 0, 0, res);
        return res;
    }

    void totalNQueensRe_2(int n, int row, int ld, int rd, int &res)
    {
        if (row == (1 << n) - 1)
        {
            res++;
            return;
        }
        int avail = ~(row | ld | rd);
        for (int i = n - 1; i >= 0; --i)
        {
            int pos = 1 << i;
            if (avail & pos)
                totalNQueensRe_2(n, row | pos, (ld | pos) << 1, (rd | pos) >> 1, res);
        }
    }
};
