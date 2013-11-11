/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Nov 11, 2013
 Problem:    Binary Tree Preorder Traversal
 Difficulty: Easy
 Source:     http://oj.leetcode.com/problems/binary-tree-preorder-traversal/
 Notes:
 Given a binary tree, return the preorder traversal of its nodes' values.
 For example:
 Given binary tree {1,#,2,3},
    1
     \
      2
     /
    3
 return [1,2,3].
 Note: Recursive solution is trivial, could you do it iteratively?

 Solution: 1. Iterative way (stack).   Time: O(n), Space: O(n).
           2. Recursive solution.      Time: O(n), Space: O(n).
           3. Threaded tree (Morris).  Time: O(n), Space: O(1).
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
    vector<int> preorderTraversal(TreeNode *root) {
        return preorderTraversal_3(root);
    }
    
    vector<int> preorderTraversal_1(TreeNode *root) {
        vector<int> res;
        stack<TreeNode *> stk;
        TreeNode *cur = root;
        while (cur || !stk.empty())
        {
            if (cur)
            {
                res.push_back(cur->val);
                stk.push(cur);
                cur = cur->left;
            }
            else if (!stk.empty())
            {
                cur = stk.top()->right;
                stk.pop();
            }
        }
        return res;
    }
    
    vector<int> preorderTraversal_2(TreeNode *root) {
        vector<int> res;
        preorderTraversalRe(root, res);
        return res;
    }

    void preorderTraversalRe(TreeNode *node, vector<int> &res) {
        if (!node) return;
        res.push_back(node->val);
        preorderTraversalRe(node->left, res);
        preorderTraversalRe(node->right, res);
    }
    
    vector<int> preorderTraversal_3(TreeNode *root) {
        vector<int> res;
        TreeNode *cur = root;
        while (cur)
        {
            if (cur->left)
            {
                TreeNode *prev = cur->left;
                while (prev->right && prev->right != cur)
                    prev = prev->right;
                    
                if (prev->right == cur)
                {
                    cur = cur->right;
                    prev->right = NULL;
                }
                else
                {
                    res.push_back(cur->val);
                    prev->right = cur;
                    cur = cur->left;
                }
            }
            else
            {
                res.push_back(cur->val);
                cur = cur->right;
            }
        }
        return res;
    }
};