/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 28, 2013
 Problem:    Best Time to Buy and Sell Stock II
 Difficulty: Medium
 Source:     http://leetcode.com/onlinejudge#question_122
 Notes:
 Say you have an array for which the ith element is the price of a given stock on day i.
 Design an algorithm to find the maximum profit. You may complete as many transactions as you like 
 (ie, buy one and sell one share of the stock multiple times). 
 However, you may not engage in multiple transactions at the same time 
 (ie, you must sell the stock before you buy again).

 Solution: 1. At the beginning of the ascending order: buy.
              At the ending of the ascending order: sell.
           2. For ascending order [1,2,4], (4 - 1) == (2 - 1) + (4 - 2).
 */

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        return maxProfit_2(prices);
    }
    int maxProfit_1(vector<int> &prices) {
        int res = 0;
        int buy_i = -1;
        for (int i = 1; i < prices.size(); ++i)
        {
            if (prices[i] > prices[i-1] && buy_i == -1)
            {
                buy_i = i - 1;
            }
            else if (prices[i] < prices[i -1] && buy_i != -1)
            {
                res += prices[i-1] - prices[buy_i];
                buy_i = -1;
            }
        }
        if (buy_i != -1)
            res += prices[prices.size() - 1] - prices[buy_i];
        return res;
    }

    int maxProfit_2(vector<int> &prices) {
        int res = 0;
        for (int i = 1; i < prices.size(); ++i)
            if (prices[i] > prices[i-1])
                res += prices[i] - prices[i-1];
        return res;
    }
};
