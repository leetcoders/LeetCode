/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 10, 2013
 Update:     Jul 26, 2013
 Problem:    Remove Duplicates from Sorted List II
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_82
 Notes:
 Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
 For example,
 Given 1->2->3->3->4->4->5, return 1->2->5.
 Given 1->1->1->2->3, return 2->3.

 Solution: ...headptr...
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
        if (!head) return head;
        ListNode headptr(0);
        headptr.next = head;
        int duplicate = INT_MAX;
        ListNode *last = &headptr;
        ListNode *cur = head;
        while (cur)
        {
            if (cur->next && cur->val == cur->next->val || cur->val == duplicate)
            {
                duplicate = cur->val;
                last->next = cur->next;
                delete cur;
                cur = last->next;
            }
            else
            {
                last = cur;
                cur = cur->next;
            }
        }
        return headptr.next;
    }
};
