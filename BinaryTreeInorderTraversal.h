/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 22, 2013
 Update:     Aug 18, 2013
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
    vector<int> inorderTraversal(TreeNode *root) {
        return inorderTraversal_1(root);
    }
    
    vector<int> inorderTraversal_1(TreeNode *root) {
        vector<int> res;
        stack<TreeNode *> stk;
        TreeNode *cur = root;
        while (cur || !stk.empty())
        {
            if (cur)
            {
                stk.push(cur);
                cur = cur->left;
            }
            else if (!stk.empty())
            {
                res.push_back(stk.top()->val);
                cur = stk.top()->right;
                stk.pop();
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
    
    vector<int> inorderTraversal_3(TreeNode *root) {
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
                    res.push_back(cur->val);
                    cur = cur->right;
                    prev->right = NULL;
                }
                else
                {
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
