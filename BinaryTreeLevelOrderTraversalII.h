/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 7, 2013
 Problem:    Binary Tree Level Order Traversal II
 Difficulty: easy
 Source:     http://leetcode.com/onlinejudge#question_107
 Notes:
 Given a binary tree, return the bottom-up level order traversal of its nodes' values. 
 (ie, from left to right, level by level from leaf to root).

 For example:
 Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
 return its bottom-up level order traversal as:
 [
  [15,7]
  [9,20],
  [3],
 ]
 
 Solution: Queue version. On the basis of 'Binary Tree Level Order Traversal', reverse the final vector.
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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int>> root2leaf;
        queue<TreeNode *> q;
        if (!root) return root2leaf;
        q.push(root);
        q.push(NULL);   // end indicator of one level
        vector<int> level;
        while (true)
        {
            TreeNode *node = q.front(); q.pop();
            if (node)
            {
                level.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            else
            {
                root2leaf.push_back(level);
                level.clear();
                if (q.empty()) break;    // CAUTIOUS! infinite loop
                q.push(NULL);
            }
        }
    	// reverse
        reverse(root2leaf.begin(), root2leaf.end());
        return root2leaf;
    }
};