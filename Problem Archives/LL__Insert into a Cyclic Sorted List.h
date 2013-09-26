/*
Usage:  Insert into a Cyclic Sorted List
Author: Annie Kim
Date:   Aug 19, 2013
Problem Link:   http://leetcode.com/2011/08/insert-into-a-cyclic-sorted-list.html
*/

#include <iostream>
#include "Structs.h"
using namespace std;

void insertIntoSortedCyclicArray(ListNode *&node, int x)
{
    ListNode *newNode = new ListNode(x);
    if (!node) 
    {
        newNode->next = newNode;
        node = newNode;
        return;
    }
    ListNode *prev = node;
    ListNode *cur = node->next;
    while (true)
    {
        if (prev->val <= x && x <= cur->val) break;
        if (prev->val > cur->val && (prev->val < x || x < cur->val)) break;
        if (prev == cur) break;
        prev = cur;
        cur = cur->next;
    }
    newNode->next = cur;
    prev->next = newNode;
}

void printCyclicList(ListNode *head)
{
    if (!head) return;
    cout << head->val << " ";
    ListNode *node = head->next;
    while (node != head)
    {
        cout << node->val << " ";
        node = node->next;
    }
    cout << endl;
}

int main()
{
    ListNode *head = new ListNode(0);
    head->next = new ListNode(2);
    head->next->next = new ListNode(4);
    head->next->next->next = new ListNode(6);
    head->next->next->next->next = new ListNode(7);
    head->next->next->next->next->next = head;
    printCyclicList(head);
    insertIntoSortedCyclicArray(head, 0);
    printCyclicList(head);
    return 0;
}