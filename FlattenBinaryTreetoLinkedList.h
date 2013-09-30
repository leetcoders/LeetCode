/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 28, 2013
 Update:     Sep 29, 2013
 Problem:    Flatten Binary Tree to Linked List
 Difficulty: Medium
 Source:     http://leetcode.com/onlinejudge#question_114
 Notes:
 Given a binary tree, flatten it to a linked list in-place.
 For example,
 Given
     1
    / \
   2   5
  / \   \
 3   4   6
 The flattened tree should look like:
 1
  \
   2
    \
     3
      \
       4
        \
         5
          \
           6
 Hints:
 If you notice carefully in the flattened tree, each node's right child points to the next node 
 of a pre-order traversal.

 Solution: Recursion. Return the last element of the flattened sub-tree.
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
    void flatten(TreeNode *root) {
        TreeNode *end = NULL;
        flattenRe(root, end);
    }
    
    void flattenRe(TreeNode *node, TreeNode *&end) {
        if (!node) return;
        TreeNode *lend = NULL, *rend = NULL;
        flattenRe(node->left, lend);
        flattenRe(node->right, rend);
        if (node->left) {
            lend->right = node->right;
            node->right = node->left;
            node->left = NULL;
        }
        end = rend ? rend : (lend ? lend : node);
    }
};