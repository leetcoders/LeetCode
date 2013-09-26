/*
Usage:  Binary Search Tree In-Order Traversal Iterative Solution (with parent node) O(1) space
Author: Annie Kim
Date:   Aug 18, 2013
Problem Link:   http://leetcode.com/2010/04/binary-search-tree-in-order-traversal.html
*/
#include <iostream>
#include <queue>
#include "Structs.h"
using namespace std;

void inorderTraversal(TreeNodeP *root)
{
    TreeNodeP *last = NULL;
    TreeNodeP *node = root;
    while (node)
    {
        if (last == node->right)
        {
            last = node;
            node = node->parent;
        }
        else if (last == node->left || !node->left)
        {
            cout << node->val << " ";
            last = node;
            if (node->right)
                node = node->right;
            else
                node = node->parent;
        }
        else if (node->left)
        {
            last = node;
            node = node->left;
        }
    }
}

TreeNodeP *buildTree_withparent(int value[], int n)
{
    if (n == 0) return NULL;
    TreeNodeP *root = new TreeNodeP(value[0], NULL);
    queue<TreeNodeP *> q;
    q.push(root);
    int i = 1;
    while (i < n)
    {
        TreeNodeP *node = q.front();
        q.pop();
        int left = value[i++];
        int right = (i >= n) ? -1 : value[i++];
        if (left != -1)
        {
            TreeNodeP *newNode = new TreeNodeP(left, node);
            node->left = newNode;
            q.push(newNode);
        }
        if (right != -1)
        {
            TreeNodeP *newNode = new TreeNodeP(right, node);
            node->right = newNode;
            q.push(newNode);
        }
    }
    return root;
}

/*
int main()
{
    int values[] = {28, 4, 69, -1, 8, 56, -1, 7, 12, 34, 27, -1, -1, 5, 13, 2, -1, 3, 39, -1, 6, 11, -1, 10, -1, 9};
    TreeNodeP *root = buildTree_withparent(values, 26);
    inorderTraversal(root);
    return 0;
}
*/