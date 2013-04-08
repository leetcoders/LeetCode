/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 8, 2013
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

 Solution: Count the number of equal characters one by one.
*/

class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return string("1");
        string old("11");
        string res;
        
        for (int i = 3; i <= n; i++)
        {
            int count = 1;
            char c = old[0];
            for (int j = 1; j < old.size(); j++)
            {
                if (c == old[j])
                {
                    count++;
                }
                else
                {
                    pushString(res, count, c);
                    c = old[j];
                    count = 1;
                }
            }
            
            pushString(res, count, c);
            old = res;
            res.clear();
        }
        
        return old;
    }
    
    void pushString(string &s, int count, char c)
    {
        char x[2];
        sprintf(x, "%d\0", count);
        s += string(x);
        s.push_back(c);
    }
};