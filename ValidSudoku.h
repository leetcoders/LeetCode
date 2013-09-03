/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       May 20, 2013
 Problem:    Valid Sudoku
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_36
 Notes:
 Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules (http://sudoku.com.au/TheRules.aspx).
 The Sudoku board could be partially filled, where empty cells are filled with the character '.'.

 Solution: 1. Traverse the Sudoku only once.
           2. Bit manipulation. Use only one bit to represent a number. Space: sizeof(int) * (1+9+9).
 */

class Solution {
public:
    bool isValidSudoku(vector<vector<char>> &board) {
        const int N = 9;
        int row, col[N] = {0}, box[N] = {0};
        for (int i = 0; i < N; ++i)
        {
            row = 0;
            for (int j = 0; j < N; ++j)
            {
                if (board[i][j] == '.') continue;
                
                int bit = 1 << (board[i][j] - '1');
                int box_index = i/3*3 + j/3;
                
                if (row & bit || col[j] & bit || box[box_index] & bit)
                    return false;
                
                row |= bit;
                col[j] |= bit;
                box[box_index] |= bit;
            }
        }
        return true;
    }
};
