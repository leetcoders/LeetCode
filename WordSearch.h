/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       May 13, 2013
 Update:     Sep 20, 2013
 Problem:    Word Search
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_79
 Notes:
 Given a 2D board and a word, find if the word exists in the grid.
 The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are 
 those horizontally or vertically neighboring. The same letter cell may not be used more than once.
 For example,
 Given board =
 [
  ["ABCE"],
  ["SFCS"],
  ["ADEE"]
 ]
 word = "ABCCED", -> returns true,
 word = "SEE", -> returns true,
 word = "ABCB", -> returns false.

 Solution: DFS. (For 'visited', using two-dimensional array will be faster than vector<vector>.[90+ms->50+ms])
 */

class Solution {
public:
    typedef vector<vector<char> > VECTOR2D;
    
    bool exist(VECTOR2D &board, string word) {
        int N = board.size(), M = board[0].size();
        VECTOR2D avail(N, vector<char>(M, 'o'));
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                if (existRe(board, word, 0, i, j, avail))
                    return true;
        return false;
    }

    bool existRe(const VECTOR2D &board, const string &word, int deep, int i, int j, VECTOR2D &avail)
    {
        int N = board.size(), M = board[0].size();
        if (deep == word.size()) return true;
        if (i < 0 || i >= N || j < 0 || j >= M) return false;
        if (board[i][j] != word[deep] || avail[i][j] == 'x') return false;
        
        avail[i][j] = 'x';
        if (existRe(board, word, deep + 1, i-1, j, avail)) return true;
        if (existRe(board, word, deep + 1, i+1, j, avail)) return true;
        if (existRe(board, word, deep + 1, i, j-1, avail)) return true;
        if (existRe(board, word, deep + 1, i, j+1, avail)) return true;
        avail[i][j] = 'o';
        
        return false;
    }
};