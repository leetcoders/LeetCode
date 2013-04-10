/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 10, 2013
 Problem:    Remove Duplicates from Sorted List II
 Difficulty: Easy
 Source:     http://leetcode.com/onlinejudge#question_82
 Notes:
 Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
 For example,
 Given 1->2->3->3->4->4->5, return 1->2->5.
 Given 1->1->1->2->3, return 2->3.

 Solution: ...headptr...
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
        ListNode *headptr = new ListNode(0);
        headptr->next = head;
        ListNode *cur = headptr;
        
        int dval = INT_MIN;
        while (cur && cur->next)
        {
            ListNode *nextNode = cur->next;
            ListNode *nextNext;
            while ((nextNext = nextNode->next) && nextNode->val == nextNext->val)
            {
                dval = nextNode->val;
                cur->next = nextNext;
                delete nextNode;
                nextNode = nextNext;
            }
            if (nextNode->val == dval)
            {
                cur->next = nextNext;
                delete nextNode;
            }
            else
            {   
                cur = cur->next;
            }
        }
        
        head = headptr->next;
        delete headptr;
        return head;
    }
};