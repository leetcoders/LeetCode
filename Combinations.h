/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       May 5, 2013
 Problem:    Combinations
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_77
 Notes:
 Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
 For example,
 If n = 4 and k = 2, a solution is:
 [
    [2,4],
    [3,4],
    [2,3],
    [1,2],
    [1,3],
    [1,4],
 ]

 Solution: DFS.
 */

class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combine(int n, int k) {
        res.clear();
        vector<int> com;
        combineRe(n, k, com, -1, 0);
        return res;
    }

    void combineRe(int n, int k, vector<int> &com, int last, int deep)
    {
        if (deep == k)
        {
            res.push_back(com);
            return;
        }
        for (int i = last + 1; i < n; ++i)
        {
            com.push_back(i+1);
            combineRe(n, k, com, i, deep + 1);
            com.pop_back();
        }
    }
};