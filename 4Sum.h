/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 20, 2013
 Problem:    4Sum
 Difficulty: Medium
 Source:     http://leetcode.com/onlinejudge#question_18
 Notes:
 Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? 
 Find all unique triplets in the array which gives the sum of zero.
 Note:
 Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? 
 Find all unique quadruplets in the array which gives the sum of target.
 Note:
 Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a <= b <= c <= d)
 The solution set must not contain duplicate quadruplets.
 For example, given array S = {1 0 -1 0 -2 2}, and target = 0.
 A solution set is:
 (-1,  0, 0, 1)
 (-2, -1, 1, 2)
 (-2,  0, 0, 2)

 Solution: FourSum = TwoSum + TwoSum.
 */

struct TwoSum
{
    int sum;
    int first;
    int second;
    TwoSum(int _first, int _second) {
        first = _first;
        second = _second;
        sum = _first + _second;
    }
};
bool increasing(TwoSum i, TwoSum j) { return (i.sum < j.sum); }

class Solution {
private:
    vector<vector<int>> res;
    map<int, int>       count;
    vector<int>         uni;
    vector<TwoSum>      sum;

public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        res.clear();
        if (num.size() < 4) return res;
        UniqueAndCount(num);
        buildTwoSum();
        searchResult(target);
        return res;
    }

private:
    void UniqueAndCount(const vector<int> &num)
    {
        count.clear();
        uni.clear();
        for (int i = 0; i < num.size(); ++i) {
            if (count[num[i]] == 0)
                uni.push_back(num[i]);
            count[num[i]]++;
        }
    }

    void buildTwoSum()
    {
        sum.clear();
        for (int i = 0; i < uni.size(); ++i)
            for (int j = i + 1; j < uni.size(); ++j)
                sum.push_back(TwoSum(uni[i], uni[j]));
        // for duplicate numbers
        for (map<int,int>::iterator it = count.begin(); it != count.end(); ++it)
            if ((*it).second > 1)
                sum.push_back(TwoSum((*it).first, (*it).first));
        sort(sum.begin(), sum.end(), increasing);
    }

    void searchResult(int target)
    {
        int i = 0; int j = sum.size() - 1;
        while (i < j)
        {
            int s = sum[i].sum + sum[j].sum;
            if (s == target) {
                int m = i, n = j;
                while (m < j && sum[m].sum == sum[i].sum) {
                    n = j;
                    while (m < n && sum[n].sum == sum[j].sum)
                        pushResult(sum[m], sum[n--]);
                    m++;
                }
                i = m;
                j = n;
            } else if (s < target) {
                i++;
            } else {
                j--;
            }
        }
        // for the numbers that have more than 4 copies
        for (map<int,int>::iterator it = count.begin(); it != count.end(); ++it)
            if ((*it).second >= 4 && (*it).first * 4 == target)
                pushResult(TwoSum((*it).first, (*it).first), TwoSum((*it).first, (*it).first));
    }

    void pushResult(const TwoSum &a, const TwoSum &b)
    {
        vector<int> quadruplet;
        quadruplet.push_back(a.first);
        quadruplet.push_back(a.second);
        quadruplet.push_back(b.first);
        quadruplet.push_back(b.second);
        // check counts
        map<int, int> used;
        for (int i = 0; i < quadruplet.size(); ++i)
            used[quadruplet[i]]++;
        for (map<int, int>::iterator it = used.begin(); it != used.end(); ++it)
            if ((*it).second > count[(*it).first])
                return;
        // avoid duplicates
        sort(quadruplet.begin(), quadruplet.end());
        if (find(res.begin(), res.end(), quadruplet) == res.end())
            res.push_back(quadruplet);
    }
};
