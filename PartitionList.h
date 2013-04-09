/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 9, 2013
 Problem:    Partition List
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_86
 Notes:
 Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
 You should preserve the original relative order of the nodes in each of the two partitions.
 For example,
 Given 1->4->3->2->5->2 and x = 3,
 return 1->2->2->4->3->5.

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
    ListNode *partition(ListNode *head, int x) {
        if (!head) return head;
        
        ListNode *headptr = new ListNode(0);
        headptr->next = head;
        ListNode *cur = headptr;
        ListNode *ins = headptr;  // insert position
        
        while (cur->next) 
        {
            ListNode *del = cur->next;
            if (del->val >= x){
                cur = cur->next;
            } else {
                if (cur == ins) {
                    cur = cur->next;
                } else {
                    cur->next = del->next;
                    del->next = ins->next;
                    ins->next = del;
                }
                ins = ins->next;
            }
        }
        
        head = headptr->next;
        delete headptr;
        return head;
    }
};