/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 10, 2013
 Problem:    Convert Sorted List to Binary Search Tree
 Difficulty: Medium
 Source:     http://leetcode.com/onlinejudge#question_109
 Notes:
 Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

 Solution: Recursion. 
 1. In-order. This will take more time than pre-order, since we need to traverse to the middle point first.
 2. Pre-order. O(n)
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
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
    TreeNode *sortedListToBST(ListNode *head) {
        if (!head) return NULL;
        ListNode *cur = head;
        int len = 1;
        while (cur = cur->next)
            len++;
        
        return buildBST_Pre(head, len);
    }
    
    // In-order
    TreeNode *buildBST_In(ListNode *head, int len)
    {
        if (len == 0 ) return NULL;
        if (len == 1) return new TreeNode(head->val);
        
        ListNode *cur = head;
        for (int i = 0; i < len / 2; i++)
            cur = cur->next;
        
        TreeNode *root = new TreeNode(cur->val);
        root->left = buildBST_In(head, len / 2);
        root->right = buildBST_In(cur->next, len%2==0 ? (len/2-1) : len/2);
        return root;
    }
    
    // Pre-order, O(n)
    TreeNode *buildBST_Pre(ListNode *&head, int len)
    {
        if (len == 0 ) return NULL;
        TreeNode *left = buildBST_Pre(head, len / 2);
        TreeNode *root = new TreeNode(head->val);
        root->left = left;
        head = head->next;
        root->right = buildBST_Pre(head, len%2==0 ? (len/2-1) : len/2);
        return root;
    }
};