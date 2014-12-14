/*
 Author:     Annie Kim, anniekim.pku@gmail.com : King, wangjingui@outlook.com
 Date:       Jun 7, 2013
 Update:     Dec 14, 2014
 Problem:    Insert Interval
 Difficulty: Medium
 Source:     https://oj.leetcode.com/problems/insert-interval/
 Notes:
 Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
 You may assume that the intervals were initially sorted according to their start times.
 Example 1:
 Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].
 Example 2:
 Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].
 This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].

 Solution: For example 2:
           1. compare [1,2] with [4,9], then insert [1,2];
           2. merge [3,5] with [4,9], get newInterval = [3,9];
           3. merge [6,7] with [3,9], get newInterval = [3,9];
           4. merge [8,10] with [3,9], get newInterval = [3,10];
           5. compare [12,16] with [3,10], insert newInterval [3,10], then all the remaining intervals...
           Solution 1 : Time O(N).
           Solution 2 : Time O(Log(N)).
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
class Solution {
public:
    vector<Interval> insert_1(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> res;
        vector<Interval>::iterator it = intervals.begin();
        bool inserted = false;
        for (; it != intervals.end(); ++it)
        {
            if (inserted == true || it->end < newInterval.start) // non-overlaping
            {
                res.push_back(*it);
            }
            else if (newInterval.end < it->start)
            {
                res.push_back(newInterval);
                res.push_back(*it);
                inserted = true;
            }
            else
            {
                newInterval.start = min(it->start, newInterval.start);
                newInterval.end = max(it->end, newInterval.end);
            }
        }
        if (inserted == false)
            res.push_back(newInterval);
        return res;
    }
    vector<Interval> insert_2(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> res;
        int n = intervals.size();
        int left = 0, right = n-1;
        while(left<=right){
            int mid = (left+right)/2;
            if(intervals[mid].start>newInterval.start) right=mid-1;
            else left = mid+1;
        }
        int idxStart = right;
        left = 0; right = n-1;
        while(left<=right){
            int mid = (left+right)/2;
            if(intervals[mid].end>=newInterval.end) right = mid -1;
            else left = mid+1;
        }
        int idxEnd = left;
        
        if (idxStart>=0 && newInterval.start<=intervals[idxStart].end)
        {
            newInterval.start=intervals[idxStart--].start;
        }
        
        if (idxEnd<intervals.size() && newInterval.end>=intervals[idxEnd].start)
        {
            newInterval.end=intervals[idxEnd++].end;
        }
        for(int i=0;i<=idxStart;i++)
            res.push_back(intervals[i]);
        res.push_back(newInterval);
        for(int i=idxEnd;i<intervals.size();i++)
            res.push_back(intervals[i]);
        return res;
    }
};