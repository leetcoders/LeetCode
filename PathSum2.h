/*
 Author:     Annie Kim, anniekim.pku@gmail.com : King, higuige@gmail.com
 Date:       Apr 6, 2013
 Update:     Oct 7, 2014
 Problem:    Path Sum 2
 Difficulty: easy
 Source:     http://leetcode.com/onlinejudge#question_113
 Notes:
 Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

 For example:
 Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
 return
 [
   [5,4,11,2],
   [5,8,4,5]
 ]
 
 Solution: DFS. 
 */

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int>> res;
        vector<int> path;
        pathSumRe(root, sum, res, path);
        return res;
    }
    void pathSumRe(TreeNode *root, int sum, vector<vector<int>> &res, vector<int> &path)
    {
        if (!root) return;
        path.push_back(root->val);
        if (!root->left && !root->right && root->val == sum)
        {
            res.push_back(path);
        }
        pathSumRe(root->left, sum - root->val, res, path);
        pathSumRe(root->right, sum - root->val, res, path);
        path.pop_back();
    }
};
