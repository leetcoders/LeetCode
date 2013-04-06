/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Jan 16, 2013
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
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        ListNode *head = NULL;
        ListNode *ptr = new ListNode(0);
        
        int carrybit = 0;
        while (l1 || l2)
        {
            int sum = 0;
        
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
            
            sum += carrybit;
            carrybit = sum / 10;
            
            if (!head)
            {
                head = new ListNode(sum%10);
                ptr->next = head;
            }
            else
            {
                ListNode *node = new ListNode(sum%10);
                ptr->next->next = node;
                ptr->next = node;
            }
        }
        
        if (carrybit == 1)
        {
            ListNode *node = new ListNode(1);
            ptr->next->next = node;
        }
        
        return head;
    }
};