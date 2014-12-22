/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 19, 2013
 Update:     Sep 22, 2013
 Problem:    3Sum
 Difficulty: Medium
 Source:     http://leetcode.com/onlinejudge#question_15
 Notes:
 Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? 
 Find all unique triplets in the array which gives the sum of zero.
 Note:
 Elements in a triplet (a,b,c) must be in non-descending order. (ie, a <= b <= c)
 The solution set must not contain duplicate triplets.
 For example, given array S = {-1 0 1 2 -1 -4},
 A solution set is:
 (-1, 0, 1)
 (-1, -1, 2)

 Solution: Simplify '3sum' to '2sum' O(n^2). http://en.wikipedia.org/wiki/3SUM
*/

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int>> res;
        sort(num.begin(), num.end());
        int N = num.size();
        for (int i = 0; i < N-2 && num[i] <= 0; ++i)
        {
            if (i > 0 && num[i] == num[i-1])
                continue; // avoid duplicates
            int twosum = 0 - num[i];
            int l = i + 1, r = N - 1;
            while (l < r)
            {
                int sum = num[l] + num[r];
                if (sum < twosum)
                    l++;
                else if (sum > twosum)
                    r--;
                else {
                    res.push_back(vector<int>{num[i],num[l],num[r]});
                    l++; r--;
                    while (l < r && num[l] == num[l-1]) l++;  // avoid duplicates
                    while (l < r && num[r] == num[r+1]) r--;  // avoid duplicates
                }
            }
        }
        return res;
    }
};
