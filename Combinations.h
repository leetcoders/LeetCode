/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       May 5, 2013
 Update:     Sep 28, 2013
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
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > res;
        vector<int> com;
        combineRe(n, k, 1, com, res);
        return res;
    }
    
    void combineRe(int n, int k, int start, vector<int> &com, vector<vector<int> > &res){
        int m = com.size();
        if (m == k) {
            res.push_back(com);
            return;
        }
        for (int i = start; i <= n-(k-m)+1; ++i) {
            com.push_back(i);
            combineRe(n, k, i+1, com, res);
            com.pop_back();
        }
    }
};