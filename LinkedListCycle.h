/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Nov 9, 2013
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
        if (!head || !head->next) return false;
        ListNode *back = head, *front = head->next->next;
        while (true) 
        {
            if (front == back) return true;
            if (!front || !front->next) return false;
            front = front->next->next;
            back = back->next;
        }
    }
};