/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 10, 2013
 Update:     Jul 16, 2013 [Two pointers ('last' and 'lastlast').]
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
        if (n <= 2) return n;
        int lastlast = 0, last = 1;
        for (int cur = 2; cur < n; ++cur)
        {
            if (A[lastlast] != A[cur] || A[last] != A[cur])
            {
                A[++last] = A[cur];
                lastlast++;
            }
        }
        return last + 1;
    }
};
