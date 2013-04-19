/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 19, 2013
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

 Solution: 1. 'threeSum_1' is my original implementation. Separate the integers into two groups: less(<0) and more(>0).
              For each less[i] and more[j], check to see if (0 - less[i] - more[j]) exists in these integers.
           2. Simplify '3sum' into '2sum'. http://en.wikipedia.org/wiki/3SUM
           3. Both of the two methods can solve the problem in O(n^2) time, but 'threeSum_1' needs more time for avoiding duplicates.
 */

class Solution {
public:
    vector<vector<int> > threeSum_1(vector<int> &num) {
        vector<vector<int>> res;
        map<int, int> count;
        vector<int> less;
        vector<int> more;
        for (int i = 0; i < num.size(); ++i) {
            if (count.find(num[i]) == count.end()) {
                count.insert(make_pair(num[i], 1));
                if (num[i] < 0) 
                    less.push_back(num[i]);
                else 
                    more.push_back(num[i]);
            } else {
                count[num[i]]++;
            }
        }
        for (int i = 0; i < less.size(); ++i)
        {
            for (int j = 0; j < more.size(); ++j)
            {
                int third = 0 - less[i] - more[j];
                if (count.find(third) == count.end())
                    continue;
                if (count[third] >= 2 || (third != less[i] && third != more[j]))
                {
                    vector<int> triplet;
                    triplet.push_back(less[i]);
                    triplet.push_back(more[j]);
                    triplet.push_back(third);
                    sort(triplet.begin(), triplet.end());
                    // avoid duplicates
                    int k;
                    for (k = 0; k < res.size(); ++k)
                    {
                        if (res[k][0] == triplet[0] && res[k][1] == triplet[1] && res[k][2] == triplet[2])
                            break;
                    }
                    if (k == res.size())
                        res.push_back(triplet);
                }
            }
        }
        if (count.find(0) != count.end() && count[0] >= 3) // 3 zeros
            res.push_back(vector<int>(3,0));
        return res;
    }

    vector<vector<int> > threeSum_2(vector<int> &num) {
        vector<vector<int>> res;
        sort(num.begin(), num.end());
        for (int i = 0; i < num.size() && num[i] <= 0; ++i)
        {
            int twosum = 0 - num[i];
            int l = i + 1, r = num.size() - 1;
            while (l < r)
            {
                int sum = num[l] + num[r];
                if (sum < twosum) {
                    l++;
                } else if (sum > twosum) {
                    r--;
                } else {
                    vector<int> triplet;
                    triplet.push_back(num[i]);
                    triplet.push_back(num[l]);
                    triplet.push_back(num[r]);
                    res.push_back(triplet);
                    while (l < r && num[l+1] == num[l]) l++;  // avoid duplicates
                    while (l < r && num[r-1] == num[r]) r--;  // avoid duplicates
                    l++; r--;
                }
            }
            while (i < num.size() && num[i+1] == num[i]) i++; // avoid duplicates
        }
        return res;
    }
};
