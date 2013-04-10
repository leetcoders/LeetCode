/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 10, 2013
 Problem:    Remove Element
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_27
 Notes:
 Given an array and a value, remove all instances of that value in place and return the new length.
 The order of elements can be changed. It doesn't matter what you leave beyond the new length.

 Solution: Move the back elements to the front if the front is equal to 'elem'.
 */

class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int i = 0;
        int j = n - 1;
        while (i < j)
            if (A[i] == elem) A[i] = A[j--];
            else i++;
        
        return A[i] == elem ? i : min(n, i + 1);
    }
};