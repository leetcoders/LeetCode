/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 22, 2013
 Update:     Sep 8, 2013
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

 Solution: 1. Iterative: Two 'while' loops: root->leaf and left->right.
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
        connect_1(root);
    }
    
    void connect_1(TreeLinkNode *root) {
        while (root)
        {
            TreeLinkNode *level = root;
            TreeLinkNode *last = NULL;
            while (level && level->left)
            {
                if (last) last->next = level->left;
                level->left->next = level->right;
                last = level->right;
                level = level->next;
            }
            root = root->left;
        }
    }
    
    void connect_2(TreeLinkNode *root) {
        if (!root) return;
        queue<TreeLinkNode *> q;
        q.push(root);
        q.push(NULL);
        TreeLinkNode *last = NULL;
        while (true)
        {
            TreeLinkNode *node = q.front();
            q.pop();
            if (!node) {
                last = NULL;
                if (q.empty()) break;
                q.push(NULL);
            } else {
                if (last) last->next = node;
                last = node;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
    }
    
    void connect_3(TreeLinkNode *node) {
        if (!node || !node->left) return;
        node->left->next = node->right;
        node->right->next = node->next ? node->next->left : NULL;
        connect_3(node->left);
        connect_3(node->right);
    }
};
