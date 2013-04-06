/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 6, 2013
 Problem:    Minimum Depth of Binary Tree
 Difficulty: easy
 Source:     http://leetcode.com/onlinejudge#question_111
 Notes:
 Given a binary tree, find its minimum depth.
 The minimum depth is the number of nodes along the shortest path from the root node 
 down to the nearest leaf node.
 
 Solution: Recursion. Pay attention to cases when the non-leaf node has only one child.
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
    int minDepth(TreeNode *root) {
        if (!root)
            return 0;
        
        if (!root->left && !root->right)
            return 1;
        
        if (!root->left)
            return 1 + minDepth(root->right);
        else if (!root->right)
            return 1 + minDepth(root->left);
        else
            return 1 + min(minDepth(root->left), minDepth(root->right));
    }
};