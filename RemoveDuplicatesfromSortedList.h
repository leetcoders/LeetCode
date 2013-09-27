/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 10, 2013
 Update:     Jul 17, 2013 (Add solution 2)
 Problem:    Remove Duplicates from Sorted List
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_83
 Notes:
 Given a sorted linked list, delete all duplicates such that each element appear only once.
 For example,
 Given 1->1->2, return 1->2.
 Given 1->1->2->3->3, return 1->2->3.

 Solution: 1. Delete duplicates directly.
           2. Copy value first (like Remove Duplicates from Array) and then delete the remaining elements.
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
    ListNode *deleteDuplicates(ListNode *head) {
        return deleteDuplicates_1(head);
    }
    
    ListNode *deleteDuplicates_1(ListNode *head) {
        if (!head) return head;
        ListNode *cur = head;
        while (cur->next)
        {
            if (cur->val == cur->next->val)
            {
                ListNode *del = cur->next;
                cur->next = del->next;
                delete del;
            }
            else
            {
                cur = cur->next;
            }
        }
        return head;
    }
    
    ListNode *deleteDuplicates_2(ListNode *head) {
        if (!head) return head;
        ListNode *last = head, *cur = head->next;
        while (cur)
        {
            if (last->val != cur->val) {
                last = last->next;
                last->val = cur->val;
            }
            cur = cur->next;
        }
        cur = last->next;
        while (cur) {
            ListNode *del = cur;
            cur = cur->next;
            delete del;
        }
        last->next = NULL;
        return head;
    }
};
