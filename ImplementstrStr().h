/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 9, 2013
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
        int i = 0;
        int j = 0;
        int index = 0;
        while (haystack[i] != '\0' && needle[j] != '\0')
        {
            if (haystack[i] == needle[j]) {
                if (j == 0)
                    index = i;
                j++;
            } else {
                if (j > 0) {
                    i = index;  // reset
                    j = 0;
                }
            }
            
            i++;
        }
        
        if (needle[j] == '\0')
            return haystack + index;
        else
            return NULL;
    }
};