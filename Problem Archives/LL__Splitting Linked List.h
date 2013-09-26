/*
Usage:  Splitting Linked List
Author: Annie Kim
Date:   Aug 19, 2013
Problem Link:   http://leetcode.com/2010/09/splitting-linked-list.html
*/
#include <iostream>
#include "Structs.h"
using namespace std;

void frontBackSplit(ListNode *head, ListNode *&front, ListNode *&back) 
{
    if (!head) return;
    ListNode *fast = head;
    ListNode *slow = head;
    while (true)
    {
        if (!fast->next || !fast->next->next)
            break;
        fast = fast->next->next;
        slow = slow->next;
    }
    front = head;
    back = slow->next;
    slow->next = NULL;
}

void printList(ListNode *node)
{
    while (node)
    {
        cout << node->val << " ";
        node = node->next;
    }
    cout << endl;
}

/*
int main()
{
    ListNode *head = new ListNode(0);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(4);
    printList(head);

    ListNode *front = NULL, *back = NULL;
    frontBackSplit(head, front, back);
    printList(front);
    printList(back);

    return 0;
}
*/

