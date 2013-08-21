/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 28, 2013
 Update:     Aug 22, 2013
 Problem:    Best Time to Buy and Sell Stock III
 Difficulty: Medium
 Source:     http://leetcode.com/onlinejudge#question_123
 Notes:
 Say you have an array for which the ith element is the price of a given stock on day i.
 Design an algorithm to find the maximum profit. You may complete at most two transactions.
 Note:
 You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

 Solution: dp. max profit =  max { l2r[0...i] + r2l[i+1...N-1] }.
                         0 <= i <= N-1
 */

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int N = prices.size();
        if (N <= 1) return 0;
        
        int l2r[N], r2l[N];
        l2r[0] = 0;
        r2l[N-1] = 0;
        
        int minn = prices[0];
        for (int i = 1; i < N; ++i)
        {
            minn = min(minn, prices[i]);
            l2r[i] = max(l2r[i-1], prices[i] - minn);
        }
        
        int maxx = prices[N-1];
        for (int i = N-2; i >= 0; --i)
        {
            maxx = max(maxx, prices[i]);
            r2l[i] = max(r2l[i+1], maxx - prices[i]);
        }
        
        int res = l2r[N-1];
        for (int i = 0; i < N-1; ++i)
            res = max(res, l2r[i] + r2l[i+1]);
        return res;
    }
};
