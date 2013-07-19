/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Jan 16, 2013
 Update:     Jul 19, 2013
 Problem:    Add Two Numbers
 Difficulty: easy
 Source:     http://www.leetcode.com/onlinejudge
 Notes:
 You are given two linked lists representing two non-negative numbers. 
 The digits are stored in reverse order and each of their nodes contain a single digit. 
 Add the two numbers and return it as a linked list.

 Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 Output: 7 -> 0 -> 8

 Solution:

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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        int carrybit = 0;
        ListNode *head = NULL, *cur = NULL;
        while (l1 || l2)
        {
            int sum = carrybit;
            if (l1)
            {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2)
            {
                sum += l2->val;
                l2 = l2->next;
            }
            carrybit = sum / 10;
            if (!head)
            {
                head = new ListNode(sum % 10);
                cur = head;
            }
            else
            {
                ListNode *newnode = new ListNode(sum % 10);
                cur->next = newnode;
                cur = newnode;
            }
        }
        if (carrybit == 1)
        {
            ListNode *newnode = new ListNode(1);
            cur->next = newnode;
        }
        return head;
    }
};
