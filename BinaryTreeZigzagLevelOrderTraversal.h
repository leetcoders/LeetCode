/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       May 16, 2013
 Problem:    Binary Tree Zigzag Level Order Traversal
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_103
 Notes:
 Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left 
 to right, then right to left for the next level and alternate between).
 For example:
 Given binary tree {3,9,20,#,#,15,7},
     3
    / \
   9  20
  / \
 15  7
 return its zigzag level order traversal as:
 [
  [3],
  [20,9],
  [15,7]
 ]

 Solution: In top of 'Binary Tree Level Order Traversal', reverse the elements in 'level' if necessary.
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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        queue<TreeNode *> q;
        if (root)
        {
            q.push(root);
            q.push(NULL);   // end indicator of one level
        }

        vector<vector<int>> res;
        vector<int> level;
        bool left2right = true;
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
                if (!left2right)
                    reverse(level.begin(), level.end());
                left2right = !left2right;
                res.push_back(level);
                level.clear();
            }
        }
        return res;
    }
};