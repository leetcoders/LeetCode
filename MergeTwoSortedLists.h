/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 17, 2013
 Update:     Jul 15, 2013
 Problem:    Merge Two Sorted Lists
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_21
 Notes:
 Merge two sorted linked lists and return it as a new list. 
 The new list should be made by splicing together the nodes of the first two lists.

 Solution: ...
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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        ListNode *head = NULL, *cur = NULL;
        while (l1 && l2)
        {
            if (l1->val < l2->val)
            {
                if (!head) {
                    head = l1;
                    cur = head;
                } else {
                    cur->next = l1;
                    cur = cur->next;
                }
                l1 = l1->next;
            }
            else
            {
                if (!head) {
                    head = l2;
                    cur = head;
                } else {
                    cur->next = l2;
                    cur = cur->next;
                }
                l2 = l2->next;
            }
        }
        if (l1) cur->next = l1;
        if (l2) cur->next = l2;
        return head;
    }
};
