/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 10, 2013
 Update:     Dec 12, 2014
 Problem:    Remove Duplicates from Sorted List II
 Difficulty: Easy
 Source:     https://oj.leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
 Notes:
 Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
 For example,
 Given 1->2->3->3->4->4->5, return 1->2->5.
 Given 1->1->1->2->3, return 2->3.

 Solution: 1. iterative 2. recursive
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
    ListNode *deleteDuplicates(ListNode *head) {
        return deleteDuplicates_1(head);
    }
    
    ListNode *deleteDuplicates_1(ListNode *head) {
        if(NULL==head||NULL==head->next) return head;
        ListNode dummy(-1);
        ListNode * pre = &dummy;
        while(head!=NULL){
            if(head->next&&head->val==head->next->val){
                while(head->next&&head->val==head->next->val) {
                    ListNode *del = head;
                    head = head->next;
                    delete del;
                }
            }else{
                pre->next = head;
                pre = pre->next;
            }
            head = head->next;
        }
        pre->next = NULL;
        return dummy.next;
    }
    
    ListNode *deleteDuplicates_2(ListNode *head) {
        if (!head) return NULL;
        if (!head->next || head->val != head->next->val) {
            head->next = deleteDuplicates(head->next);
            return head;
        }
        int val = head->val;
        while(head->next&&head->val==head->next->val) {
            ListNode *del = head;
            head = head->next;
            delete del;
        }
        return deleteDuplicates(head->next);
    }
};