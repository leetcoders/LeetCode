/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 23, 2013
 Update:     Jul 21, 2013
 Problem:    Sum Root to Leaf Numbers
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_129
 Notes:
 Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.
 An example is the root-to-leaf path 1->2->3 which represents the number 123.
 Find the total sum of all root-to-leaf numbers.
 For example,
   1
  / \
 2   3
 The root-to-leaf path 1->2 represents the number 12.
 The root-to-leaf path 1->3 represents the number 13.
 Return the sum = 12 + 13 = 25.

 Solution: 1. Recursion (add to sum when reaching the leaf).
           2. Iterative solution.
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
    int sumNumbers(TreeNode *root) {
        return sumNumbers_1(root);
    }
    
    int sumNumbers_1(TreeNode *root) {
        int sum = 0;
        sumNumbersRe(root, 0, sum);
        return sum;
    }
    
    void sumNumbersRe(TreeNode *node, int num, int &sum) {
        if (!node) return;
        num = num * 10 + node->val;
        if (!node->left && !node->right) { 
            sum += num;
            return;
        }
        sumNumbersRe(node->left, num, sum);
        sumNumbersRe(node->right, num, sum);
    }
    
    int sumNumbers_2(TreeNode *root) {
        if (!root) return 0;
        int res = 0;
        queue<pair<TreeNode *, int>> q;
        q.push(make_pair(root, 0));
        while(!q.empty())
        {
            TreeNode *node = q.front().first;
            int sum = q.front().second * 10 + node->val;
            q.pop();
            if (!node->left && !node->right)
            {
                res += sum;
                continue;
            }
            if (node->left)
                q.push(make_pair(node->left, sum));
            if (node->right)
                q.push(make_pair(node->right, sum));
        }
        return res;
    }
};
