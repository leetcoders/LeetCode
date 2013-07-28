/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 9, 2013
 Update:     Jul 28, 2013
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
        ListNode headptr(0);
        headptr.next = head;
        ListNode *ins = &headptr, *cur = head;
        for (int i = 1; i < n; ++i)
        {
            if (i < m)
            {
                ins = ins->next;
                cur = cur->next;
            }
            else if (i >= m && i < n)
            {
                ListNode *move = cur->next;
                cur->next = move->next;
                move->next = ins->next;
                ins->next = move;
            }
        }
        return headptr.next;
    }
};
