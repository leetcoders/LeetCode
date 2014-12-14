/*
 Author:     King, wangjingui@outlook.com
 Date:       Dec 14, 2014 
 Problem:    Maximum Gap
 Difficulty: Hard
 Source:     https://oj.leetcode.com/problems/maximum-gap/
 Notes:
 Given an unsorted array, find the maximum difference between the successive elements in its sorted form.

 Try to solve it in linear time/space.

 Return 0 if the array contains less than 2 elements.

 You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.

 Solution: 1. Time : O(nlogn). Space : O(1); 
              Sort the unsorted array, and find the maximum difference.
           2. Time : O(n). Space : O(n).
              Drawer Theory. If we put n numbers into (n+1) drawers, 
              then there must be at least one empty drawer. 
              So we can find the maximum difference between two succesive non-empty drawers.
 */

class Solution {
public:
    int maximumGap_1(vector<int> &num) {
        sort(num.begin(), num.end());
        int res = 0;
        for (int i = 1; i < num.size(); ++i) {
            res = max(res, num[i] - num[i-1]);
        }
        return res;
    }
    int maximumGap_2(vector<int> &num) {
        int n = num.size();
        if (n < 2) return 0;
        int minVal = num[0], maxVal = num[0];
        for (int i = 1; i < n; ++i) {
            minVal = min(minVal, num[i]);
            maxVal = max(maxVal, num[i]);
        }
        //delta = (maxVal + 1 - minVal) / (n + 1)
        //idx = (val - minVal) / delta = (val - minVal) * (n + 1) / (maxVal + 1 - minVal)
        vector<pair<int,int> > pool(n+2,make_pair(-1,-1));
        for (int i = 0; i < n; ++i) {
            int idx = (long long)(num[i] - minVal)* (n + 1) / (maxVal + 1 - minVal);
            if (pool[idx].first == -1) {
                pool[idx] = make_pair(num[i],num[i]);
            } else {
                pool[idx].first = min(pool[idx].first, num[i]);
                pool[idx].second = max(pool[idx].second, num[i]);
            }
        }
        int last = pool[0].second;
        int res = 0;
        for (int i = 1; i < n + 2; ++i) {
            if (pool[i].first != -1) {
                res = max(res, pool[i].first - last);
                last = pool[i].second;
            }
        }
        return res;
    }
};