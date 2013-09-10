/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Jan 17, 2013
 Update:     Sep 10, 2013
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

 Solution: 1. Sort first. O(nlgn)
           2. Hash table. O(n)
 */

bool compare(pair<int, int> a, pair<int, int> b) {
    return a.first < b.first;
}

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        return twoSum_1(numbers, target);
    }
    
    vector<int> twoSum_1(vector<int> &numbers, int target) {
        vector<pair<int, int>> nums(numbers.size());
        for (int i = 0; i < numbers.size(); ++i)
            nums[i] = make_pair(numbers[i], i+1);
        sort(nums.begin(), nums.end(), compare);
        
        int l = 0, r = nums.size() - 1;
        while (l < r)
        {
            int sum = nums[l].first + nums[r].first;
            if (sum == target) break;
            else if (sum < target) l++;
            else r--;
        }

        vector<int> res;
        res.push_back(min(nums[l].second, nums[r].second));
        res.push_back(max(nums[l].second, nums[r].second));
        return res;
    }
    
    vector<int> twoSum_2(vector<int> &numbers, int target) {
        unordered_map<int, int> map;
        for (int i = 0; i < numbers.size(); ++i)
            map[numbers[i]] = i + 1;
        for (int i = 0; i < numbers.size(); ++i)
        {
            unordered_map<int, int>::iterator it = map.find(target - numbers[i]);
            if (it == map.end()) continue;
            vector<int> res;
            res.push_back(min(i+1, it->second));
            res.push_back(max(i+1, it->second));
            return res;
        }
    }
};
