/*
Usage:  Print Edge Nodes (Boundary) of a Binary Tree
Author: Annie Kim
Date:   Aug 18, 2013
Problem Link:   http://leetcode.com/2010/10/print-edge-nodes-boundary-of-binary.html
*/
#include <iostream>
#include <fstream>
//#include "BT__Serialization Deserialization of a Binary Tree.h"
//#include "BT__How to Pretty Print a Binary Tree.h"
#include "Structs.h"
using namespace std;

void printLeftEdges(TreeNode *node);
void printLeafEdges(TreeNode *node);
void printRightEdges(TreeNode *node);

void printEdges(TreeNode *root)
{
    printLeftEdges(root);
    printLeafEdges(root);
    printRightEdges(root->right);
}

void printLeftEdges(TreeNode *node)
{
    if (!node) return;

    if (node->left || node->right)
        cout << node->val << " ";

    if (node->left)
        printLeftEdges(node->left);
    else
        printLeftEdges(node->right);
}

void printLeafEdges(TreeNode *node)
{
    if (!node) return;
    printLeafEdges(node->left);
    if (!node->left && !node->right)
        cout << node->val << " ";
    printLeafEdges(node->right);
}

void printRightEdges(TreeNode *node)
{
    if (!node) return;

    if (node->right)
        printRightEdges(node->right);
    else
        printRightEdges(node->left);

    if (node->left || node->right)
        cout << node->val << " ";
}

/*
int main()
{
    ifstream fin;
    fin.open("C:\\Users\\Administrator\\Desktop\\input.txt");
    TreeNode *root = readBinaryTree(fin);
    printPretty(root, 0, 0, cout);
    fin.close();
    printEdges(root);
    return 0;
}
*/