/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 6, 2013
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
 
 Solution: Use queue. In order to seperate the levels, use 'NULL' as the 
           end indicator of one level.
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
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int>> res;
        
        queue<TreeNode *> q;
        if (root)
        {
            q.push(root);
            q.push(NULL);   // end indicator of one level
        }
        
        vector<int> level;
        while (q.size() > 0)
        {
            TreeNode *front = q.front();
            q.pop();
            if (front)
            {
                level.push_back(front->val);
                if (front->left)
                    q.push(front->left);
                if (front->right)
                    q.push(front->right);
            }
            else
            {
                if (q.size() > 0)    // CAUTIOUS! infinite loop
                    q.push(NULL);
                res.push_back(level);
                level.clear();
            }
        }
        
        return res;
    }
};