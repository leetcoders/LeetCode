/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 8, 2013
 Problem:    Search in Rotated Sorted Array
 Difficulty: Medium
 Source:     http://leetcode.com/onlinejudge#question_33
 Notes:
 Suppose a sorted array is rotated at some pivot unknown to you beforehand.
 (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 You are given a target value to search. If found in the array return its index, otherwise return -1.
 You may assume no duplicate exists in the array.

 Solution: 
 1. Sequence search. O(n)
 2. Binary search. O(lgn) eg. [4 5 6] -7- 8 1 2, 5 6 0 -1- [2 3 4]
 */

class Solution {
public:
    int search_1(int A[], int n, int target) {
        if (A[0] == target)
            return 0;
        else if (n == 1)
            return -1;
        else if (A[0] > target)
            for (int i = n - 1; i >= 0; i--)
			{
                if (A[i] == target)
                    return i;
                if (A[i] < target || i == 0)
                    return -1;
            }
        else
            for (int i = 1; i < n; i++)
			{
                if (A[i] == target)
                    return i;
                if (A[i] > target || i == n - 1)
                    return -1;
            }
    }

    int search_2(int A[], int n, int target) {
        int f = 0;
        int b = n - 1;
        
        while (f <= b)
        {
            int mid = (f + b) / 2;
            if (A[mid] == target)
                return mid;
            
            if (A[f] > A[mid])
            {
                if (target > A[mid] && target < A[f])
                    f = mid + 1;
                else
                    b = mid - 1;
            }
            else
            {
                if (target >= A[f] && target < A[mid])
                    b = mid - 1;
                else
                    f = mid + 1;
            }
        }
        
        return -1;
    }
};
