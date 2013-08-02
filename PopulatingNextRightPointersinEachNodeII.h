/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 23, 2013
 Update:     Aug 8, 2013
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

 Solution: From root->leaf, left->right.
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
        while (root)
        {
            TreeLinkNode *level = root;
            TreeLinkNode *last = NULL;
            root = NULL;
            while (level)
            {
                if (!level->left && !level->right)
                {
                    level = level->next;
                    continue;
                }
                if (last) 
                    last->next = level->left ? level->left : level->right;
                if (level->left)
                    level->left->next = level->right ? level->right : NULL;
                if (!root)
                    root = level->left ? level->left : level->right;
                last = level->right ? level->right : level->left;
                level = level->next;
            }
        }
    }
};
