/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 22, 2013
 Update:     Apr 22, 2013
 Problem:    Populating Next Right Pointers in Each Node
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_116
 Notes:
 Given a binary tree
 struct TreeLinkNode {
    TreeLinkNode *left;
    TreeLinkNode *right;
    TreeLinkNode *next;
 }
 Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.
 Initially, all next pointers are set to NULL.
 Note:
 You may only use constant extra space.
 You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
 For example,
 Given the following perfect binary tree,
     1
    /  \
   2    3
  / \  / \
 4  5  6  7
 After calling your function, the tree should look like:
     1 -> NULL
    /  \
   2 -> 3 -> NULL
  / \  / \
 4->5->6->7 -> NULL

 Solution: 1. Iterative: Two 'while' loops: top->leaf and left->right.
           2. Recursive: DFS.
 */

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */

class Solution {
public:
    void connect_1(TreeLinkNode *root) {
        if (!root) return;
        root->next = NULL;
        TreeLinkNode *parent = root;
        while (parent->left)
        {
            TreeLinkNode *pHead = parent;
            pHead->left->next = pHead->right;
            TreeLinkNode *cTail = pHead->right;
            while (pHead = pHead->next)
            {
                cTail->next = pHead->left;
                pHead->left->next = pHead->right;
                cTail = pHead->right;
            }
            cTail->next = NULL;
            parent = parent->left;
        }
    }

    void connect_2(TreeLinkNode *root) {
        if (!root) return;
        root->next = NULL;
        connectRe(root);
    }

    void connectRe(TreeLinkNode *node) {
        if (!node || !node->left) return;
        node->left->next = node->right;
        node->right->next = node->next ? node->next->left : NULL;
        connectRe(node->left);
        connectRe(node->right);
    }
};