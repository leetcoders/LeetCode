/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       May 26, 2013
 Update:     Aug 10, 2013
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
        int M = S.size(), N = L.size();
        int K = L[0].size();
        unordered_map<string, int> need;
        unordered_map<string, int> found;
        for (int i = 0; i < N; ++i)
            need[L[i]]++;
        for (int i = 0; i <= M - N * K; ++i)
        {
            found.clear();
            int j;
            for (j = 0; j < N; ++j)
            {
                string s = S.substr(i + j * K, K);
                auto it = need.find(s);
                if (it == need.end())
                    break;
                if (it->second <= found[s])
                    break;
                found[s]++;
            }
            if (j == N) res.push_back(i);
        }
        return res;
    }
};
