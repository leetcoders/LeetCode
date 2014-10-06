/*
 Author:     Annie Kim, anniekim.pku@gmail.com : King, higuige@gmail.com
 Date:       May 20, 2013
 Update:     Oct 06, 2014
 Problem:    Palindrome Partitioning
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_131
 Notes:
 Given a string s, partition s such that every substring of the partition is a palindrome.
 Return all possible palindrome partitioning of s.
 For example, given s = "aab",
 Return
 [
  ["aa","b"],
  ["a","a","b"]
 ]

 Solution: ...
 */

class Solution {
public:
    vector<vector<string>> partition(string s) {
        return partition_2(s);
    }
    vector<vector<string>> partition_2(string s) {
        int size = s.size();
        vector<vector<bool> > dp(size, vector<bool>(size));
        for (int i = size - 1; i >= 0; --i) {
            for (int j = i; j < size; ++j) {
                dp[i][j]=(s[i]==s[j])&&(j<i+2||dp[i+1][j-1]);
            }
        }
        vector<vector<string> > res[size];
        for (int i = size - 1; i >= 0; --i) {
            for (int j = i; j < size; ++j) {
                if (dp[i][j] == false) continue;
                string word = s.substr(i, j - i + 1);
                if (j == size - 1) {
                    res[i].push_back(vector<string>{word});
                } else {
                    for (auto iter : res[j+1]) {
                        iter.insert(iter.begin(), word);
                        res[i].push_back(iter);
                    }
                }
            }
        }
        return res[0];
    }

    vector<vector<string>> partition_1(string s) {
        int size = s.size();
        vector<vector<bool> > dp(size, vector<bool>(size));
        for (int i = size - 1; i >= 0; --i) {
            for (int j = i; j < size; ++j) {
                dp[i][j]=(s[i]==s[j])&&(j<i+2||dp[i+1][j-1]);
            }
        }
        vector<vector<string> > res;
        vector<string> path;
        dfs(s, dp, 0, path, res);
        return res;
    }
    void dfs(string s, vector<vector<bool> > &dp, int start, vector<string> &path, vector<vector<string> > &res) {
        int size = s.size();
        if (start == size) {
            res.push_back(path);
        }
        for (int i = start; i < size; ++i) {
            if (dp[start][i] == false) {
                continue;
            }
            path.push_back(s.substr(start, i - start + 1));
            dfs(s, dp, i + 1, path, res);
            path.pop_back();
        }
    }
};