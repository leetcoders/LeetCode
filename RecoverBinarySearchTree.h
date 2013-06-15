/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Jun 15, 2013
 Problem:    Recover Binary Search Tree
 Difficulty: High
 Source:     http://leetcode.com/onlinejudge#question_99
 Notes:
 Two elements of a binary search tree (BST) are swapped by mistake.
 Recover the tree without changing its structure.
 Note:
 A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?

 Solution: 1. recursive solution. O(n) space. get inorder list first.
           2. recursive solution. O(n) space. with only auxiliary two pointers.
           3. Morris inorder traversal. O(1) space. with only auxiliary two pointers.
*/

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // first solution
    void recoverTree_1(TreeNode *root) {
        vector<TreeNode *> inorder;
        inorderTraversal(root, inorder);
        TreeNode *first = NULL, *second = NULL;
        for (int i = 1; i < inorder.size(); ++i)
        {
            if (inorder[i-1]->val < inorder[i]->val)
                continue;
            if (!first)
                first = inorder[i-1];
            second = inorder[i];
        }
        swap(first->val, second->val);
    }

    void inorderTraversal(TreeNode *root, vector<TreeNode *> &inorder) {
        if (!root) return;
        inorderTraversal(root->left, inorder);
        inorder.push_back(root);
        inorderTraversal(root->right, inorder);
    }

    // second solution
    void recoverTree_2(TreeNode *root) {
        TreeNode *prev = NULL, *first = NULL, *second = NULL;
        recoverTreeRe(root, prev, first, second);
        swap(first->val, second->val);
    }

    void recoverTreeRe(TreeNode *curNode, TreeNode *&preNode, TreeNode *&first, TreeNode *&second) {
        if (curNode == NULL) return;
        recoverTreeRe(curNode->left, preNode, first, second);
        if (preNode && preNode->val > curNode->val) {
            if (first == NULL) 
                first = preNode;
            second = curNode;
        }
        preNode = curNode;
        recoverTreeRe(curNode->right, preNode, first, second);
    }
    
    // third solution
    void recoverTree_3(TreeNode *root) {
        TreeNode *cur = root, *prev = NULL;
        TreeNode *first = NULL, *second = NULL, *last = NULL;
        while (cur != NULL)
        {
            if (cur->left == NULL)
            {
                compare(last, cur, first, second);
                last = cur;
                cur = cur->right;
            }
            else
            {
                prev = cur->left;
                while (prev->right != NULL && prev->right != cur)
                    prev = prev->right;

                if (prev->right == NULL)
                {
                    prev->right = cur;
                    cur = cur->left;
                }
                else
                {
                    compare(last, cur, first, second);
                    last = cur;
                    prev->right = NULL;
                    cur = cur->right;
                }
            }
        }
        swap(first->val, second->val);
    }

    void compare(TreeNode *last, TreeNode *cur, TreeNode *&first, TreeNode *&second)
    {
        if (last && last->val > cur->val)
        {
            if (!first)
                first = last;
            second = cur;
        }
    }
};