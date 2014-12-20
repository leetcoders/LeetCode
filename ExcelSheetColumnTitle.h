/*
 Author:     King, wangjingui@outlook.com
 Date:       Dec 19, 2014
 Problem:    Excel Sheet Column Title 
 Difficulty: Easy
 Source:     https://oj.leetcode.com/problems/excel-sheet-column-title/
 Notes:
 Given a non-zero positive integer, return its corresponding column title as appear in an Excel sheet.

 For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 

 Solution: 1. Iteration.
           2&3. recursion.
 */

class Solution {
public:
    string convertToTitle_1(int n) {
        string res;
        while (n){
            res.push_back((n - 1)%26 + 'A');
            n = (n - 1) / 26;
        }
        reverse(res.begin(), res.end());
        return res;
    }
    void convertToTitleRe(int n, string &res) {
        if (n == 0) return;
        convertToTitleRe((n-1)/26, res);
        res.push_back((n-1)%26 + 'A');
    }
    string convertToTitle_2(int n) {
        string res;
        convertToTitleRe(n, res);
        return res;
    }
    void convertToTitleRe3(int n, string &res) {
        if (n == 0) return;
        res.push_back((n-1)%26 + 'A');
        convertToTitleRe3((n-1)/26, res);
    }
    string convertToTitle(int n) {
        string res;
        convertToTitleRe3(n, res);
        reverse(res.begin(), res.end());
        return res;
    }
};