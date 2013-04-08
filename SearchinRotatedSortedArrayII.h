/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 8, 2013
 Problem:    Search in Rotated Sorted Array II
 Difficulty: Medium
 Source:     http://leetcode.com/onlinejudge#question_81
 Notes:
 Suppose a sorted array is rotated at some pivot unknown to you beforehand.
 (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 What if duplicates are allowed?
 Would this affect the run-time complexity? How and why?
 Write a function to determine if a given target is in the array.

 Solution: Sequence search. O(n)
           Since there are duplicates, it's hard to decide which branch to go if binary-search is deployed.
 */

class Solution {
public:
    bool search(int A[], int n, int target) {
        for (int i = 0; i < n; i++)
            if (A[i] == target)
                return true;
        return false;
    }
};