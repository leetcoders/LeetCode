/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 6, 2013
 Update:     Jul 26, 2013
 Problem:    Path Sum
 Difficulty: easy
 Source:     http://www.leetcode.com/onlinejudge
 Notes:
 Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up 
 all the values along the path equals the given sum.

 For example:
 Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1
 return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
 
 Solution: Recursion.
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
    bool hasPathSum(TreeNode *root, int sum) {
        if (!root)
            return false;
        if (!root->left and !root->right)
            return sum == root->val;
        return hasPathSum(root->left, sum - root->val) || 
               hasPathSum(root->right, sum - root->val);
    }
};
