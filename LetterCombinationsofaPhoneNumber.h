/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       May 12, 2013
 Update:     Dec 02, 2014
 Problem:    Letter Combinations of a Phone Number
 Difficulty: Medium
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
    vector<string> letterCombinations(string digits) {
        vector<string> keyboard {" ","","abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> res;
        string s;
        letterCombinationsRe(keyboard,digits,s,res);
        return res;
    }
    void letterCombinationsRe(vector<string> &keyboard, string &digits, string &s, vector<string>&res){
        if(s.size() == digits.size()){
            res.push_back(s);
            return;
        }
        string &letters = keyboard[digits[s.size()]-'0'];
        for(size_t i = 0; i < letters.size(); ++i){
            s.push_back(letters[i]);
            letterCombinationsRe(keyboard, digits,s,res);
            s.pop_back();
        }
    }
};