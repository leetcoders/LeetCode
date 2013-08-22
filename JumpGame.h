/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 21, 2013
 Update:     Jul 12, 2013
 Problem:    Jump Game
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_55
 Notes:
 Given an array of non-negative integers, you are initially positioned at the first index of the array.
 Each element in the array represents your maximum jump length at that position.
 Determine if you are able to reach the last index.
 For example:
 A = [2,3,1,1,4], return true.
 A = [3,2,1,0,4], return false.

 Solution: Updated solution: try every reachable index. 
           Thank to Wenxin Xing for kindly feedback and pointing out my big mistake:)
 */

class Solution {
public:
    bool canJump(int A[], int n) {
        int start = 0, end = 0;
        while (start <= end && end < n-1)
        {
            end = max(end, start + A[start]);
            start++;
        }
        return end >= (n-1);
    }
};
