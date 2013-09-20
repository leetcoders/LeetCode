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
    bool exist(vector<vector<char> > &board, string word) {
        int N = board.size(), M = board[0].size();
        vector<vector<bool> > visited(N, vector<bool>(M, false));
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                if (existRe(board, word, 0, i, j, visited))
                    return true;
        return false;
    }

    bool existRe(const vector<vector<char> > &board, const string &word, int deep, 
                 int i, int j, vector<vector<bool> > &visited)
    {
        int N = board.size(), M = board[0].size();
        if (deep == word.size()) return true;
        if (i < 0 || i >= N || j < 0 || j >= M) return false;
        if (board[i][j] != word[deep] || visited[i][j]) return false;
        
        visited[i][j] = true;
        if (existRe(board, word, deep + 1, i-1, j, visited)) return true;
        if (existRe(board, word, deep + 1, i+1, j, visited)) return true;
        if (existRe(board, word, deep + 1, i, j-1, visited)) return true;
        if (existRe(board, word, deep + 1, i, j+1, visited)) return true;
        visited[i][j] = false;
        
        return false;
    }
};
