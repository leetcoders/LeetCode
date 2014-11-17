/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 6, 2013
 Update:     Nov 17, 2014 : by King, wangjingui@outlook.com
 Problem:    Minimum Depth of Binary Tree
 Difficulty: easy
 Source:     http://leetcode.com/onlinejudge#question_111
 Notes:
 Given a binary tree, find its minimum depth.
 The minimum depth is the number of nodes along the shortest path from the root node 
 down to the nearest leaf node.
 
 Solution: 1. Recursion. Pay attention to cases when the non-leaf node has only one child.
           2. Iteration + Queue. Contributed by SUN Mian(孙冕).
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
        return minDepth_1(root);
    }
    
    int minDepth_1(TreeNode *root) {
        if (!root)
            return 0;
        
        if (!root->left)
            return 1 + minDepth_1(root->right);
        if (!root->right)
            return 1 + minDepth_1(root->left);
        return 1 + min(minDepth_1(root->left), minDepth_1(root->right));
    }
    
    int minDepth_2(TreeNode *root) {
        if (!root) return 0;
        queue<TreeNode *> q;
        q.push(root);
        TreeNode * rightmost = root;
        int depth = 1;
        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();
            if (!node->left && !node->right) return depth;
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
            if (node == rightmost) {
                ++depth;
                rightmost = node->right?node->right:node->left;
            }
        }
    }
};
