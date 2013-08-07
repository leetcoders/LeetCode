/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       May 24, 2013
 Update:     Aug 8, 2013
 Problem:    Longest Consecutive Sequence
 Difficulty: Hard
 Source:     http://leetcode.com/onlinejudge#question_128
 Notes:
 Given an unsorted array of integers, find the length of the longest consecutive 
 elements sequence.
 For example,
 Given [100, 4, 200, 1, 3, 2],
 The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.
 Your algorithm should run in O(n) complexity.

 Solution: Update solution. This solution is from Peking2 (http://blog.sina.com.cn/s/blog_b9285de20101iqar.html).
           This solution is much easier to understand.
*/

class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        set<int> s;
        for (int i = 0; i < num.size(); ++i)
            s.insert(num[i]);
        int res = 0;
        for (int i = 0; i < num.size() && !s.empty(); ++i)
        {
            if (s.find(num[i]) != s.end())
            {
                int low = getCount(s, num[i], false);
                int high = getCount(s, num[i] + 1, true);
                res = max(res, low + high);
            }
        }
        return res;
    }

    int getCount(set<int> &s, int val, bool ascending)
    {
        int count = 0;
        while (s.find(val) != s.end())
        {
            s.erase(val);
            count++;
            val = ascending ? val + 1 : val - 1;
        }
        return count;
    }
};
