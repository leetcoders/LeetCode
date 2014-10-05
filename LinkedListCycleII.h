/*
 Author:     Matthew Jin, marthew777@gmail.com
 Date:       Feb 21, 2014
 Problem:    Linked List Cycle II
 Difficulty: Easy
 Source:     http://oj.leetcode.com/problems/linked-list-cycle-ii/
 Notes:
 Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
 Follow up:
 Can you solve it without using extra space?

 Solution: From Matthew. Simpler.
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
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL) return NULL;
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) break;
        }
        
        if (fast == NULL || fast->next == NULL) return NULL;
        
        fast = head;
        while (fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }
        
        return slow;
    }
};
