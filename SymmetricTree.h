/*
 Author:     Annie Kim, anniekim.pku@gmail.com : King, higuige@gmail.com
 Date:       Apr 22, 2013
 Update:     Oct 07, 2014
 Problem:    Symmetric Tree
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_101
 Notes:
 Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
 For example, this binary tree is symmetric:
     1
    / \
   2   2
  / \ / \
 3  4 4  3
 But the following is not:
    1
   / \
  2   2
   \   \
   3    3
 Note:
 Bonus points if you could solve it both recursively and iteratively.

 Solution: 1. Recursive solution 2.Iterative way (queue).
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
    bool isSymmetric(TreeNode *root) {
        return isSymmetric_2(root);
    }
    bool isSymmetric_1(TreeNode *root) {
        if (root == NULL) return true;
        return solve (root->left, root->right);
    }
    bool solve(TreeNode * t1, TreeNode * t2) {
        if (!t1 && !t2) return true;
        if (!t1 && t2 || t1 && !t2 || t1->val != t2->val) return false;
        return solve(t1->left, t2->right) && solve(t1->right, t2->left);
    }
    bool isSymmetric_2(TreeNode *root) {
        if (root == NULL) return true;
        stack<TreeNode *> s;
        s.push(root->left);
        s.push(root->right);
        while (!s.empty()) {
            TreeNode *t2 = s.top(); s.pop();
            TreeNode *t1 = s.top(); s.pop();
            if (!t1 && !t2) continue;
            if (!t1 && t2 || t1 && !t2 || t1->val != t2->val) return false;
            s.push(t1->right);
            s.push(t2->left);
            s.push(t1->left);
            s.push(t2->right);
        }
        return true;
    }
    bool isSymmetric_3(TreeNode *root) {
        if (root == NULL) return true;
        queue<TreeNode *> q;
        q.push(root->left);
        q.push(root->right);
        while (!s.empty()) {
            TreeNode *t2 = q.front(); q.pop();
            TreeNode *t1 = q.front(); q.pop();
            if (!t1 && !t2) continue;
            if (!t1 && t2 || t1 && !t2 || t1->val != t2->val) return false;
            q.push(t1->left);
            q.push(t2->right);
            q.push(t1->right);
            q.push(t2->left);
        }
        return true;
    }
};