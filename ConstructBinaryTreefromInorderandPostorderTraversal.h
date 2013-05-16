/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       May 16, 2013
 Problem:    Construct Binary Tree from Inorder and Postorder Traversal
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_106
 Notes:
 Given inorder and postorder traversal of a tree, construct the binary tree.
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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        int N = inorder.size();
        return buildTreeRe(inorder, 0, N, postorder, 0, N);
    }

    TreeNode *buildTreeRe(vector<int> &inorder, int in_s, int in_e, 
                          vector<int> &postorder, int post_s, int post_e) {
        int N = in_e - in_s;
        if (N <= 0) return NULL;
        int pos = 0;
        while (pos < N && inorder[in_s + pos] != postorder[post_e-1]) pos++;

        TreeNode *root = new TreeNode(postorder[post_e-1]);
        root->left = buildTreeRe(inorder, in_s, in_s + pos, 
                                 postorder, post_s, post_s + pos);
        root->right = buildTreeRe(inorder, in_s + pos + 1, in_e, 
                                  postorder, post_s + pos, post_e - 1);
        return root;
    }
};