/*
 Author:     King, wangjingui@outlook.com
 Date:       Nov 28, 2014
 Problem:    Intersection of Two Linked Lists 
 Difficulty: Easy
 Source:     https://oj.leetcode.com/problems/intersection-of-two-linked-lists/

 Notes:
 Write a program to find the node at which the intersection of two singly linked lists begins.
 Hints:
    If the two linked lists have no intersection at all, return null.
    The linked lists must retain their original structure after the function returns.
    You may assume there are no cycles anywhere in the entire linked structure.
    Your code should preferably run in O(n) time and use only O(1) memory.


 Solution: Two iteration.
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode * cur = NULL;
        int lenA = 0, lenB = 0;
        cur = headA;
        while (cur) {
            ++lenA;
            cur = cur->next;
        }
        cur = headB;
        while (cur) {
            ++lenB;
            cur = cur->next;
        }
        if (lenA >= lenB) {
            int diff = lenA - lenB;
            while (diff > 0) {
                headA = headA->next;
                --diff;
            }
            while (headA && headB) {
                if(headA == headB) {
                    return headA;
                }
                headA = headA->next;
                headB = headB->next;
            }
        } else {
            int diff = lenB - lenA;
            while (diff > 0) {
                headB = headB->next;
                --diff;
            }
            while (headA && headB) {
                if(headA == headB) {
                    return headA;
                }
                headA = headA->next;
                headB = headB->next;
            }
        }
        return NULL;
    }
};