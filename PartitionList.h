/*
 Author:     Annie Kim, anniekim.pku@gmail.com : King, higuige@gmail.com
 Date:       Apr 9, 2013
 Update:     Oct 7, 2014
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
        ListNode leftdummy(-1);
        ListNode rightdummy(-1);
        ListNode * lhead = &leftdummy;
        ListNode * rhead = &rightdummy;
        
        for(ListNode*cur = head; cur; cur=cur->next){
            if(cur->val<x){
                lhead->next = cur;
                lhead = lhead->next;
            }else{
                rhead->next = cur;
                rhead = rhead->next;
            }
        }
        lhead->next = rightdummy.next;
        rhead->next = nullptr;
        return leftdummy.next;
    }

    ListNode *partition_1(ListNode *head, int x) {
        ListNode dummy(0), *ins = &dummy, *cur = &dummy;
        dummy.next = head;
        while (cur->next) 
        {
            if (cur->next->val >= x)
            {
                cur = cur->next;
            } 
            else 
            {
                if (cur == ins) 
                {
                    cur = cur->next;
                    ins = ins->next;
                } 
                else 
                {
                    ListNode *move = cur->next;
                    cur->next = move->next;
                    move->next = ins->next;
                    ins->next = move;
                    ins = move;
                }
            }
        }
        return dummy.next;
    }
};
