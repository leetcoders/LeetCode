/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       May 25, 2013
 Problem:    Combination Sum
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_39
 Notes:
 Given a set of candidate numbers (C) and a target number (T), find all unique 
 combinations in C where the candidate numbers sums to T.
 The same repeated number may be chosen from C unlimited number of times.
 Note:
 All numbers (including target) will be positive integers.
 Elements in a combination (a1, a2, .. , ak) must be in non-descending order. (ie, a1 <= a2 <= ... <= ak).
 The solution set must not contain duplicate combinations.
 For example, given candidate set 2,3,6,7 and target 7, 
 A solution set is: 
 [7] 
 [2, 2, 3] 

 Solution: Sort & Recursion.
*/

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        vector<vector<int>> res;
        sort(candidates.begin(), candidates.end());
        vector<int> com;
        combinationSumRe(candidates, target, 0, com, res);
        return res;
    }

    void combinationSumRe(const vector<int> &num, int target, int start, vector<int> &com, vector<vector<int>> &res)
    {
        if (target == 0) {
            res.push_back(com);
            return;
        }
        for (int i = start; i < num.size() && target >= num[i]; ++i) {
            com.push_back(num[i]);
            combinationSumRe(num, target-num[i], i, com, res);
            com.pop_back();
        }
    }
};