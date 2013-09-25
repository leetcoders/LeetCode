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

 Solution: 1. Sort in ascending order of 'start'.
           2. Traverse the 'intervals', merge or push...
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
        int N = intervals.size();
        if (N <= 1) return intervals;
        sort(intervals.begin(), intervals.end(), mycompare);
        vector<Interval> res;
        Interval last = intervals[0];
        for (int i = 1; i < N; ++i) 
        {
            if (intervals[i].start > last.end) {
                res.push_back(last);
                last = intervals[i];
            } else {
                last.end = max(last.end, intervals[i].end);
            }
        }
        res.push_back(last);
        return res;
    }
};