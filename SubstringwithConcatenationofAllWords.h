/*
 Author:     Annie Kim, anniekim.pku@gmail.com : Andy, nkuwjg@gmail.com
 Date:       May 26, 2013
 Update:     Jan 15, 2015
 Problem:    Substring with Concatenation of All Words
 Difficulty: Easy
 Source:     https://oj.leetcode.com/problems/substring-with-concatenation-of-all-words/
 Notes:
 You are given a string, S, and a list of words, L, that are all of the same length. Find all 
 starting indices of substring(s) in S that is a concatenation of each word in L exactly once 
 and without any intervening characters.
 For example, given:
 S: "barfoothefoobarman"
 L: ["foo", "bar"]
 You should return the indices: [0,9].
 (order does not matter).

 Solution: 1. Brute + HashMap.
           2. Sliding Window + HashMap.
*/
class Solution {
public:
    vector<int> findSubstring_1(string S, vector<string> &L) {
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
    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int> res;
        if (S.empty() || L.empty()) return res;
        unordered_map<string, int> need;
        for (int i = 0; i < L.size(); ++i)
            need[L[i]]++;
        int n = L[0].length(), m = L.size();
        for (int i = 0; i < n; ++i) {
            unordered_map<string, int> find;
            for (int start = i, end = i, count = 0; end + n <= S.length(); end += n) {
                string str = S.substr(end, n);
                auto it = need.find(str);
                if (it == need.end()) {
                    start = end + n;
                    find.clear();
                    count = 0;
                    continue;
                }
                while (find.find(str) != find.end() && find[str] >= need[str]) {
                    string subStart = S.substr(start, n);
                    find[subStart]--;
                    start += n;
                    --count;
                }
                find[str]++;
                ++count;
                if (count != m) continue;
                res.push_back(start);
            }
        }
        return res;
    }
};
