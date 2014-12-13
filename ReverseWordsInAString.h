/*
 Author:     King, wangjingui@outlook.com
 Date:       Dec 13, 2014
 Problem:    Reorder List
 Difficulty: Easy
 Source:     https://oj.leetcode.com/problems/reverse-words-in-a-string/
 Notes:
 Given an input string, reverse the string word by word.

 For example,
 Given s = "the sky is blue",
 return "blue is sky the".

 Solution: Reverse the raw string and reverse each word.
*/

class Solution {
public:
    void reverseWords(string &s) {
        string res;
        reverse(s.begin(),s.end());
        for (int i = 0; i < s.size(); ++i) {
            while (i < s.size() && s[i] == ' ') ++i;
            if(i == s.size()) break;
            string tmp;
            while(i < s.size() && s[i] != ' ') tmp.push_back(s[i++]);
            reverse(tmp.begin(), tmp.end());
            if (!res.empty()) res = res + " " + tmp;
            else res = res + tmp;
        }
        s = res;
    }
};