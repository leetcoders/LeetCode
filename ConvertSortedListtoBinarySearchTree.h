/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 10, 2013
 Update:     Jul 29, 2013
 Problem:    Convert Sorted List to Binary Search Tree
 Difficulty: Medium
 Source:     http://leetcode.com/onlinejudge#question_109
 Notes:
 Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

 Solution: Recursion. Pre-order. O(n)
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
        return sortedListToBSTRe(head, getLength(head));
    }
    
    TreeNode *sortedListToBSTRe(ListNode *&head, int length)
    {
        if (length == 0) return NULL;
        int mid = length / 2;
        TreeNode *left = sortedListToBSTRe(head, mid);
        TreeNode *root = new TreeNode(head->val);
        TreeNode *right = sortedListToBSTRe(head->next, length - mid - 1);
        root->left = left;
        root->right = right;
        head = head->next;
        return root;
    }
    
    int getLength(ListNode *head)
    {
        int length = 0;
        while (head)
        {
            length++;
            head = head->next;
        }
        return length;
    }
};
