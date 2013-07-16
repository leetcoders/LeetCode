/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 10, 2013
 Update:     Jul 16, 2013
 Problem:    Remove Duplicates from Sorted Array
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_26
 Notes:
 Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
 Do not allocate extra space for another array, you must do this in place with constant memory.
 For example,
 Given input array A = [1,1,2],
 Your function should return length = 2, and A is now [1,2].

 Solution: Update 7/16/2013: Let j start from 0 for better understanding.
 */

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n == 0 || n == 1) return n;
        int j = 0;
        for (int i = 1; i < n; i++)
            if (A[i] != A[j])
                A[++j] = A[i];
        return j + 1;
    }
};
