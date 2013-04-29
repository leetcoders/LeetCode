/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 29, 2013
 Problem:    Permutations II
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_47
 Notes:
 Given a collection of numbers that might contain duplicates, return all possible unique permutations.
 For example,
 [1,1,2] have the following unique permutations:
 [1,1,2], [1,2,1], and [2,1,1].

 Solution: dfs...use <set> to avoid duplicates.
 */

class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> permuteUnique(vector<int> &num) {
        res.clear();
        vector<bool> avail(num.size(), true);
        vector<int> pum;
        permuteUniqueRe(num, avail, pum, num.size(), 0);
        return res;
    }

    void permuteUniqueRe(vector<int> &num, vector<bool> &avail, vector<int> &pum, int N, int deep)
    {
        if (deep == N)
        {
            res.push_back(pum);
            return;
        }
        set<int> used;
        for (int i = 0; i < num.size(); ++i)
        {
            if (avail[i] && used.find(num[i]) == used.end())
            {
                avail[i] = false;
                pum.push_back(num[i]);
                permuteUniqueRe(num, avail, pum, N, deep + 1);
                pum.pop_back();
                avail[i] = true;
                used.insert(num[i]);
            }
        }
    }
};