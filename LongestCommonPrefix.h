/*
 Author:     Annie Kim, anniekim.pku@gmail.com : King, wangjingui@outlook.com
 Date:       Apr 16, 2013
 Update:     Dec 20, 2014
 Problem:    Longest Common Prefix
 Difficulty: Easy
 Source:     https://oj.leetcode.com/problems/longest-common-prefix/
 Notes:
 Write a function to find the longest common prefix string amongst an array of strings.

 Solution: ...
 */
class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if(strs.empty()) return "";
        for(int i = 0;i < strs[0].size(); ++i){
            for(int j = 1;j < strs.size(); ++j){
                if(strs[j][i] != strs[0][i]) return strs[0].substr(0,i);
            }
        }
        return strs[0];
    }
};
