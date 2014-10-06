/*
 Author:     Annie Kim, anniekim.pku@gmail.com : King, higuige@gmail.com
 Date:       Apr 28, 2013
 Update:     Oct 07, 2014
 Problem:    Binary Tree Maximum Path Sum
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_124
 Notes:
 Given a binary tree, find the maximum path sum.
 The path may start and end at any node in the tree.
 For example:
 Given the below binary tree,
   1
  / \
 2   3
 Return 6.

 Solution: Recursion...
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
    int maxPathSum(TreeNode *root) {
        int res = INT_MIN;
        maxPathSumRe(root, res);
        return res;
    }

    int maxPathSumRe(TreeNode *node, int &res)
    {
        if (!node) return 0;
        int l = maxPathSumRe(node->left, res);
        int r = maxPathSumRe(node->right, res);
        int sum = max(node->val, max(l, r) + node->val);
        res = max(res, max(0, l) + max(0, r) + node->val);
        return sum;
    }
};
