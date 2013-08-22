/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 24, 2013
 Update:     Aug 23, 2013
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

 Solution: 1. Recursion.
           2. Recursion + bit version. (fast)
              The idea is from http://www.matrix67.com/blog/archives/266 (in chinese).
           3. Iteration.
*/

class Solution {
public:
    int totalNQueens(int n) {
        return totalNQueens_2(n);
    }
    
    // solution 1: recursion
    int totalNQueens_1(int n) 
    {
        int board[n];
        memset(board, -1, sizeof(board));
        int res = 0;
        totalNQueensRe(n, 0, board, res);
        return res;
    }
    
    void totalNQueensRe(int n, int row, int board[], int &res)
    {
        if (row  == n)
        {
            res++;
            return;
        }
        for (int i = 0; i < n; ++i)
        {
            if (isValid(board, row, i))
            {
                board[row] = i;
                totalNQueensRe(n, row + 1, board, res);
                board[row] = -1;
            }
        }
    }
    
    bool isValid(int board[], int row, int col)
    {
        for (int i = 0; i < row; ++i)
            if (board[i] == col || row - i == abs(col - board[i]))
                return false;
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
    
    // solution 3: iterative solution
    int totalNQueens_3(int n) 
    {
        int board[n];
        memset(board, -1, sizeof(board));
        int row = 0;
        int res = 0;
        while (row != -1)
        {
            if (row == n)
            {
                res++;
                row--;
            }
            int i = board[row] == -1 ? 0 : board[row] + 1;
            for (; i < n; ++i)
            {
                if (isValid(board, row, i))
                {
                    board[row] = i;
                    row++;
                    break;
                }
            }
            if (i == n)
            {
                board[row] = -1;
                row--;
            }
        }
        return res;
    }
};
