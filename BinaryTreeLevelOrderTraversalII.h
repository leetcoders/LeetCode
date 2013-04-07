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
 
 Solution: 
 1. Queue version. On the basis of 'Binary Tree Level Order Traversal', reverse the final vector.
 2. Stack version. Store each level in the vector and then push the vector into stack.
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
    vector<vector<int> > levelOrderBottom_1(TreeNode *root) {
        vector<vector<int>> root2leaf;
        
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
                root2leaf.push_back(level);
                level.clear();
            }
        }
        
    	// reverse
        vector<vector<int>> leaf2root;
        for (size_t i = 0; i < root2leaf.size(); i++)
        {
            leaf2root.push_back(root2leaf[root2leaf.size()-i-1]);
        }
        return leaf2root;
    }

    vector<vector<int> > levelOrderBottom_2(TreeNode *root) {
        vector<vector<int>> res;
        
        if (!root)
            return res;
        
        stack<vector<TreeNode *>> stk;
        vector<TreeNode *> level;
        level.push_back(root);
        stk.push(level);
        
        while (true)
        {
            level.clear();
            for (size_t i = 0; i < stk.top().size(); i++)
            {
                if (stk.top()[i]->left)
                    level.push_back(stk.top()[i]->left);
                if (stk.top()[i]->right)
                    level.push_back(stk.top()[i]->right);
            }
            
            if (level.size() == 0)
                break;
            
            stk.push(level);
        }
        
        while (stk.size() > 0)
        {
            vector<int> level_val;
            for (size_t i = 0; i < stk.top().size(); i++)
            {
                level_val.push_back(stk.top()[i]->val);
            }
            res.push_back(level_val);
            stk.pop();
        }
        
        return res;
    }
};
