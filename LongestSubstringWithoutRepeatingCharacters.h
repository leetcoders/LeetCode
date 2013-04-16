/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 16, 2013
 Problem:    Longest Substring Without Repeating Characters
 Difficulty: Medium
 Source:     http://leetcode.com/onlinejudge#question_3
 Notes:
 Given a string, find the length of the longest substring without repeating characters. 
 For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. 
 For "bbbbb" the longest substring is "b", with the length of 1.

 Solution: Pay attention when moving the 'start' pointer forward.
 */

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        bool visited[256]; 
        memset(visited, 0, sizeof(visited));
        int start = 0, end = 0, size = s.size();
        while (start + res < size && end < size)
        {
            while (end < size && !visited[s[end]])
                visited[s[end++]] = true;

            res = max(end-start, res);
            while (start < end && s[start] != s[end])
                visited[s[start++]] = false;

            start++;
            end++;
        }
        return res;
    }
};