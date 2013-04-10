/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 10, 2013
 Problem:    Balanced Binary Tree
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_110
 Notes:
 Given a binary tree, determine if it is height-balanced.
 For this problem, a height-balanced binary tree is defined as a binary tree in which 
 the depth of the two subtrees of every node never differ by more than 1.

 Solution: Check height.
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
    bool isBalanced(TreeNode *root) {
        int height;
        return isBalancedRe(root, height);
    }
    
    bool isBalancedRe(TreeNode *root, int &height){
        if (!root){
            height = 0; 
            return true;
        }
        
        int leftHeight, rightHeight;
        if (!isBalancedRe(root->left, leftHeight)) return false;
        if (!isBalancedRe(root->right, rightHeight)) return false;
        
        height = 1 + max(leftHeight, rightHeight);
        return abs(leftHeight-rightHeight) <= 1;
    }
};