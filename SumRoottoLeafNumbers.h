/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 23, 2013
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

 Solution: Recursion (add to sum when reaching the leaf).
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
    int sum;
    int sumNumbers(TreeNode *root) {
        sum = 0;
        sumNumbersRe(root, 0);
        return sum;
    }
    void sumNumbersRe(TreeNode *node, int num) {
        if (!node) return;
        num = num * 10 + node->val;
        if (!node->left && !node->right) { 
            sum += num;
            return;
        }
        sumNumbersRe(node->left, num);
        sumNumbersRe(node->right, num);
    }
};