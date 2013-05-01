/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 30, 2013
 Problem:    Subsets II
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_90
 Notes:
 Given a collection of integers that might contain duplicates, S, return all possible subsets.
 Note:
 Elements in a subset must be in non-descending order.
 The solution set must not contain duplicate subsets.
 For example,
 If S = [1,2,2], a solution is:
 [
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
 ]

 Solution: Use <set> to avoid duplicates.
 */
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> subsetsWithDup(vector<int> &S) {
        res.clear();
        res.push_back(vector<int>());
        sort(S.begin(), S.end());
        for (int setSize = 1; setSize <= S.size(); ++setSize) {
            vector<int> r;
            subsetsWithDupRe(S, r, setSize, 0, -1);
        }
        return res;
    }

    void subsetsWithDupRe(vector<int> &s, vector<int> &r, int setSize, int deep, int lastIndex)
    {
        if (deep == setSize) {
            res.push_back(r);
            return;
        }
        set<int> used;
        for (int i = lastIndex + 1; i <= s.size() - (setSize - deep); ++i) {
            if (used.find(s[i]) == used.end())
            {
                r.push_back(s[i]);
                subsetsWithDupRe(s, r, setSize, deep + 1, i);
                r.pop_back();
                used.insert(s[i]);
            }
        }
    }
};
