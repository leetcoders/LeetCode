/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       May 24, 2013
 Update:     Jun 18, 2014
 Problem:    Longest Consecutive Sequence
 Difficulty: Hard
 Source:     https://oj.leetcode.com/problems/longest-consecutive-sequence/
 Notes:
 Given an unsorted array of integers, find the length of the longest consecutive 
 elements sequence.
 For example,
 Given [100, 4, 200, 1, 3, 2],
 The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.
 Your algorithm should run in O(n) complexity.

 Solution 1: Update solution. This solution is from Peking2 (http://blog.sina.com.cn/s/blog_b9285de20101iqar.html).
             This solution is much easier to understand.
 Solution 2: by Yao Liu.
*/

class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        return longestConsecutive1(num);
    }
    
    int longestConsecutive1(vector<int> &num) {
        unordered_set<int> s;
        int res = 0;
        for (int i = 0; i < num.size(); ++i)
            s.insert(num[i]);
        for (int i = 0; i < num.size() && !s.empty(); ++i)
        {
            if (s.find(num[i]) == s.end())
                continue;
            int upper = num[i], lower = num[i];
            while (s.find(upper+1) != s.end())
                s.erase(++upper);
            while (s.find(lower-1) != s.end())
                s.erase(--lower);
            if (upper != lower)
                s.erase(num[i]);
            res = max(res, upper - lower + 1);
        }
        return res;
    }
    
    int longestConsecutive2(vector<int> &num) {
        int longest = 0;
        unordered_map<int, int> table;
        for(int i = 0, count = num.size(); i < count; ++i) 
            if(table.find(num[i]) == table.end()) {
                int val = num[i], update;
                if(table.find(val - 1) != table.end() && table.find(val + 1) != table.end())
                    // assigning to table[val] here is only for adding val as a key of the hashtable.
                    update = table[val] = 
                             table[val - table[val - 1]] = 
                             table[val + table[val + 1]] = 
                             table[val - 1] + table[val + 1] + 1; 
                else if(table.find(val - 1) != table.end())
                    update = table[val] = ++table[val - table[val - 1]];
                else if(table.find(val + 1) != table.end())
                    update = table[val] = ++table[val + table[val + 1]];
                else 
                    update = table[val] = 1;
                longest = max(longest, update);
            }
        return longest;
    }
};
