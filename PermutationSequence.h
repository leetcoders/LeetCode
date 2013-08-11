/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       May 8, 2013
 Update:     Aug 12, 2013
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

 Solution: ...
 */

class Solution {
public:
    string getPermutation(int n, int k) {
        string num, res;
        int total = 1;
        for (int i = 1; i <= n; ++i)
        {
            num.push_back(i + '0');
            total *= i;
        }
        k--;
        while (n)
        {
            total /= n;
            int i = k / total;
            k %= total;
            res.push_back(num[i]);
            num.erase(i, 1);
            n--;
        }
        return res;
    }
};
