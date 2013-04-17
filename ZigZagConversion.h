/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 7, 2013
 Problem:    ZigZag Conversion
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_6
 Notes:
 The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

 P   A   H   N
 A P L S I I G
 Y   I   R
 And then read line by line: "PAHNAPLSIIGYIR"
 Write the code that will take a string and make this conversion given a number of rows:

 string convert(string text, int nRows);
 convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".

 Solution: It's done if you find the rule!
 */

class Solution {
public:
    string convert(string s, int nRows) {
        if (nRows == 1) return s; 
        string res;
        int offset = 2 * (nRows - 1);
        for (int i = 0; i < nRows; i++)
        {
            if (i == 0 || i == nRows-1) {
                for (int j = i; j < s.size(); j += offset)
                    res.push_back(s[j]);
            } else {
                int j_1 = i;
                int j_2 = j_1 + offset - i * 2;
                bool use_1 = true;
                while (use_1 ? j_1 < s.size() : j_2 < s.size())
                {
                    res.push_back(use_1 ? s[j_1] : s[j_2]);
                    j_1 = use_1? j_1 + offset : j_1;
                    j_2 = use_1? j_2 : j_2 + offset;
                    use_1 = !use_1;
                }
            }
        } 
        return res;
    }
};
