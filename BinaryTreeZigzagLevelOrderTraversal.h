/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       May 16, 2013
 Update:     Aug 17, 2013
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

 Solution: 1. BFS(queue) + reverse vector.
           2. Two stack.
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
        return zigzagLevelOrder_2(root);
    }
    
    vector<vector<int>> zigzagLevelOrder_1(TreeNode *root) {
        vector<vector<int>> res;
        if (!root) return res;
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);   // end indicator of one level
        bool left2right = true;
        int level = 0;
        while (!q.empty())
        {
            TreeNode *front = q.front();
            q.pop();
            if (front)
            {
                if (res.size() == level)
                    res.push_back(vector<int>());
                res[level].push_back(front->val);
                if (front->left)
                    q.push(front->left);
                if (front->right)
                    q.push(front->right);
            }
            else
            {
                if (!q.empty())    // CAUTIOUS! infinite loop
                    q.push(NULL);
                if (!left2right)
                    reverse(res[level].begin(), res[level].end());
                left2right = !left2right;
                level++;
            }
        }
        return res;
    }
    
    vector<vector<int>> zigzagLevelOrder_2(TreeNode *root) {
        vector<vector<int>> res;
        if (!root) return res;
        stack<TreeNode *> stk[2];
        bool left2right = false;
        int cur = 1, last = 0;
        stk[last].push(root);
        int level = 0;
        while (!stk[last].empty())
        {
            TreeNode *node = stk[last].top();
            stk[last].pop();
            if (node)
            {
                if (res.size() == level)
                    res.push_back(vector<int>());
                res[level].push_back(node->val);
                if (left2right)
                {
                    stk[cur].push(node->right);
                    stk[cur].push(node->left);
                }
                else
                {
                    stk[cur].push(node->left);
                    stk[cur].push(node->right);
                }
            }
            if (stk[last].empty())
            {
                cur = !cur;
                last = !last;
                left2right = !left2right;
                level++;
            }
        }
        return res;
    }
};
