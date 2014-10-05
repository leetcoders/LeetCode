/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Oct 5, 2013
 Problem:    Copy List with Random Pointer
 Difficulty: Easy
 Source:     http://oj.leetcode.com/problems/copy-list-with-random-pointer/
 Notes:
 A linked list is given such that each node contains an additional random pointer 
 which could point to any node in the list or null.
 Return a deep copy of the list.

 Solution: Solution 1 uses constant extra space.
*/

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
    typedef unordered_map<RandomListNode*, RandomListNode*> nodemap;
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        return copyRandomList_1(head);
    }
    
    RandomListNode *copyRandomList_1(RandomListNode *head) {
        for (RandomListNode *cur = head; cur; cur = cur->next->next) {
            RandomListNode *newNode = new RandomListNode(cur->label);
            newNode->next = cur->next;
            cur->next = newNode;
        }
        
        for (RandomListNode *cur = head; cur; cur = cur->next->next)
            if (cur->random)
                cur->next->random = cur->random->next;
        
        RandomListNode dummy(0), *curNew = &dummy;
        for (RandomListNode *cur = head; cur; cur = cur->next) {
            curNew->next = cur->next;
            curNew = curNew->next;
            cur->next = cur->next->next;
        }
        return dummy.next;
    }
    
    RandomListNode *copyRandomList_2(RandomListNode *head) {
        if (!head) return NULL;
        unordered_map<RandomListNode *, RandomListNode *> map;
        RandomListNode dummy(0), *curNew = &dummy, *cur = head;
        while (cur) 
        {
            if (map.find(cur) == map.end())
                map[cur] = new RandomListNode(cur->label);
            if (cur->random && map.find(cur->random) == map.end())
                map[cur->random] = new RandomListNode(cur->random->label);
            curNew->next = map[cur];
            curNew = curNew->next;
            curNew->random = map[cur->random];
            cur = cur->next;
        }
        return dummy.next;
    }
    RandomListNode *copyRandomList_3(RandomListNode *head) {
        nodemap m;
        return copy(head, m);
    }
    RandomListNode *copy(RandomListNode *root, nodemap &m) {
        if (root == nullptr) return nullptr;
        nodemap::iterator iter = m.find(root);
        if (iter != m.end()) {
            return m[root];
        }
        RandomListNode *node = new RandomListNode(root->label);
        m[root] = node;
        node->next = copy(root->next, m);
        node->random = copy(root->random, m);
        return node;   
    }
};
