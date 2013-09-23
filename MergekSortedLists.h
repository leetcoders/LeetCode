/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 6, 2013
 Update:     Sep 22, 2013
 Problem:    Merge k Sorted Lists
 Difficulty: easy
 Source:     http://leetcode.com/onlinejudge#question_23
 Notes:
 Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
 
 Solution: Find the smallest list-head first using minimum-heap(lgk).
           complexity: O(NlgK)
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Mycompare {
public:
    bool operator()(ListNode *a, ListNode *b) {
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        priority_queue<ListNode *, vector<ListNode *>, Mycompare> q;
        for (int i = 0; i < lists.size(); ++i)
            if (lists[i])
                q.push(lists[i]);
        
        ListNode dummy(0), *cur = &dummy;
        while (!q.empty()) {
            ListNode *node = q.top();
            q.pop();
            cur = cur->next = node;
            if (node->next)
                q.push(node->next);
        }
        return dummy.next;
    }
};
