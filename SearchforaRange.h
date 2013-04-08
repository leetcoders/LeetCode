/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 8, 2013
 Problem:    Search for a Range
 Difficulty: Medium
 Source:     http://leetcode.com/onlinejudge#question_34
 Notes:
 Given a sorted array of integers, find the starting and ending position of a given target value.

 Your algorithm's runtime complexity must be in the order of O(log n).

 If the target is not found in the array, return [-1, -1].

 For example,
 Given [5, 7, 7, 8, 8, 10] and target value 8,
 return [3, 4].

 Solution: It takes O(lgN) to find both the lower-bound and upper-bound.
 */

class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        vector<int> res(2, -1);
        int lower = lowerBound(A, n, target);
        int upper = upperBound(A, n, target);
        
        if (lower > upper)
            return res;
        
        res[0] = lower;
        res[1] = upper;
        
        return res;
    }
    
    int lowerBound(int A[], int n, int target)
    {
        int f = 0;
        int b = n - 1;
        
        while (f <= b)
        {
            int mid = (f + b) / 2;
            if (A[mid] >= target)
                b = mid - 1;
            else
                f = mid + 1;
        }
        
        return b + 1;
    }
    
    int upperBound(int A[], int n, int target)
    {
        int f = 0;
        int b = n - 1;
        
        while (f <= b)
        {
            int mid = (f + b) / 2;
            if (A[mid] <= target)
                f = mid + 1;
            else
                b = mid - 1;
        }
        
        return f - 1;
    }
};