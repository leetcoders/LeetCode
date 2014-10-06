/*
 Author:     Annie Kim, anniekim.pku@gmail.com : King, higuige@gmail.com
 Date:       Apr 28, 2013
 Update:     Oct 07, 2014
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
        int size = prices.size();
        if (prices.empty()) return 0;
        int minVal = prices[0], res = 0;
        for (int i = 1; i < size; ++i)
        {
            minVal = min(minVal, prices[i]);
            res = max(res, prices[i] - minVal);
        }
        return res;
    }
};
