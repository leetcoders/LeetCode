/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       May 12, 2013
 Problem:    Letter Combinations of a Phone Number
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_17
 Notes:
 Given a digit string, return all possible letter combinations that the number could represent.
 A mapping of digit to letters (just like on the telephone buttons) is given below.
 Input:Digit string "23"
 Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 Note:
 Although the above answer is in lexicographical order, your answer could be in any order you want.

 Solution: ...
 */

class Solution {
public:
    vector<string> res;
    vector<string> letterCombinations(string digits) {
        string mapping[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        res.clear();
        string s;
        letterCombinationsRe(digits, mapping, s, 0);
        return res;
    }

    void letterCombinationsRe(const string &digits, string mapping[], string &s, int deep)
    {
        if (deep == digits.size())
        {
            res.push_back(s);
            return;
        }
        for (int i = 0; i < mapping[digits[deep]-'2'].size(); ++i)
        {
            s.push_back(mapping[digits[deep]-'2'][i]);
            letterCombinationsRe(digits, mapping, s, deep + 1);
            s.resize(s.size() - 1);
        }
    }
};