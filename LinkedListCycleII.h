/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Nov 15, 2013
 Problem:    Linked List Cycle II
 Difficulty: Easy
 Source:     http://oj.leetcode.com/problems/linked-list-cycle-ii/
 Notes:
 Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
 Follow up:
 Can you solve it without using extra space?

 Solution: two pointers. 1. check cycle. 2. get cycle length. 3. find entry.
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
        if (!head || !head->next) return NULL;
        ListNode *slow = head, *fast = head->next->next;
        while (true) {
            if (fast == slow) break;
            if (!fast || !fast->next) return NULL;
            fast = fast->next->next;
            slow = slow->next;
        }
        
        int cycleLength = 1;
        slow = slow->next;
        while (slow != fast) {
            slow = slow->next;
            cycleLength++;
        }
        
        slow = fast = head;
        while (cycleLength--)
            fast = fast->next;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};