/*
 Author:     Annie Kim, anniekim.pku@gmail.com : King, wangjingui@outlook.com
 Date:       May 6, 2013
 Update:     Dec 16, 2014
 Problem:    Next Permutation
 Difficulty: Medium
 Source:     http://leetcode.com/onlinejudge#question_31
 Notes:
 Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
 If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
 The replacement must be in-place, do not allocate extra memory.
 Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
 1,2,3 -> 1,3,2
 3,2,1 -> 1,2,3
 1,1,5 -> 1,5,1

 Solution: O(n)
 Processes: Take A = {1,3,2} as an example:
            1. Traverse from back to forth, find the turning point, that is A[i] = 3.
            2. Sort from the turning point to the end (A[i] to A[end]), so {3,2} becomes {2,3}.
            3. If i equals to 0, finish! Else, goto 4.
            4. Let j = i, search from A[j] to A[end] to find the first elem which is larger than A[i-1], '2' here.
            5. Swap the elem A[j] with A[i-1].
            Finally, the next permutation is {2,1,3}.
 */

class Solution {
public:
    void nextPermutation(vector<int> &num) {
        int n = num.size(), i = n - 1, j = 0;
        while(i > 0 && num[i-1] >= num[i]) --i;
        reverse(num.begin() + i,num.end());
        if (i == 0) return;
        while (i+j < n && num[i-1] >= num[i+j]) ++j;
        swap(num[i-1], num[i+j]);
    }
};