/*
Usage:  Detecting a Loop in a Singly Linked List
Author: Annie Kim
Date:   Aug 19, 2013
Problem Link:   http://leetcode.com/2010/09/detecting-loop-in-singly-linked-list.html
*/
#include <iostream>
#include "Structs.h"
using namespace std;

bool hasLoop(ListNode *head) 
{
    if (!head) return false;
    ListNode *slow = head, *fast = head->next;
    while (fast && fast != slow)
    {
        fast = fast->next ? fast->next->next : NULL;
        slow = slow->next;
    }
    if (slow == fast)
        return true;
    return false;
}
/*
int main()
{
    ListNode *head = new ListNode(0);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = head->next;
    cout << boolalpha << hasLoop(head);
    return 0;
}
*/

