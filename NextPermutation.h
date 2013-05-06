/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       May 6, 2013
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
        int i = num.size() - 1;
        while (i > 0 && num[i] <= num[i-1]) 
            i--;
        sort(num.begin() + i, num.end());
        if (i == 0) 
            return;
        int j = i;
        while (j < num.size() && num[j] <= num[i-1])
            j++;
        swap(num[j], num[i-1]);
    }
};