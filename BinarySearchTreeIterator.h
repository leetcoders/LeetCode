/*
 Author:     king, wangjingui@outlook.com
 Date:       Dec 29, 2014
 Problem:    Binary Search Tree Iterator 
 Difficulty: Easy
 Source:     https://oj.leetcode.com/problems/binary-search-tree-iterator/
 Notes:
 Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

 Calling next() will return the next smallest number in the BST.

 Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.

 Solution: Inorder traversal.
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
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        node = root;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        if (stk.empty() == true && node == NULL) return false;
        return true;
    }

    /** @return the next smallest number */
    int next() {
        if (stk.empty() == true && node == NULL) return 0;
        while (node != NULL) {
            stk.push(node);
            node = node->left;
        }
        int res = 0;
        node = stk.top();
        stk.pop();
        res = node->val;
        node = node->right;
        return res;
    }
private:
    TreeNode * node;
    stack<TreeNode*> stk;
};
/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */