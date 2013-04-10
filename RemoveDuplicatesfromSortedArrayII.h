/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 10, 2013
 Problem:    Remove Duplicates from Sorted Array II
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_80
 Notes:
 Follow up for "Remove Duplicates":
 What if duplicates are allowed at most twice?
 For example,
 Given sorted array A = [1,1,1,2,2,3],
 Your function should return length = 5, and A is now [1,1,2,2,3].

 Solution: ...
 */

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n == 0 || n == 1) return n;
        int j = 1;
        int count = 1;
        for (int i = 1; i < n; i++)
            if (A[i] != A[j-1])
            {
                A[j++] = A[i];
                count = 1;
            }
            else
            {
                if (count < 2)
                    A[j++] = A[i];
                count++;
            }
        return j;
    }
};