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
        return buildTreeRe(inorder.begin(), postorder.begin(), N);
    }

    TreeNode *buildTreeRe(vector<int>::iterator inorder, vector<int>::iterator postorder, int N) {
        if (N <= 0) return NULL;
        vector<int>::iterator it = find(inorder, inorder+N, *(postorder+N-1));
        int pos = it - inorder;
        TreeNode *root = new TreeNode(*(postorder+N-1));
        root->left = buildTreeRe(inorder, postorder, pos);
        root->right = buildTreeRe(inorder+pos+1, postorder+pos, N-pos-1);
        return root;
    }
};