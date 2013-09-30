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
        vector<string> part;
        partitionRe(s, 0, part);
        return res;
    }

    void partitionRe(const string &s, int start, vector<string> &part) {
        if (start == s.size())
        {
            res.push_back(part);
            return;
        }
        string palindrom;
        for (int i = start; i < s.size(); ++i) {
            palindrom.push_back(s[i]);
            if (!isPalindrome(palindrom)) continue;
            part.push_back(palindrom);
            partitionRe(s, i + 1, part);
            part.pop_back();
        }
    }

    bool isPalindrome(const string &s) {
        int i = 0, j = s.size()-1;
        while (i < j) {
            if (s[i] != s[j]) return false;
            i++; j--;
        }
        return true;
    }
};