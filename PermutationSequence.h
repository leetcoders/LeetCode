/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       May 8, 2013
 Problem:    Permutation Sequence
 Difficulty: Medium
 Source:     http://leetcode.com/onlinejudge#question_60
 Notes:
 The set [1,2,3,...,n] contains a total of n! unique permutations.
 By listing and labeling all of the permutations in order,
 We get the following sequence (ie, for n = 3):
 "123"
 "132"
 "213"
 "231"
 "312"
 "321"
 Given n and k, return the kth permutation sequence.
 Note: Given n will be between 1 and 9 inclusive.

 Solution: Quite fast..Finish 'Large Test' in less than 16ms.
           If we fix the first m digits, there'll be (n-m)! different permutations for the latter m digits.
           Decide the digits from left to right...
 */

class Solution {
public:
    string getPermutation(int n, int k) {
        string res;
        list<int> nums;
        int count = 1, digits = n - 1;
        for (int i = 1; i <= n; ++i)
        {
            if (i < n) count *= i;
            nums.push_back(i);
        }
        while (res.size() < n)
        {
            list<int>::iterator it = nums.begin();
            for (int m = 1; m < (int)ceil(k*1.0 / count); ++m)
                it++;
            res += char(*it + '0');
            nums.erase(it);
            k = (k % count == 0) ? count : k % count;
            count = (count == 1) ? 1 : count / digits--;
        }
        return res;
    }
};