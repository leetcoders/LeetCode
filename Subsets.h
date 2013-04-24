/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 24, 2013
 Problem:    Subsets
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_78
 Notes:
 Given a set of distinct integers, S, return all possible subsets.
 Note:
 Elements in a subset must be in non-descending order.
 The solution set must not contain duplicate subsets.
 For example,
 If S = [1,2,3], a solution is:
 [
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
 ]

 Solution: Recursion (DFS).
 */

class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> subsets(vector<int> &S) {
        res.clear();
        res.push_back(vector<int>());
        sort(S.begin(), S.end());
        for (int setSize = 1; setSize <= S.size(); ++setSize) {
            vector<int> r;
            subsetsRe(S, r, setSize, 0, -1);
        }
        return res;
    }

    void subsetsRe(vector<int> &s, vector<int> &r, int setSize, int deep, int lastIndex)
    {
        if (deep == setSize) {
            res.push_back(r);
            return;
        }
        for (int i = lastIndex + 1; i <= s.size() - (setSize - deep); ++i) {
            r.push_back(s[i]);
            subsetsRe(s, r, setSize, deep + 1, i);
            r.pop_back();
        }
    }
};