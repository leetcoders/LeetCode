/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       May 13, 2013
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
    bool exist(vector<vector<char>> &board, string word) {
        int N = board.size(), M = board[0].size();

        bool **visited = new bool*[N];
        for (int i = 0; i < N; ++i) {
            visited[i] = new bool[M];
            memset(visited[i], 0, M * sizeof(bool));
        }

        bool found = false;
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                if (!found && board[i][j] == word[0] && existRe(board, word, 1, visited, make_pair(i, j)))
                    found = true;

        for (int i = 0; i < N; ++i)
            delete [] visited[i];
        delete [] visited;

        return found;
    }

    bool existRe(const vector<vector<char>> &board, const string &word, int deep, bool **visited, pair<int, int> last)
    {
        if (deep == word.size())
            return true;

        int x = last.first, y = last.second;
        int N = board.size(), M = board[0].size();
        visited[x][y] = true;

        bool found = false;
        if (x > 0 && !visited[x-1][y] && board[x-1][y] == word[deep])
            found = existRe(board, word, deep + 1, visited, make_pair(x-1, y));
        if (!found && x < N-1 && !visited[x+1][y] && board[x+1][y] == word[deep])
            found = existRe(board, word, deep + 1, visited, make_pair(x+1, y));
        if (!found && y > 0 && !visited[x][y-1] && board[x][y-1] == word[deep])
            found = existRe(board, word, deep + 1, visited, make_pair(x, y-1));
        if (!found && y < M-1 && !visited[x][y+1] && board[x][y+1] == word[deep])
            found = existRe(board, word, deep + 1, visited, make_pair(x, y+1));

        visited[x][y] = false;
        return found;
    }
};