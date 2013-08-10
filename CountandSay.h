/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 8, 2013
 Update:     Aug 10, 2013
 Problem:    Count and Say
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_38
 Notes:
 The count-and-say sequence is the sequence of integers beginning as follows:
 1, 11, 21, 1211, 111221, ...

 1 is read off as "one 1" or 11.
 11 is read off as "two 1s" or 21.
 21 is read off as "one 2, then one 1" or 1211.
 Given an integer n, generate the nth sequence.
 Note: The sequence of integers will be represented as a string.

 Solution: ...
*/

class Solution {
public:
    string countAndSay(int n) {
        string res = "1";
        for (int i = 2; i <= n; ++i)
        {
            stringstream ss;
            int k = 0;
            for (int j = 1; j < res.size(); ++j)
            {
                if (res[j] != res[k])
                {
                    ss << (j - k) << res[k];
                    k = j;
                }
            }
            ss << (res.size() - k) << res[k];
            ss >> res;
        }
        return res;
    }
};
