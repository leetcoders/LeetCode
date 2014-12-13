/*
 Author:     Annie Kim, anniekim.pku@gmail.com, King, wangjingui@outlook.com
 Date:       Apr 16, 2013
 Update:     Dec 12, 2014
 Problem:    Longest Substring Without Repeating Characters
 Difficulty: Medium
 Source:     https://oj.leetcode.com/problems/longest-substring-without-repeating-characters/
 Notes:
 Given a string, find the length of the longest substring without repeating characters. 
 For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. 
 For "bbbbb" the longest substring is "b", with the length of 1.

 Solution: 1. Pay attention when moving the 'start' pointer forward.
           2. More space, but maybe faster.
 */

class Solution {
public:
    int lengthOfLongestSubstring_1(string s) {
        bool exist[256];
        memset(exist, false, sizeof(exist));
        int res = 0;
        int start = 0, end = 0, N = s.size();
        while (end < N && start + res < N)
        {
            if (!exist[s[end]])
                exist[s[end++]] = true;
            else
                exist[s[start++]] = false;
            res = max(end - start, res);
        }
        return res;
    }
    int lengthOfLongestSubstring_2(string s) {
        int len =  s.length();
        if(len <= 1) return len;
        vector<int> hash(256,-1);
        hash[s[0]]=0;
        int start = 0, cur = 0, res = 1;
        while(++cur < len){
            if(hash[s[cur]]>=start){
                start = hash[s[cur]]+1;
            }
            res = max (res, cur - start + 1);
            hash[s[cur]] = cur;
        }
        return res;
    }
};
