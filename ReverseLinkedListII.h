/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 9, 2013
 Problem:    Reverse Linked List II
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_92
 Notes:
 Reverse a linked list from position m to n. Do it in-place and in one-pass.
 For example:
 Given 1->2->3->4->5->NULL, m = 2 and n = 4,
 return 1->4->3->2->5->NULL.
 Note:
 Given m, n satisfy the following condition:
 1 <= m <= n <= length of list.

 Solution: Insert and delete node iteratively. (in-place & one-pass)
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if (m == n) return head;
        
        ListNode *headptr = new ListNode(0); 
        headptr->next = head;  // 'headptr' is a node pointing to head
        
        ListNode *insert = headptr; // insert a new node after 'insert' node
        for (int i = 0; i < m - 1; i++)
        {
            insert = insert->next;
        }
        
        ListNode *cur = insert->next;
        for (int i = 0; i < n - m; i++)
        {
            ListNode *del = cur->next;
            cur->next = del->next;
            del->next = insert->next;
            insert->next = del;
        }
        
        if (m == 1) 
            head = headptr->next;
        delete headptr;
        
        return head;
    }
};