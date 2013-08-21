/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 28, 2013
 Problem:    Best Time to Buy and Sell Stock
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_121
 Notes:
 Say you have an array for which the ith element is the price of a given stock on day i.
 If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), 
 design an algorithm to find the maximum profit.

 Solution: For each element, calculate the max difference with the former elements.
 */

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int imin = 0;
        int res = 0;
        for (int i = 1; i < prices.size(); ++i)
        {
            if (prices[i] < prices[imin])
                imin = i;
            res = max(res, prices[i] - prices[imin]);
        }
        return res;
    }
};
