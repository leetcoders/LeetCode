/*
 Author:     King, nkuwjg@gmail.com
 Date:       Jan 13, 2015
 Problem:    ZigZag Conversion
 Difficulty: Medium
 Source:     https://oj.leetcode.com/problems/largest-number/
 Notes:
 Given a list of non negative integers, arrange them such that they form the largest number.

 For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.

 Note: The result may be very large, so you need to return a string instead of an integer.

 Solution: ...
 */
class Solution {
public:
    static string itos(int i) { // convert int to string
        stringstream s;
        s << i;
        return s.str();
    }
    static bool cmp(const int & a, const int &b) {
        string s1 = itos(a), s2 = itos(b);
        return s1+s2>s2+s1;
    }
    string largestNumber(vector<int> &num) {
        sort(num.begin(),num.end(), cmp);
        stringstream res;
        int i = 0;
        while ((i < num.size() -1) && num[i] == 0) i++;
        while (i < num.size()) res << num[i++];
        return res.str();
    }
};