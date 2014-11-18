/*
 Author:     Annie Kim, anniekim.pku@gmail.com : King, higuige@gmail.com
 Date:       Apr 30, 2013
 Update:     Nov 18, 2014
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

 Solution: ..Similar to Subset I.
 */
class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<vector<int>> res;
        sort(S.begin(), S.end());
        vector<int> path;
        dfs(S,res,path,0);
        return res;
    }
    void dfs(vector<int> &S, vector<vector<int>>& res, vector<int>&path, size_t step) {
        res.push_back(path);
        for (int i = step; i < S.size(); ++i) {
            if(i!=step&&S[i]==S[i-1]) continue;
            path.push_back(S[i]);
            dfs(S,res,path,i+1);
            path.pop_back();
        }
    }
    // Solution 2. iterative solution.
    vector<vector<int> > subsetsWithDup_2(vector<int> &S) {
        vector<vector<int> > res(1);
        sort(S.begin(),S.end());
        size_t presz = 0;
        for(int i=0;i<S.size();i++){
            int sz = res.size();
            for (int j = 0; j < sz; ++j) {
                if(i==0||S[i]!=S[i-1]||j >= presz) {
                    res.push_back(res[j]);
                    res.back().push_back(S[i]);
                }
            }
            presz = sz;
        }
        return res;
    }
};