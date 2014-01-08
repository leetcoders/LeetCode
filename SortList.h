/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Jan 8, 2014
 Problem:    Sort List
 Difficulty: Medium
 Source:     http://oj.leetcode.com/problems/sort-list/
 Notes:
 Sort a linked list in O(nlogn) time using constant space complexity.

 Solution: merge sort.
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
    ListNode *sortList(ListNode *head) {
        return sortLinkedList(head, getLength(head));
    }
    
    ListNode* sortLinkedList(ListNode *&head, int N) {
        if (N == 0) return NULL;
        if (N == 1) {
            ListNode* cur = head;
            head = head->next;
            cur->next = NULL;
            return cur;
        }
        int half = N / 2;
        ListNode* head1 = sortLinkedList(head, half);
        ListNode* head2 = sortLinkedList(head, N - half);
        return mergeList(head1, head2);
    }
    
    ListNode* mergeList(ListNode *head1, ListNode*head2) {
        ListNode dummy(0); dummy.next = NULL;
        ListNode *cur = &dummy;
        while (head1 && head2)
        {
            ListNode **min = head1->val < head2->val ? &head1 : &head2;
            cur->next = *min;
            cur = cur->next;
            *min = (*min)->next;
        }
        if (!head1) cur->next = head2;
        if (!head2) cur->next = head1;
        return dummy.next;
    }
    
    int getLength(ListNode *head) {
        int length = 0;
        while (head) {
            length++;
            head = head->next;
        }
        return length;
    }
};