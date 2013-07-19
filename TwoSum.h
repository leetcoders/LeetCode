/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Jan 17, 2013
 Update:     Jul 19, 2013
 Problem:    Two Sum
 Difficulty: easy
 Source:     http://leetcode.com/onlinejudge#question_1
 Notes:
 Given an array of integers, find two numbers such that they add up to a specific target number.

 The function twoSum should return indices of the two numbers such that they add up to the target, 
 where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

 You may assume that each input would have exactly one solution.

 Input: numbers={2, 7, 11, 15}, target=9
 Output: index1=1, index2=2

 Solution: Sort first O(nlogn)
 */

bool compare(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<pair<int, int>> nums;
        for (int i=0; i<numbers.size(); i++)
            if (numbers[i] < target)
                nums.push_back(pair<int, int>(i + 1, numbers[i]));
        sort(nums.begin(), nums.end(), compare);
    
        int l = 0, r = nums.size() - 1;
        while (l < r)
        {
            int sum = nums[l].second + nums[r].second;
            if (sum == target) break;
            else if (sum < target) l++;
            else r--;
        }

        vector<int> res;
        res.push_back(min(nums[l].first, nums[r].first));
        res.push_back(max(nums[l].first, nums[r].first));
    
        return res;
    }
};
