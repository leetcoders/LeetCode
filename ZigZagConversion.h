/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 7, 2013
 Update:     Dec 14, 2014
 Problem:    ZigZag Conversion
 Difficulty: Easy
 Source:     https://oj.leetcode.com/problems/zigzag-conversion/
 Notes:
 The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

 P   A   H   N
 A P L S I I G
 Y   I   R
 And then read line by line: "PAHNAPLSIIGYIR"
 Write the code that will take a string and make this conversion given a number of rows:

 string convert(string text, int nRows);
 convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".

 Solution: ...
 */

class Solution {
public:
    string convert(string s, int nRows) {
        if(nRows <= 1) return s;
        int n = s.size();
        string res;
        for(int i = 0;i < nRows; ++i){
            for (int j = 0; j  + i < n; j += 2*nRows - 2) {
                res.push_back(s[j+i]);
                if (i == 0 || i == nRows - 1) continue;
                if (j + 2*nRows - 2 - i < n)
                    res.push_back(s[j + 2*nRows - 2 - i]);
            }
        }
        return res;
    }
};