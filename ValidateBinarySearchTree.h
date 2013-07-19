/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 10, 2013
 Update:     Jul 19, 2013
 Problem:    Validate Binary Search Tree
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_98
 Notes:
 Given a binary tree, determine if it is a valid binary search tree (BST).
 Assume a BST is defined as follows:
 The left subtree of a node contains only nodes with keys less than the node's key.
 The right subtree of a node contains only nodes with keys greater than the node's key.
 Both the left and right subtrees must also be binary search trees.

 Solution: Recursion. Add to parameters(lower & upper bound). O(n)
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
    bool isValidBST(TreeNode *root) {
        return isValidBST(root, INT_MIN, INT_MAX);
    }
    
    bool isValidBST(TreeNode *node, int lower, int upper){
        if (!node) return true;
        if (node->val <= lower || node->val >= upper) return false;
        
        return isValidBST(node->left, lower, min(node->val, upper)) && 
               isValidBST(node->right, max(lower, node->val), upper);
    }
};
