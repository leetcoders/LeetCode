/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       May 17, 2013
 Update:     Jul 20, 2013
 Problem:    Generate Parentheses
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_22
 Notes:
 Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
 For example, given n = 3, a solution set is:
 "((()))", "(()())", "(())()", "()(())", "()()()"

 Solution: Place n left '(' and n right ')'.
           Cannot place ')' if there are no enough matching '('.
 */

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generateParenthesisRe(res, n, n, "");
        return res;
    }

    void generateParenthesisRe(vector<string> &res, int left, int right, string s) {
        if (left == 0 && right == 0)
            res.push_back(s);
        if (left > 0)
            generateParenthesisRe(left - 1, right, s + "(");
        if (right > left)
            generateParenthesisRe(left, right - 1, s + ")");
    }
};
