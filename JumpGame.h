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

 Solution: Updated solution: try every reachable index. Thank to Wenxin Xing for kindly feedback:)
 */

class Solution {
public:
    bool canJump(int A[], int n) {
        int reachable = 0;
        for (int i = 0; i <= reachable && reachable < n-1; ++i)
            reachable = max(reachable, i + A[i]);
        return reachable >= n-1;
    }

    // My first solution, which is totally wrong but still able to pass OJ --|
    // Wrong answer for test cases: {3,4,0,0,1,1} & {2,2,2,3,0,0}
    bool canJump_Wrong(int A[], int n) {
        int i = 0;
        while (i < n && A[i] > 0)
            i += A[i];
        return (i >= n-1);
    }
};