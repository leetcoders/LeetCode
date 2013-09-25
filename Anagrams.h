/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 17, 2013
 Update:     Sep 25, 2013
 Problem:    Anagrams
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_49
 Notes:
 Given an array of strings, return all groups of strings that are anagrams.
 Note: All inputs will be in lower-case.

 Solution: Sort the string to see if they're anagrams.
           Solution 1 is simpler than 2.
 */

class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        return anagrams_1(strs);
    }
    
    // solution 1
    vector<string> anagrams_1(vector<string> &strs) {
        typedef map<string, vector<int> > MAP;
        MAP map;
        for (int i = 0; i < strs.size(); ++i) 
        {
            string s = strs[i];
            sort(s.begin(), s.end());
            map[s].push_back(i);
        }
        vector<string> res;
        MAP::iterator it = map.begin();
        for (; it != map.end(); it++) 
        {
            vector<int> &anagrams = it->second;
            if (anagrams.size() > 1) {
                for (int i = 0; i < anagrams.size(); ++i)
                    res.push_back(strs[anagrams[i]]);
            }
        }
        return res;
    }
    
    // solution 2
    vector<string> anagrams_2(vector<string> &strs) {
        typedef unordered_map<string, int > MAP;
        vector<string> res;
        MAP anagram;
        for (int i = 0; i < strs.size(); ++i)
        {
            string s = strs[i];
            sort(s.begin(), s.end());
            MAP::iterator it = anagram.find(s);
            if (it == anagram.end()) 
            {
                anagram[s] = i;
            } 
            else 
            {
                if (it->second >= 0) {
                    res.push_back(strs[it->second]);
                    it->second = -1;
                }
                res.push_back(strs[i]);
            }
        }
        return res;
    }
};