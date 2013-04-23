/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 23, 2013
 Problem:    Populating Next Right Pointers in Each Node II
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_117
 Notes:
 Follow up for problem "Populating Next Right Pointers in Each Node".
 What if the given tree could be any binary tree? Would your previous solution still work?
 Note:
 You may only use constant extra space.
 For example,
 Given the following binary tree,
     1
    /  \
   2    3
  / \    \
 4   5    7
 After calling your function, the tree should look like:
     1 -> NULL
    /  \
   2 -> 3 -> NULL
  / \    \
 4-> 5 -> 7 -> NULL

 Solution: Extend level-order traversal (queue).
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
        if (!root) return;
        root->next = NULL;
        queue<TreeLinkNode *> q;
        q.push(root);
        q.push(root->next);
        while (!q.empty())
        {
            TreeLinkNode *cur = q.front();
            TreeLinkNode *bef = NULL;
            q.pop();
            while (cur)
            {
                if (bef) bef->next = cur;
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
                bef = cur;
                cur = q.front();
                q.pop();
            }
            if (cur) cur->next = NULL;
            if (!q.empty()) q.push(NULL);
        }
    }
};