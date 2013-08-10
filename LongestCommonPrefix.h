/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 16, 2013
 Update:     Aug 10, 2013
 Problem:    Longest Common Prefix
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_14
 Notes:
 Write a function to find the longest common prefix string amongst an array of strings.

 Solution: ...
 */

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        string res;
        if (strs.empty()) return res;
        for (int i = 0; i < strs[0].size(); ++i)
        {
            char ch = strs[0][i];
            for (int j = 1; j < strs.size(); ++j)
                if (i == strs[j].size() || strs[j][i] != ch)
                    return res;
            res.push_back(ch);
        }
        return res;
    }
};
