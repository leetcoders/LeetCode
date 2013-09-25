/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 10, 2013
 Update:     Jul 20, 2013
 Problem:    Remove Element
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_27
 Notes:
 Given an array and a value, remove all instances of that value in place and return the new length.
 The order of elements can be changed. It doesn't matter what you leave beyond the new length.

 Solution: Refactor: Update solution. Use two pointers.
 */

class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int i = 0;
        for (int j = 0; j < n; ++j)
            if (A[j] != elem)
                A[i++] = A[j];
        return i;
    }
};
