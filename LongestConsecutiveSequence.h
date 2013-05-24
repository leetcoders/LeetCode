/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       May 24, 2013
 Problem:    Longest Consecutive Sequence
 Difficulty: Medium
 Source:     http://leetcode.com/onlinejudge#question_128
 Notes:
 Given an unsorted array of integers, find the length of the longest consecutive 
 elements sequence.
 For example,
 Given [100, 4, 200, 1, 3, 2],
 The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.
 Your algorithm should run in O(n) complexity.

 Solution: Store lower-bound and upper-bound for each element in 'num'. O(n) ?
           Another solution can be found at https://github.com/anson627/leetcode/blob/master/LongestConsecutiveSequence/LongestConsecutiveSequence.cpp,
           where it only stores length for each element and it has O(n) time complexity actually.
*/

class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        int N = num.size();
        unordered_map<int, pair<int, int>> itvl;
        int res = 1;
        for (int i = 0; i < N; ++i)
        {
            int number = num[i];

            if (itvl.find(number) == itvl.end())
                itvl[number] = make_pair(number, number);
            else
                continue;

            int j = number + 1;
            int low = number, high = number;
            while (itvl.find(j) != itvl.end())
            {
                high = itvl[j].second;
                itvl[number].second = high;
                itvl[j].first = itvl[number].first;
                j = high + 1;
            }
            j = number - 1;
            while (itvl.find(j) != itvl.end())
            {
                low = itvl[j].first;
                itvl[number].first = low;
                itvl[j].second = itvl[number].second;
                j = low - 1;
            }
            res = max(res, high - low + 1);
        }
        return res;
    }
};