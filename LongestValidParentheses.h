/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       May 6, 2013
 Problem:    Longest Valid Parentheses
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_32
 Notes:
 Given a string containing just the characters '(' and ')', find the length of the longest valid 
 (well-formed) parentheses substring.
 For "(()", the longest valid parentheses substring is "()", which has length = 2.
 Another example is ")()())", where the longest valid parentheses substring is "()()", 
 which has length = 4.

 Solution: Traverse the string twice, taking O(n) time.
           First time, mark all the matching parentheses as '*' (push the index of '(' into <stack>).
           Second time, count the longest consecutive '*'.
 */

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> stk;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '(') {
                stk.push(i);
            } else if (!stk.empty()) {
                s[stk.top()] = '*';
                s[i] = '*';
                stk.pop();
            }
        }

        int res = 0, part = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '*') {
                part++;
            } else {
                res = max(res, part);
                part = 0;
            }
        }
        res = max(res, part);
        return res;
    }
};
