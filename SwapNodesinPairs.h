/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 9, 2013
 Problem:    Swap Nodes in Pairs
 Difficulty: Medium
 Source:     http://leetcode.com/onlinejudge#question_24
 Notes:
 Given a linked list, swap every two adjacent nodes and return its head.
 For example,
 Given 1->2->3->4, you should return the list as 2->1->4->3.
 Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.

 Solution: Use recursion instead of normal solution.
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
    ListNode *swapPairs(ListNode *head) {
        swap(head);
        return head;
    }
    
    void swap(ListNode*& node){
        if (!node || !node->next) 
            return;
        ListNode *next = node->next;
        ListNode *nextHead= next->next;
        swap(nextHead);
        next->next = node;
        node->next = nextHead;
        node = next;
    }
};