/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 22, 2013
 Problem:    Binary Tree Inorder Traversal
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_94
 Notes:
 Given a binary tree, return the inorder traversal of its nodes' values.
 For example:
 Given binary tree {1,#,2,3},
 1
  \
   2
  /
 3
 return [1,3,2].
 Note: Recursive solution is trivial, could you do it iteratively?

 Solution: 1. Iterative way (stack). 2. Recursive solution.
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
    vector<int> inorderTraversal_1(TreeNode *root) {
        vector<int> res;
        if (!root) return res;
        stack<pair<TreeNode *, bool>> stk;
        stk.push(make_pair(root->right, false));
        stk.push(make_pair(root, true));
        stk.push(make_pair(root->left, false));
        while (!stk.empty())
        {
            pair<TreeNode *, bool> p = stk.top();
            stk.pop();
            if (p.second == true) {
                res.push_back(p.first->val);
            } else if (p.first) {
                stk.push(make_pair(p.first->right, false));
                stk.push(make_pair(p.first, true));
                stk.push(make_pair(p.first->left, false));
            }
        }
        return res;
    }

    vector<int> inorderTraversal_2(TreeNode *root) {
        vector<int> res;
        inorderTraversalRe(root, res);
        return res;
    }

    void inorderTraversalRe(TreeNode *node, vector<int> &res) {
        if (!node) return;
        inorderTraversalRe(node->left, res);
        res.push_back(node->val);
        inorderTraversalRe(node->right, res);
    }
};