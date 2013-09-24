/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       May 6, 2013
 Problem:    Combination Sum II
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_40
 Notes:
 Given a collection of candidate numbers (C) and a target number (T), find all unique combinations
 in C where the candidate numbers sums to T.
 Each number in C may only be used once in the combination.
 Note:
 All numbers (including target) will be positive integers.
 Elements in a combination (a1, a2, .. , ak) must be in non-descending order. (ie, a1 <= a2 <= ... <= ak).
 The solution set must not contain duplicate combinations.
 For example, given candidate set 10,1,2,7,6,1,5 and target 8, 
 A solution set is: 
 [1, 7] 
 [1, 2, 5] 
 [2, 6] 
 [1, 1, 6] 

 Solution: ..Similar to Combination Sum I, except for line 42 && 44.
 */

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int> &num, int target) {
        vector<vector<int>> res;
        sort(num.begin(), num.end());
        vector<int> com;
        combinationSum2Re(num, target, 0, com, res);
        return res;
    }

    void combinationSum2Re(const vector<int> &num, int target, int start, vector<int> &com, vector<vector<int>> &res)
    {
        if (target == 0) {
            res.push_back(com);
            return;
        }
        for (int i = start; i < num.size() && num[i] <= target; ++i) {
            if (i > start && num[i] == num[i-1]) continue;
            com.push_back(num[i]);
            combinationSum2Re(num, target-num[i], i+1, com, res);
            com.pop_back();
        }
    }
};