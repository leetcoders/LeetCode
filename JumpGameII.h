/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 21, 2013
 Problem:    Jump Game II
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_45
 Notes:
 Given an array of non-negative integers, you are initially positioned at the first index of the array.
 Each element in the array represents your maximum jump length at that position.
 Your goal is to reach the last index in the minimum number of jumps.
 For example:
 Given array A = [2,3,1,1,4]
 The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)

 Solution: Jump to the position where we can jump farthest (index + A[index]) next time.
 */

class Solution {
public:
    int jump(int A[], int n) {
        if (n <= 1) return 0;
        int res = 0;
        int i = 0;
        while (i < n - 1)
        {
            int max_jump = i + A[i];
            if (i + A[i] < n - 1) 
            {
                for (int j = i + 1; j < min(i + A[i], n - 1); ++j)
                    if (j + A[j] > max_jump + A[max_jump])
                        max_jump = j;
            }
            i = max_jump;
            res++;
        }
        return res;
    }
};