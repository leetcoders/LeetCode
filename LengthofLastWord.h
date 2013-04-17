/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 17, 2013
 Problem:    Length of Last Word
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_58
 Notes:
 Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.
 If the last word does not exist, return 0.
 Note: A word is defined as a character sequence consists of non-space characters only.
 For example, 
 Given s = "Hello World",
 return 5.

 Solution: ...
 */

class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int res = 0;
        int i = strlen(s) - 1;
        while (s[i] == ' ') 
            i--;
        for (; i >= 0; --i)
            if (s[i] != ' ') res++;
            else break;
        return res;
    }
};
