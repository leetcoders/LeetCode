/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       May 16, 2013
 Problem:    Construct Binary Tree from Preorder and Inorder Traversal
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_105
 Notes:
 Given preorder and inorder traversal of a tree, construct the binary tree.
 Note:
 You may assume that duplicates do not exist in the tree.

 Solution: Recursion.
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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        int N = inorder.size();
        return buildTreeRe(preorder, 0, N, inorder, 0, N);
    }

    TreeNode *buildTreeRe(vector<int> &preorder, int pre_s, int pre_e, 
                          vector<int> &inorder, int in_s, int in_e) {
        int N = in_e - in_s;
        if (N <= 0) return NULL;
        int pos = 0;
        while (pos < N && inorder[in_s + pos] != preorder[pre_s]) pos++;

        TreeNode *root = new TreeNode(preorder[pre_s]);
        root->left = buildTreeRe(preorder, pre_s + 1, pre_s + 1 + pos, 
                                 inorder, in_s, in_s + pos);
        root->right = buildTreeRe(preorder, pre_s + 1 + pos, pre_e, 
                                 inorder, in_s + pos + 1, in_e);
        return root;
    }
};