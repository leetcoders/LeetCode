/*
 Author:     Matthew Jin, marthew777@gmail.com
 Co-author:  Annie Kim, anniekim.pku@gmail.com
 Date:       Feb 21, 2014
 Problem:    Binary Tree Postorder Traversal 
 Difficulty: Easy
 Source:     http://oj.leetcode.com/problems/binary-tree-postorder-traversal/
 Notes:
 Given a binary tree, return the postorder traversal of its nodes' values.

 For example:
 Given binary tree {1,#,2,3},
    1
     \
      2
     /
    3
 return [3,2,1].

 Note: Recursive solution is trivial, could you do it iteratively?

 Solution: 1. Iterative way (stack).   Time: O(n), Space: O(n).
           2. Recursive solution.      Time: O(n), Space: O(n).
           3. Threaded tree (Morris).  Time: O(n), Space: O(1). 
              You may refer to my blog for more detailed explanations: 
              http://www.cnblogs.com/AnnieKim/archive/2013/06/15/MorrisTraversal.html
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
    vector<int> postorderTraversal(TreeNode *root) {
        return postorderTraversal_1(root);
    }
    
    vector<int> postorderTraversal_1(TreeNode *root) {
        vector<int> res;
        stack<TreeNode *> stk;
        TreeNode *last = NULL, *cur = root;
        while(cur || !stk.empty()){
            if (cur) {
                stk.push(cur);
                cur = cur->left;
            }
            else{
                TreeNode *peak = stk.top();
                if(peak->right && last != peak->right)
                    cur = peak->right;
                else{
                    res.push_back(peak->val); 
                    stk.pop();
                    last = peak;
                }
            }
        }
        return res;
    }
    
    vector<int> postorderTraversal_2(TreeNode *root) {
        vector<int> res;
        postorderTraversalRe(root, res);
        return res;
    }

    void postorderTraversalRe(TreeNode *node, vector<int> &res) {
        if (!node) return;
        postorderTraversalRe(node->left, res);
        postorderTraversalRe(node->right, res);
        res.push_back(node->val);
    }
    
    vector<int> postorderTraversal_3(TreeNode *root) {
        vector<int> res;
        TreeNode dump(0);
        dump.left = root;
        TreeNode *cur = &dump, *prev = NULL;
        while (cur)
        {
            if (cur->left == NULL)
            {
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
                    printReverse(cur->left, prev, res);  // call print
                    prev->right = NULL;
                    cur = cur->right;
                }
            }
        }
        return res;
    }

    void printReverse(TreeNode* from, TreeNode *to, vector<int>& res) // print the reversed tree nodes 'from' -> 'to'.
    {
        reverse(from, to);
        
        TreeNode *p = to;
        while (true)
        {
            res.push_back(p->val);
            if (p == from)
                break;
            p = p->right;
        }
        
        reverse(to, from);
    }
    
    void reverse(TreeNode *from, TreeNode *to) // reverse the tree nodes 'from' -> 'to'.
    {
        if (from == to)
            return;
        TreeNode *x = from, *y = from->right, *z;
        while (true)
        {
            z = y->right;
            y->right = x;
            x = y;
            y = z;
            if (x == to)
                break;
        }
    }
};