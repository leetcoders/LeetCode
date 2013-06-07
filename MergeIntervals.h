/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Jun 7, 2013
 Problem:    Merge Intervals
 Difficulty: Medium
 Source:     http://leetcode.com/onlinejudge#question_56
 Notes:
 Given a collection of intervals, merge all overlapping intervals.
 For example,
 Given [1,3],[2,6],[8,10],[15,18],
 return [1,6],[8,10],[15,18].

 Solution: 1. Sort first.
           - sort according to increasing sequence of 'start' first;
           - for the intervals that have equal 'start', sort in decreasing order of 'end'.
           For example, sort [[0,4],[5,9],[6,9],[9,9],[5,5],[8,11],[9,13]],
           then we will get [[0,4],[5,9],[5,5],[6,9],[8,11],[9,13],[9,9]].
           2. Traverse the 'intervals'.
           - if 'it' interval is totally enclosed by 'last' interval, push 'last' to result, then move both forward.
           - else merge 'it' and 'last' (modify 'last'), then move 'it' forward only.
           At last, DO NOT forget push the last 'last' into result.
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
    if (a.start != b.start)
        return a.start < b.start;
    else
        return a.end > b.end;
}

class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        if (intervals.empty()) 
            return intervals;
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