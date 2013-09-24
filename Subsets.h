/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 24, 2013
 Update:     Sep 16, 2013
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

 Solution: 1. Recursive solution.
           2. Iterative solution. Contributed by yinlinglin.
 */

class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        return subsets_1(S);
    }
    
    vector<vector<int> > subsets_1(vector<int> &S) {
        vector<vector<int> > res(1, vector<int>());
        sort(S.begin(), S.end());
        vector<int> set;
        int N = S.size();
        for (int l = 1; l <= N; ++l)
            subsetsRe(S, l, 0, set, res);
        return res;
    }
    
    void subsetsRe(vector<int> &S, int L, int start, vector<int> &set, vector<vector<int> > &res)
    {
        int N = S.size(), M = set.size();
        if (M == L) {
            res.push_back(set);
            return;
        }
        for (int i = start; i <= N - (L - M); ++i) {
            set.push_back(S[i]);
            subsetsRe(S, L, i + 1, set, res);
            set.pop_back();
        }
    }
    
    vector<vector<int> > subsets_2(vector<int> &S) {
        vector<vector<int> > res(1, vector<int>());
        sort(S.begin(), S.end());
        int N = S.size();
        for (int L = 1; L <= N; ++L)
        {
            int stk[L];
            stk[0] = 0;
            int top = 0;
            while (true)
            {
                if (stk[top] == N)
                {
                    top--;
                    if (top < 0) break;
                    stk[top]++;
                }
                else if (top == L - 1) 
                {
                    vector<int> set;
                    for (int i = 0; i < L; ++i)
                        set.push_back(S[stk[i]]);
                    res.push_back(set);
                    stk[top]++;
                }
                else
                {
                    top++;
                    stk[top] = stk[top-1] + 1;
                }
            }
        }
        return res;
    }
};
