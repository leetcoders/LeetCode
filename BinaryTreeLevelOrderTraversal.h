/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 6, 2013
 Update:     Aug 15, 2013
 Problem:    Binary Tree Level Order Traversal
 Difficulty: easy
 Source:     http://leetcode.com/onlinejudge#question_102
 Notes:
 Given a binary tree, return the level order traversal of its nodes' values. 
 (ie, from left to right, level by level).

 For example:
 Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
 return its level order traversal as:
 [
  [3],
  [9,20],
  [15,7]
 ]
 
 Solution: 1. Use queue. In order to seperate the levels, use 'NULL' as the end indicator of one level.
           2. DFS.
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
    vector<vector<int>> levelOrder(TreeNode *root) {
        return levelOrder_1(root);
    }
    
    vector<vector<int> > levelOrder_1(TreeNode *root) {
        vector<vector<int> > res;
        if (!root) return res;
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);
        vector<int> level;
        while (true)
        {
            TreeNode *node = q.front(); q.pop();
            if (!node)
            {
                res.push_back(level);
                level.clear();
                if (q.empty()) break; // end
                q.push(NULL);
            }
            else
            {
                level.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        return res;
    }
    
    vector<vector<int>> levelOrder_2(TreeNode *root) {
        vector<vector<int>> res;
        levelOrderRe(root, 0, res);
        return res;
    }

    void levelOrderRe(TreeNode *node, int level, vector<vector<int>> &res)
    {
        if (!node) return;
        if (res.size() <= level) res.push_back(vector<int>());
        res[level].push_back(node->val);
        levelOrderRe(node->left, level + 1, res);
        levelOrderRe(node->right, level + 1, res);
    }
};
