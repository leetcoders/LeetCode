/*
 Author:     King, wangjingui@outlook.com
 Date:       Dec 15, 2014
 Problem:    Fraction to Recurring Decimal
 Difficulty: Easy
 Source:     https://oj.leetcode.com/problems/fraction-to-recurring-decimal/
 Notes:
 Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

 If the fractional part is repeating, enclose the repeating part in parentheses.

 For example,

 Given numerator = 1, denominator = 2, return "0.5".
 Given numerator = 2, denominator = 1, return "2".
 Given numerator = 2, denominator = 3, return "0.(6)".

 Solution: ...
 */
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return string("0");
        bool flag = (numerator < 0)^(denominator < 0);
        long long Numerator = abs((long long)numerator);
        long long Denominator = abs((long long)denominator);
        string res;
        if (flag == true) res.push_back('-');
        ostringstream out;
        out << (Numerator / Denominator);
        res.insert(res.size(),out.str());
        Numerator = Numerator % Denominator;
        if (Numerator == 0) return res;
        res.push_back('.');
        unordered_map<int, int> map;
        for (int i = res.size(); Numerator != 0; ++i) {
            if (map.find(Numerator) != map.end()) break;
            map[Numerator] = i;
            Numerator *= 10;
            res.push_back((Numerator / Denominator) + '0');
            Numerator %= Denominator;
        }
        if (Numerator == 0) return res;
        res.insert(map[Numerator],"(");
        res.push_back(')');
        return res;
    }
};