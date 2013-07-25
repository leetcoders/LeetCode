/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 17, 2013
 Update:     Jul 25, 2013
 Problem:    Anagrams
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_49
 Notes:
 Given an array of strings, return all groups of strings that are anagrams.
 Note: All inputs will be in lower-case.

 Solution: 1. Sort the string to see if they're the same (anagrams).
           2. Use map<string, int> to record the sorted string and the index of original string. 
              If first corresponding anagram appears, push the original string (strs[index]) into result vector and set the index = -1.
 */

class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        vector<string> res;
        map<string, int> anagram;
        for (int i = 0; i < strs.size(); ++i)
        {
            string s = strs[i];
            sort(s.begin(), s.end());
            if (anagram.find(s) == anagram.end()) 
            {
                anagram[s] = i;
            } 
            else 
            {
                if (anagram[s] >= 0) {
                    res.push_back(strs[anagram[s]]);
                    anagram[s] = -1;
                }
                res.push_back(strs[i]);
            }
        }
        return res;
    }
};
