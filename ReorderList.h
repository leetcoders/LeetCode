/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Nov 11, 2013
 Problem:    Reorder List
 Difficulty: Easy
 Source:     http://oj.leetcode.com/problems/reorder-list/
 Notes:
 Given a singly linked list L: L0->L1->...->Ln-1->Ln,
 reorder it to: L0->Ln->L1->Ln-1->L2->Ln-2->...
 You must do this in-place without altering the nodes' values.
 For example,
 Given {1,2,3,4}, reorder it to {1,4,2,3}.

 Solution: Reverse the back half first, then reorder.
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
    void reorderList(ListNode *head) {
        if (!head || !head->next) return;
        ListNode *slow = head, *fast = head->next->next;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        if (fast) slow = slow->next;
        ListNode *mid = slow, *cur = slow->next;
        while (cur->next) {
            ListNode *mov = cur->next;
            cur->next = mov->next;
            mov->next = mid->next;
            mid->next = mov;
        }
        cur = head;
        while (cur != mid && mid->next) {
            ListNode *mov = mid->next;
            mid->next = mov->next;
            mov->next = cur->next;
            cur->next = mov;
            cur = cur->next->next;
        }
    }
};