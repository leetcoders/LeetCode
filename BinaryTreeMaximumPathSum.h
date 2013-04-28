/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 28, 2013
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
    int res;
    int maxPathSum(TreeNode *root) {
        res = INT_MIN;
        if (!root) return 0;
        maxPathSumRe(root);
        return res;
    }

    int maxPathSumRe(TreeNode *node)
    {
        if (!node) return 0;
        int l = maxPathSumRe(node->left);
        int r = maxPathSumRe(node->right);
        res = max(res, node->val);
        res = max(res, l + r + node->val);
        res = max(res, max(l, r) + node->val);
        return max(node->val, max(l, r) + node->val);
    }
};
