/*
 Author:     King, wangjingui@outlook.com
 Date:       Dec 20, 2014
 Problem:    Majority Element
 Difficulty: Easy
 Source:     https://oj.leetcode.com/problems/majority-element/
 Notes:
 Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

 You may assume that the array is non-empty and the majority element always exist in the array.

 Solution: 1. Runtime: O(n) — Moore voting algorithm: We maintain a current candidate and a counter initialized to 0. As we iterate the array, we look at the current element x:
 If the counter is 0, we set the current candidate to x and the counter to 1.
 If the counter is not 0, we increment or decrement the counter based on whether x is the current candidate.
 After one pass, the current candidate is the majority element. Runtime complexity = O(n).
 2. Runtime: O(n) — Bit manipulation: We would need 32 iterations, each calculating the number of 1's for the ith bit of all n numbers. Since a majority must exist, therefore, either count of 1's > count of 0's or vice versa (but can never be equal). The majority number’s ith bit must be the one bit that has the greater count.
 */

class Solution {
public:
    int majorityElement_1(vector<int> &num) {
        int n = num.size();
        if (n == 0) return 0;
        if (n == 1) return num[0];
        int res = num[0], cnt = 1;
        for (int i = 1; i < num.size(); ++i) {
            if (cnt == 0) {
                res = num[i];
                ++cnt;
                continue;
            }
            if (res == num[i]) ++cnt;
            else --cnt;
        }
        return res;
    }
    int majorityElement_2(vector<int> &num) {
        int n = num.size();
        if (n == 0) return 0;
        if (n == 1) return num[0];
        int res = 0;
        for (int i = 0; i < 32; ++i) {
            int one = 0, zero = 0;
            for (int j = 0; j < n; ++j) {
                if (((num[j]>>i) & 1) == 1) ++one;
                else ++zero;
            }
            if (one > zero) res = res | (1<<i);
        }
        return res;
    }
};