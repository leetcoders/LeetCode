/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 9, 2013
 Problem:    Convert Sorted Array to Binary Search Tree
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_108
 Notes:
 Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        return buildBST(num, 0, num.size() - 1);
    }
    
    TreeNode *buildBST(vector<int> &num, int start, int end)
    {
        if (start > end) return NULL;

        int mid = (start + end) / 2;
        TreeNode *root = new TreeNode(num[mid]);
        root->left = buildBST(num, start, mid - 1);
        root->right = buildBST(num, mid + 1, end);

        return root;
    }
};