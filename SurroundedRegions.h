/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       May 20, 2013
 Update:     Aug 21, 2013
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

 Solution: Traverse from the boarder to the inside and mark all the 'O's that are not surrounded by 'X' as 'V' (visited).
           1. DFS.
           2. BFS (queue).
 */

class Solution {
public:
    typedef vector<vector<char> > BOARDTYPE;
    
    void solve(BOARDTYPE &board) {
        if (board.empty() || board[0].empty()) return;
        int N = board.size(), M = board[0].size();
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                if (i == 0 || j == 0 || i == N-1 || j == M-1)
                    bfs(board, i, j); // you may call dfs or bfs here!
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                board[i][j] = (board[i][j] == 'V') ? 'O' : 'X';
    }
    
    void dfs(BOARDTYPE &board, int row, int col) {
        int N = board.size(), M = board[0].size();
        if (row < 0 || row >= N || col < 0 || col >= M) return;
        if (board[row][col] != 'O') return;
        board[row][col] = 'V';
        dfs(board, row+1, col);
        dfs(board, row-1, col);
        dfs(board, row, col+1);
        dfs(board, row, col-1);
    }

    void bfs(BOARDTYPE &board, int row, int col) {
        if (board[row][col] != 'O') return;
        int N = board.size(), M = board[0].size();
        queue<pair<int, int>> q;
        q.push(make_pair(row, col));
        while (!q.empty())
        {
            int i = q.front().first, j = q.front().second;
            q.pop();
            if (i < 0 || i >= N || j < 0 || j >= M) continue;
            if (board[i][j] != 'O') continue;// important to recheck!
            board[i][j] = 'V';
            q.push(make_pair(i-1, j));
            q.push(make_pair(i+1, j));
            q.push(make_pair(i, j-1));
            q.push(make_pair(i, j+1));
        }
    }
};
