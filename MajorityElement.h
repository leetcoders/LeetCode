/*
 Author:     King, wangjingui@outlook.com
 Date:       Dec 14, 2014
 Problem:    ZigZag Conversion
 Difficulty: Easy
 Source:     https://oj.leetcode.com/problems/majority-element/
 Notes:
 Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

 You may assume that the array is non-empty and the majority element always exist in the array.

 Solution: Runtime: O(n) — Moore voting algorithm: We maintain a current candidate and a counter initialized to 0. As we iterate the array, we look at the current element x:
 If the counter is 0, we set the current candidate to x and the counter to 1.
 If the counter is not 0, we increment or decrement the counter based on whether x is the current candidate.
 After one pass, the current candidate is the majority element. Runtime complexity = O(n).
 */

class Solution {
public:
    int majorityElement(vector<int> &num) {
        int n = num.size();
        if (n == 0) return 0;
        if (n == 1) return num[0];
        int cur = num[0], cnt = 1;
        for (int i = 1; i < num.size(); ++i) {
            if (cnt == 0) {
                cur = num[i];
                ++cnt;
                continue;
            }
            if (cur == num[i]) ++cnt;
            else --cnt;
        }
        return cur;
    }
};