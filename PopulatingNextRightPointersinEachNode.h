/*
 Author:     Annie Kim, anniekim.pku@gmail.com : King, higuige@gmail.com
 Date:       Apr 22, 2013
 Update:     Oct 7, 2014
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

 Solution: 1. Iterative: Two 'while' loops.
           2. Iterative: Queue. Use extra space.
           3. Recursive: DFS. Defect: Use extra stack space for recursion.
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
    void connect(TreeLinkNode *root) {
        connect_2(root);
    }
    void connect_1(TreeLinkNode *root) {
        if (root == nullptr) return;
        TreeLinkNode *cur = root;
        TreeLinkNode dummy(-1);
        TreeLinkNode *pre = &dummy;
        while (cur) {
            pre = &dummy;
            pre->next = nullptr;
            while (cur) {
                if (cur->left) {
                    pre->next = cur->left;
                    pre = pre->next;
                }
                if (cur->right) {
                    pre->next = cur->right;
                    pre = pre->next;
                }
                cur = cur->next;
            }
            cur = dummy.next;
        }
    }
    void connect_2(TreeLinkNode *root) {
        if (root == NULL) return;
        queue<TreeLinkNode *> q;
        q.push(root);
        q.push(NULL);
        TreeLinkNode *last = NULL;
        TreeLinkNode dummy(-1);
        TreeLinkNode *pre = &dummy;
        while (!q.empty()) {
            TreeLinkNode *node = q.front();
            q.pop();
            if (node == NULL) {
                if (dummy.next) q.push(NULL);
                pre = &dummy;
                pre->next = NULL;
            } else {
                pre->next = node;
                pre = pre->next;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
    }
    void connect_3(TreeLinkNode *root) {
        if (root == nullptr) return;
        TreeLinkNode dummy(-1);
        TreeLinkNode *pre = &dummy;
        TreeLinkNode *cur = root;
        while (cur) {
            if (cur->left) {
                pre->next = cur->left;
                pre = pre->next;
            }
            if (cur->right) {
                pre->next = cur->right;
                pre = pre->next;
            }
            cur = cur->next;
        }
        connect(dummy.next);
    }
};