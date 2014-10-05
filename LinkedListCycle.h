/*
 Author:     Annie Kim, anniekim.pku@gmail.com : King, higuige@gmail.com
 Date:       Nov 9, 2013
 Update:     Oct 5, 2014
 Problem:    Linked List Cycle
 Difficulty: Easy
 Source:     http://oj.leetcode.com/problems/linked-list-cycle/
 Notes:
 Given a linked list, determine if it has a cycle in it.
 Follow up:
 Can you solve it without using extra space?

 Solution: two pointers.
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
    bool hasCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) 
        {   
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) return true;
        }
        return false;
    }
};
