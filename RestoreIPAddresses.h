/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       May 1, 2013
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
    vector<string> res;
    vector<string> restoreIpAddresses(string s) {
        res.clear();
        string ip;
        restoreIpAddressesRe(s, ip, 0, s.size() - 1, 0);
        return res;
    }

    void restoreIpAddressesRe(const string &s, string &ip, int start, int end, int deep)
    {
        if (deep == 4) {
            if (end - start + 1 == 0)
                res.push_back(ip);
            return;
        }
        if (end - start + 1 > (4 - deep) * 3)
            return;
        if (end - start + 1 == (4 - deep) * 3) {
            int i;
            for (i = deep; i < 4; ++i, start += 3)
            {
                string r(s.begin() + start, s.begin() + start + 3);
                if (!pushIpAddress(ip, r, i))
                    break;
            }
            if (i == 4)
                res.push_back(ip);
            return;
        }
        for (int i = 0; i <= min(end - start, 2); ++i)
        {
            string r(s.begin() + start, s.begin() + start + i + 1);
            int before = ip.size();
            if (!pushIpAddress(ip, r, deep))
                continue;
            restoreIpAddressesRe(s, ip, start + i + 1, end, deep + 1);
            ip.resize(before);
        }

    }

    bool checkIpAddress(const string &num)
    {
        if (num.size() > 1 && num[0] == '0')
            return false;
        stringstream stream;
        stream<<num;
        int iip;
        stream>>iip;
        return iip >= 0 && iip <= 255;
    }

    bool pushIpAddress(string &ip, string num, int deep)
    {
        if (!checkIpAddress(num))
            return false;
        ip += num;
        if (deep != 3)
            ip.push_back('.');
        return true;
    }
};
