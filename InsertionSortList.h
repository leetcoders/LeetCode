/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Mar 5, 2014
 Problem:    Insertion Sort List
 Difficulty: Easy
 Source:     http://oj.leetcode.com/problems/insertion-sort-list/
 Notes:
 Sort a linked list using insertion sort.

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
    ListNode *insertionSortList(ListNode *head) {
        ListNode dummy(INT_MIN); 
        dummy.next = head;
        ListNode *cur = &dummy;
        while (cur->next) {
            if (cur->next->val >= cur->val)
                cur = cur->next;
            else
                insert(&dummy, cur, cur->next);
        }
        return dummy.next;
    }
    
    void insert(ListNode *head, ListNode *tail, ListNode *node) {
        ListNode *cur = head;
        while (cur->next->val < node->val)
            cur = cur->next;
        tail->next = node->next;
        node->next = cur->next;
        cur->next = node;
    }
};