/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       May 1, 2013
 Update:     Jul 26, 2013
 Problem:    Restore IP Addresses
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_93
 Notes:
 Given a string containing only digits, restore it by returning all possible valid IP address combinations.
 For example:
 Given "25525511135",
 return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)

 Solution: DFS.
 */

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        string ip;
        restoreIpAddressRe(s, res, ip, 0, 0);
        return res;
    }
    
    void restoreIpAddressRe(string &s, vector<string> &res, string &ip, int deep, int start)
    {
        if (deep == 4 || start == s.size())
        {
            if (start == s.size() && deep == 4)
                res.push_back(ip);
            return;
        }
        int num = 0;
        for (int i = start; i <= start + 2 && i < s.size(); ++i)
        {
            num = num * 10 + s[i] - '0';
            if (num >= 0 && num <= 255)
            {
                int orig = ip.size();
                if (orig != 0) ip.push_back('.');
                ip += s.substr(start, i - start + 1);
                restoreIpAddressRe(s, res, ip, deep + 1, i + 1);
                ip.resize(orig);
                if (num == 0) break;
            }
        }
    }
};
