/*
 Author:     Annie Kim, anniekim.pku@gmail.com : King, higuige@gmail.com
 Date:       Apr 28, 2013
 Update:     Oct 7, 2014
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
        flatten_3(root);
    }

    void flatten_1(TreeNode *root) {
        if (root == NULL) return;
        flatten_1(root->left);
        flatten_2(root->right);
        if (root->left == NULL) return;
        TreeNode *p = root->left;
        while (p->right) p = p->right;
        p->right = root->right;
        root->right = root->left;
        root->left = NULL;
    }

    TreeNode * dfs (TreeNode * root, TreeNode * tail){
        if(root == NULL) return tail;
        root->right = dfs(root->left,dfs(root->right,tail));
        root->left = NULL;
        return root;
    }
    void flatten_2(TreeNode *root) {
        if(root == NULL) return;
        dfs(root, NULL);
    }
    void flatten_3(TreeNode *root) {
        if(root==nullptr) return;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty()){
            auto p=s.top();
            s.pop();
            if(p->right) s.push(p->right);
            if(p->left) s.push(p->left);
            p->left = nullptr;
            if(!s.empty()){
                p->right=s.top();
            }else p->right = nullptr;
        }
    }

    void flatten_4(TreeNode *root) {
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