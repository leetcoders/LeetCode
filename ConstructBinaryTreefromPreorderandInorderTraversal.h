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
        return buildTreeRe(preorder.begin(), inorder.begin(), preorder.size());
    }

    TreeNode *buildTreeRe(vector<int>::iterator preorder, vector<int>::iterator inorder, int N) {
        if (N <= 0) return NULL;
        vector<int>::iterator it = find(inorder, inorder + N, *preorder);
        int pos = it - inorder;
        TreeNode *root = new TreeNode(*preorder);
        root->left = buildTreeRe(preorder+1, inorder, pos);
        root->right = buildTreeRe(preorder+1+pos, inorder+pos+1, N-1-pos);
        return root;
    }
};