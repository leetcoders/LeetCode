/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 6, 2013
 Problem:    Merge k Sorted Lists
 Difficulty: easy
 Source:     http://leetcode.com/onlinejudge#question_23
 Notes:
 Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
 
 Solution: Find the smallest list-head first using minimum-heap(lgk).
           complexity: N*lgk
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct Compare
{
    bool operator ()(const ListNode* a, const ListNode* b)
    {
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        ListNode *head = NULL;
        ListNode *cur;
        
        priority_queue<ListNode *, vector<ListNode *>, Compare> min_heap;
        for (size_t i = 0; i < lists.size(); i++)
        {
            if (lists[i])
                min_heap.push(lists[i]);
        }
        
        while (min_heap.size() > 0)
        {
            ListNode* min = min_heap.top();
            min_heap.pop();
            
            if (!head)
            {
                head = min;
                cur = head;
            }
            else
            {
                cur->next = min;
                cur = min;
            }
            
            min = min->next;
            if (min)
                min_heap.push(min);
        }
        
        return head;
    }
};