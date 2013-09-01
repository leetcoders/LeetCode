/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 29, 2013
 Update:     Sep 2, 2013
 Problem:    Permutations II
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_47
 Notes:
 Given a collection of numbers that might contain duplicates, return all possible unique permutations.
 For example,
 [1,1,2] have the following unique permutations:
 [1,1,2], [1,2,1], and [2,1,1].

 Solution: dfs...
 */

class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> permuteUnique(vector<int> &num) {
        res.clear();
        sort(num.begin(), num.end());
        bool avail[num.size()];
        memset(avail, true, sizeof(avail));
        vector<int> pum;
        permuteUniqueRe(num, pum, avail);
        return res;
    }

    void permuteUniqueRe(vector<int> &num, vector<int> &pum, bool avail[])
    {
        if (pum.size() == num.size())
        {
            res.push_back(pum);
            return;
        }
        int last_index = -1;
        for (int i = 0; i < num.size(); ++i)
        {
            if (!avail[i]) continue;
            if (last_index != -1 && num[i] == num[last_index]) continue;
            
            avail[i] = false;
            pum.push_back(num[i]);
            permuteUniqueRe(num, pum, avail);
            pum.pop_back();
            avail[i] = true;
            last_index = i;
        }
    }
};
