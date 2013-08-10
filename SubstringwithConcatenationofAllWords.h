/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       May 26, 2013
 Problem:    Substring with Concatenation of All Words
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_30
 Notes:
 You are given a string, S, and a list of words, L, that are all of the same length. Find all 
 starting indices of substring(s) in S that is a concatenation of each word in L exactly once 
 and without any intervening characters.
 For example, given:
 S: "barfoothefoobarman"
 L: ["foo", "bar"]
 You should return the indices: [0,9].
 (order does not matter).

 Solution: ...
*/

class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int> res;
        if (S.empty() || L.empty()) return res;
        int N = S.size(), M = L.size(), Len = L[0].size();
        map<string, int> need;
        map<string, int> found;
        for (int i = 0; i < M; ++i)
            need[L[i]]++;
        for (int i = 0; i <= N - M * Len; ++i)
        {
            found.clear();
            int j = 0;
            for (j = 0; j < M; ++j)
            {
                string w = S.substr(i + j * Len, Len);
                if (need.find(w) == need.end())
                    break;
                if (found[w] >= need[w])
                    break;
                found[w]++;
            }
            if (j == M)    
                res.push_back(i);
        }
        return res;
    }
};
