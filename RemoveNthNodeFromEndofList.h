/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 10, 2013
 Update:     Sep 27, 2013
 Problem:    Remove Nth Node From End of List
 Difficulty: Medium
 Source:     http://leetcode.com/onlinejudge#question_19
 Notes:
 Given a linked list, remove the nth node from the end of list and return its head.
 For example,
 Given linked list: 1->2->3->4->5, and n = 2.
 After removing the second node from the end, the linked list becomes 1->2->3->5.
 Note:
 Given n will always be valid.
 Try to do this in one pass.

 Solution: head---back------front------>NULL
                   |          |
                   ---> n <----
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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode dummy(0), *back = &dummy, *front = &dummy;
        dummy.next = head;
        while (n--) front = front->next;
        while (front->next) {
            front = front->next;
            back = back->next;
        }
        ListNode *del = back->next;
        back->next = del->next;
        delete del;
        return dummy.next;
    }
    ListNode *removeNthFromEnd_2(ListNode *head, int n) {
        if(head==NULL) return head;
        ListNode *slow = head, *fast = head;
        while(n--) fast = fast->next;
        if (fast == NULL) return head->next;
        while(fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return head;
    }
};