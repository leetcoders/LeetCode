/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 16, 2013
 Update:     Jul 29, 2013
 Problem:    Longest Substring Without Repeating Characters
 Difficulty: Medium
 Source:     http://leetcode.com/onlinejudge#question_3
 Notes:
 Given a string, find the length of the longest substring without repeating characters. 
 For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. 
 For "bbbbb" the longest substring is "b", with the length of 1.

 Solution: Pay attention when moving the 'start' pointer forward. Don't forget update 'res' in the end.
 */

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        bool exist[256];
        memset(exist, 0, sizeof(exist));
        int res = 0, back = 0, front = 0, size = s.size();
        while (front < size && back + res < size)
        {
            if (!exist[s[front]])
            {
                exist[s[front++]] = true;
            }
            else
            {
                res = max(front - back, res);
                exist[s[back++]] = false;
            }
        }
        res = max(front - back, res);
        return res;
    }
};
