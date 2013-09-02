/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 17, 2013
 Update:     Sep 2, 2013
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
        ListNode head(0), *cur = &head;
        while (l1 && l2) 
        {
            ListNode **min = l1->val < l2->val ? &l1 : &l2;
            cur->next = *min;
            cur = cur->next;
            *min = (*min)->next;
        }
        if (l1) cur->next = l1;
        if (l2) cur->next = l2;
        return head.next;
    }
};
