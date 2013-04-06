/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Jan 17, 2013
 Problem:    Two Sum
 Difficulty: easy
 Source:     http://www.leetcode.com/onlinejudge
 Notes:
 Given an array of integers, find two numbers such that they add up to a specific target number.

 The function twoSum should return indices of the two numbers such that they add up to the target, 
 where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

 You may assume that each input would have exactly one solution.

 Input: numbers={2, 7, 11, 15}, target=9
 Output: index1=1, index2=2

 Solution:
 1. traverse the vector (n^2)
 2. sort first (sort nlogn)
 */
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b)
{
	return a.second < b.second;
}

class Solution {
public:
	vector<int> twoSum_1(vector<int> &numbers, int target) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function

		vector<int> results;
		for (int i=0; i<numbers.size(); i++)
		{
			if (numbers[i] > target)
				continue;

			for (int j=i+1; j<numbers.size(); j++)
			{
				if (numbers[i] + numbers[j] == target)
				{
					results.push_back(i < j ? i+1 : j+1);
					results.push_back(i < j ? j+1 : i+1);
				}
			}
		}

		return results;
	}

	vector<int> twoSum(vector<int> &numbers, int target) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		
		vector< pair<int, int> > nums;
		for (int i=0; i<numbers.size(); i++)
			nums.push_back(pair<int, int>(i, numbers[i]));
		
		sort(nums.begin(), nums.end(), compare);

		int front = 0;
		int back = nums.size() - 1;

		while (front < back)
		{
			while (nums[back].second >= target || nums[front].second + nums[back].second > target)
				back--;
			
			while (nums[front].second + nums[back].second < target)
				front++;
			
			if (nums[front].second + nums[back].second == target)
				break;
		}

		vector<int> results;
		results.push_back(nums[front].first < nums[back].first ? nums[front].first+1 : nums[back].first+1);
		results.push_back(nums[front].first < nums[back].first? nums[back].first+1 : nums[front].first+1);
		
		return results;
	}
};