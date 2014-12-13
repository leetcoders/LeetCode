/*
 Author:     King, wangjingui@outlook.com
 Date:       Dec 13, 2014
 Problem:    Reverse Words in a String 
 Difficulty: Easy
 Source:     https://oj.leetcode.com/problems/reverse-words-in-a-string/
 Notes:
 Given an input string, reverse the string word by word.

 For example,
 Given s = "the sky is blue",
 return "blue is sky the".

 Solution: 1. Reverse the raw string and reverse each word.
           2. In Place.
*/

class Solution {
public:
    void reverseWords_1(string &s) {
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
    void reverseWords_2(string &s) {
        int N = s.size();
        reverse(s.begin(),s.end());
        for (string::iterator i = s.begin(); i != s.end();) {
            while (i != s.end() && *i == ' ') ++i;
            string::iterator left = i;
            while((i) != s.end() && *(i) != ' ') ++i;
            reverse(left,i);
        }
        int idx = 0;
        for (int i = 0; i < N;) {
            while (i < N && s[i] == ' ') ++i;
            while (i < N && s[i] != ' ') s[idx++] = s[i++];
            while (i < N && s[i] == ' ') ++i;
            if (i == N) break;
            s[idx++] = ' ';
        }
        s.resize(idx);
    }
};