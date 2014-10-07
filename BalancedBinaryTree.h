/*
 Author:     Annie Kim, anniekim.pku@gmail.com : King, higuige@gmail.com
 Date:       Apr 10, 2013
 Update:     Oct 07, 2014
 Problem:    Balanced Binary Tree
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_110
 Notes:
 Given a binary tree, determine if it is height-balanced.
 For this problem, a height-balanced binary tree is defined as a binary tree in which 
 the depth of the two subtrees of every node never differ by more than 1.

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
    bool isBalanced(TreeNode *root) {
        return solve(root) != -1;
    }
    int solve(TreeNode *root) {
        if (root == NULL) return 0;
        int left = solve(root->left);
        int right = solve(root->right);
        if (left == -1 || right == -1 || abs(left - right) > 1) return -1;
        return max(left,right) + 1;
    }
};
