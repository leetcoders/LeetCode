/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 18, 2013
 Problem:    Reverse Nodes in k-Group
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_25
 Notes:
 Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
 If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
 You may not alter the values in the nodes, only nodes itself may be changed.
 Only constant memory is allowed.
 For example,
 Given this linked list: 1->2->3->4->5
 For k = 2, you should return: 2->1->4->3->5
 For k = 3, you should return: 3->2->1->4->5

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
    ListNode *reverseKGroup(ListNode *head, int k) {
        int len = GetLength(head);
        int reverseTimes = len / k;
        if (reverseTimes == 0) return head;

        ListNode *headptr = new ListNode(0);
        headptr->next = head;
        ListNode *insptr = headptr;   // insert the reversed nodes after insptr
        ListNode *cur = insptr->next;
        for (int i = 0; i < reverseTimes; ++i) {
            for (int j = 0; j < k - 1; ++j) {
                ListNode *rev = cur->next;
                cur->next = rev->next;
                rev->next = insptr->next;
                insptr->next = rev;
            }
            insptr = cur;
            cur = insptr->next;
        }
        head = headptr->next;
        delete headptr;
        return head;
    }

    int GetLength(ListNode *head)
    {
        int len = 0;
        while (head) {
            head = head->next;
            len++;
        }
        return len;
    }
};
