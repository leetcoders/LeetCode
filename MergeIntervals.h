/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Jun 7, 2013
 Update:     Jul 15, 2013
 Problem:    Merge Intervals
 Difficulty: Medium
 Source:     http://leetcode.com/onlinejudge#question_56
 Notes:
 Given a collection of intervals, merge all overlapping intervals.
 For example,
 Given [1,3],[2,6],[8,10],[15,18],
 return [1,6],[8,10],[15,18].

 Solution: 1. Sort first.
              - sort according to increasing sequence of 'start'.
           2. Traverse the 'intervals'.
              - if 'it' interval intersects with 'last' interval, merge them (modify 'last').
              - else push 'last' into final result.
              - At last, DO NOT forget push the last 'last' into result.
*/

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool compare(Interval a, Interval b)
{
    return a.start < b.start;
}

class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        if (intervals.empty()) return intervals;
        sort(intervals.begin(), intervals.end(), compare);
        vector<Interval> res;
        vector<Interval>::iterator last = intervals.begin(), it = last + 1;
        while (it != intervals.end())
        {
            if (last->end < it->start)
            {
                res.push_back((*last));
                last = it;
            }
            else
            {
                last->end = max(last->end, it->end);
            }
            it++;
        }
        res.push_back((*last));
        return res;
    }
};
