/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       May 20, 2013
 Problem:    Surrounded Regions
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_130
 Notes:
 Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.
 A region is captured by flipping all 'O's into 'X's in that surrounded region .
 For example,
 X X X X
 X O O X
 X X O X
 X O X X
 After running your function, the board should be:
 X X X X
 X X X X
 X X X X
 X O X X

 Solution: Traverse from the boarder to the inside and mark all the 'O's that are not surrounded by
           'X' as 'V' (visited).
           1. DFS. Cause 'Runtime Error' for large test data (I think it's caused by stack overflow).
           2. BFS (queue).
 */

class Solution {
public:
    void solve(vector<vector<char>> &board) {
        solve_2(board);
    }

    void solve_1(vector<vector<char>> &board) {
        if (board.empty()) return; 
        int N = board.size(), M = board[0].size();
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                if (i == 0 || i == N-1 || j == 0 || j == M-1)
                    dfs(board, i, j);

        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == 'V')
                    board[i][j] = 'O';
    }

    void dfs(vector<vector<char>> &board, int i, int j)
    {
        if (board[i][j] == 'V' || board[i][j] == 'X')
            return;
        board[i][j] = 'V';
        int N = board.size(), M = board[0].size();
        if (i > 0) dfs(board, i-1, j);
        if (i < N-1) dfs(board, i+1, j);
        if (j > 0) dfs(board, i, j-1);
        if (j < M-1) dfs(board, i, j+1);
    }

    void solve_2(vector<vector<char>> &board) {
        if (board.empty()) return; 
        int N = board.size(), M = board[0].size();
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                if (i == 0 || i == N-1 || j == 0 || j == M-1)
                    bfs(board, i, j);

        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == 'V') board[i][j] = 'O';
    }

    void bfs(vector<vector<char>> &board, int i, int j)
    {
        if (board[i][j] != 'O')
            return;
        queue<pair<int, int>> q;
        q.push(make_pair(i, j));
        int N = board.size(), M = board[0].size();
        while (!q.empty())
        {
            i = q.front().first;
            j = q.front().second;
            q.pop();
            if (board[i][j] == 'V') // important to recheck!
                continue;
            board[i][j] = 'V';
            if (i > 0 && board[i-1][j] == 'O')
                q.push(make_pair(i-1, j));
            if (i < N-1 && board[i+1][j] == 'O')
                q.push(make_pair(i+1, j));
            if (j > 0 && board[i][j-1] == 'O')
                q.push(make_pair(i, j-1));
            if (j < M-1&& board[i][j+1] == 'O')
                q.push(make_pair(i, j+1));
        }
    }
};