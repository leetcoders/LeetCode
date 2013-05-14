/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       May 14, 2013
 Problem:    Triangle
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_120
 Notes:
 Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.
 For example, given the following triangle
 [
    [2],
   [3,4],
  [6,5,7],
 [4,1,8,3]
 ]
 The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
 Note:
 Bonus point if you are able to do this using only O(n) extra space, where n is the total number 
 of rows in the triangle.

 Solution: 1. DFS. (Time Limit Exceeded for large test data).
           2. DP. Do not need additional spaces (happen in-place).
 */

class Solution {
public:
    int minimumTotal(vector<vector<int>> &triangle) {
        return minimumTotal_2(triangle);
    }

    int minimumTotal_1(vector<vector<int>> &triangle) {
        int res = INT_MAX;
        minimumTotal_1_Re(triangle, 0, res, 0, 0);
        return res;
    }

    void minimumTotal_1_Re(vector<vector<int>> &triangle, int partSum, int &res, int deep, int j)
    {
        if (deep == triangle.size()) {
            res = min(res, partSum);
            return;
        }
        for (int i = j; i < triangle[deep].size() && i <= j + 1; ++i)
            minimumTotal_1_Re(triangle, partSum + triangle[deep][i], res, deep + 1, i);
    }

    int minimumTotal_2(vector<vector<int>> &triangle) {
        for (int i = triangle.size() - 2; i >= 0; --i)
            for (int j = 0; j < triangle[i].size(); ++j)
                triangle[i][j] = triangle[i][j] + min(triangle[i+1][j], triangle[i+1][j+1]);
        return triangle[0][0];
    }
};