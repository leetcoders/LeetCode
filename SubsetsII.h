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

 Solution: ..Similar to Subset I, except for line 45.
 */
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int> &S) {
        vector<vector<int> > res(1, vector<int>());
        sort(S.begin(), S.end());
        vector<int> set;
        int N = S.size();
        for (int l = 1; l <= N; ++l)
            subsetsWithDupRe(S, l, 0, set, res);
        return res;
    }

    void subsetsWithDupRe(vector<int> &S, int L, int start, vector<int> &set, vector<vector<int>> &res)
    {
        int N = S.size(), M = set.size();
        if (M == L) {
            res.push_back(set);
            return;
        }
        for (int i = start; i <= N - (L - M); ++i) {
            if (i > start && S[i] == S[i-1]) continue;
            set.push_back(S[i]);
            subsetsWithDupRe(S, L, i + 1, set, res);
            set.pop_back();
        }
    }
};