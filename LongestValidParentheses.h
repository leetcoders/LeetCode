/*
 Author:     Annie Kim, anniekim.pku@gmail.com : Andy, nkuwjg@gmail.com
 Date:       May 6, 2013
 Update:     Jan 15, 2015
 Problem:    Longest Valid Parentheses
 Difficulty: Easy
 Source:     https://oj.leetcode.com/problems/longest-valid-parentheses/
 Notes:
 Given a string containing just the characters '(' and ')', find the length of the longest valid 
 (well-formed) parentheses substring.
 For "(()", the longest valid parentheses substring is "()", which has length = 2.
 Another example is ")()())", where the longest valid parentheses substring is "()()", 
 which has length = 4.

 Solution: O(n).
 */

class Solution {
public:
    int longestValidParentheses(string s) {
        return longestValidParentheses_1(s);
    }
    
    // Solution 1, from fuwutu. Smart!
    // push the length of last valid parentheses into stack.
    int longestValidParentheses_1(string s) {
        stack<int> stk;
        int res = 0, count = 0;
        for(int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                stk.push(count);
                count = 0;
            } else if (!stk.empty()) {
                count += (1 + stk.top());
                stk.pop();
                res = max(res, count);
            } else {
                count = 0;
            }
        }
        return res * 2;
    }
    
    // Solution 2, By Annie.
    // Traverse the string twice, taking O(n) time.
    // First time, mark all the matching parentheses as '*' (push the index of '(' into <stack>).
    // Second time, count the longest consecutive '*'.
    int longestValidParentheses_2(string s) {
        stack<int> stk;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                stk.push(i);
            } else if (!stk.empty()) {
                s[stk.top()] = '*';
                s[i] = '*';
                stk.pop();
            }
        }
        int res = 0, part = 0;
        for (int i = 0; i < s.size(); ++i) {
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
    // Dp Solution. By Andy.
    int longestValidParentheses_3(string s) {
        int n = s.size();
        if(s.empty()) return 0;
        if(n<=1) return 0;
        int res = 0;
        vector<int> f(n,0);
        for(int i=n-2;i>=0;i--){
            int match = i + f[i+1] + 1;
            if(match<n&&s[i]=='('&&s[match]==')'){
                f[i]=f[i+1]+2;
                if(match+1<n) f[i]+=f[match+1];
            }
            res = max(res,f[i]);
        }
        return res;
    }
    // From Sun Mian.
    // O(1) Space, and Traverse the string twice, taking O(n) time.
    int longestValidParentheses_4(string s) {
        int counter = 0, val = 0, res = 0;
        for (int i = 0; i < s.length(); ++i) {
            counter += s[i] == '(' ? 1 : -1;
            if (counter < 0) {
                val = counter = 0;
                continue;
            }
            val += s[i] == '(' ? 0 : 2;
            res = counter == 0 ? max(res, val) : res;
        }
        val = counter = 0;
        for (int i = s.length() - 1; i >= 0; --i) {
            counter += s[i] == ')' ? 1 : -1;
            if (counter < 0) {
                val = counter = 0;
                continue;
            }
            val += s[i] == ')' ? 0 : 2;
            res = counter == 0 ? max(res, val) : res;
        }
        return res;
    }
};