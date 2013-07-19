/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 9, 2013
 Update:     Jul 19, 2013 (Refactor)
 Problem:    Implement strStr()
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_28
 Notes:
 Implement strStr().
 Returns a pointer to the first occurrence of needle in haystack, or null if needle is not part of haystack.

 Solution: Check in the haystack one by one. If not equal to needle, reset the pointer.
 */

class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        while(true)
        {
            char *h = haystack, *n = needle;
            while (*n != '\0' && *h == *n)
            {
                h++; 
                n++;
            }
            if (*n == '\0') return haystack;
            if (*h == '\0') return NULL;
            haystack++;
        }
    }
};
