/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 29, 2013
 Problem:    Permutations
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_46
 Notes:
 Given a collection of numbers, return all possible permutations.
 For example,
 [1,2,3] have the following permutations:
 [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].

 Solution: dfs...
 */

class Solution {
public:
    vector<vector<int>> res;

    vector<vector<int>> permute(vector<int> &num) {
        res.clear();
        vector<bool> avail(num.size(), true);
        vector<int> pum;
        permuteRe(num, avail, pum, num.size(), 0);
        return res;
    }

    void permuteRe(const vector<int> &num, vector<bool> &avail, vector<int> &pum, int N, int deep)
    {
        if (deep == N)
        {
            res.push_back(pum);
            return;
        }
        for (int i = 0; i < num.size(); ++i)
        {
            if (avail[i])
            {
                avail[i] = false;
                pum.push_back(num[i]);
                permuteRe(num, avail, pum, N, deep + 1);
                pum.pop_back();
                avail[i] = true;
            }
        }
    }
};