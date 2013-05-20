/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       May 20, 2013
 Problem:    Palindrome Partitioning
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_131
 Notes:
 Given a string s, partition s such that every substring of the partition is a palindrome.
 Return all possible palindrome partitioning of s.
 For example, given s = "aab",
 Return
 [
  ["aa","b"],
  ["a","a","b"]
 ]

 Solution: ...
 */

class Solution {
public:
    vector<vector<string>> res;
    vector<vector<string>> partition(string s) {
        res.clear();
        vector<string> v;
        partitionRe(s, 0, v);
        return res;
    }

    void partitionRe(const string &s, int start, vector<string> &v)
    {
        if (start == s.size())
        {
            res.push_back(v);
            return;
        }
        string palindrom;
        for (int i = start; i < s.size(); ++i)
        {
            palindrom.push_back(s[i]);
            if (isPalindrome(palindrom))
            {
                v.push_back(palindrom);
                partitionRe(s, i + 1, v);
                v.pop_back();
            }
        }
    }

    bool isPalindrome(const string &s)
    {
        int N = s.size();
        for (int i = 0; i < N / 2; ++i)
            if (s[i] != s[N-i-1])
                return false;
        return true;
    }
};