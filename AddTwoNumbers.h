/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Jan 16, 2013
 Update:     Sep 22, 2013
 Problem:    Add Two Numbers
 Difficulty: easy
 Source:     http://www.leetcode.com/onlinejudge
 Notes:
 You are given two linked lists representing two non-negative numbers. 
 The digits are stored in reverse order and each of their nodes contain a single digit. 
 Add the two numbers and return it as a linked list.

 Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 Output: 7 -> 0 -> 8

 Solution: dummy head...

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
        ListNode dummy(0), *cur = &dummy;
        int carry = 0;
        while (l1 || l2 || carry)
        {
            int sum = carry;
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }
            carry = sum >= 10 ? 1 : 0;
            sum %= 10;
            ListNode *newNode = new ListNode(sum);
            cur->next = newNode;
            cur = newNode;
        }
        return dummy.next;
    }
};
