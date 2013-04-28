/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 28, 2013
 Problem:    Best Time to Buy and Sell Stock III
 Difficulty: Medium
 Source:     http://leetcode.com/onlinejudge#question_123
 Notes:
 Say you have an array for which the ith element is the price of a given stock on day i.
 Design an algorithm to find the maximum profit. You may complete at most two transactions.
 Note:
 You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

 Solution: dp.
 */

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int N = prices.size();
        vector<int> l2r(N, 0);   // [1, i]
        vector<int> r2l(N, 0);   // [i + 1, N]

        int imin = 0;
        for (int i = 1; i < N; ++i)
        {
            if (prices[i] < prices[imin])
                imin = i;
            l2r[i] = max(l2r[i-1], prices[i] - prices[imin]);
        }

        int imax = N - 1;
        for (int i = N - 3; i >= 0; --i)
        {
            if (prices[i+1] > prices[imax])
                imax = i + 1;
            r2l[i] = max(r2l[i+1], prices[imax] - prices[i+1]);
        }

        int res = 0;
        for (int i = 0; i < N; ++i)
            res = max(res, l2r[i] + r2l[i]);
        return res;
    }
};

