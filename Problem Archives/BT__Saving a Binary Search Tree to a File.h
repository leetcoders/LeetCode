/*
Usage:  Saving a Binary Search Tree to a File
Author: Annie Kim
Date:   Aug 17, 2013
Problem Link:   http://leetcode.com/2010/09/saving-binary-search-tree-to-file.html
*/

#include <iostream>
#include <fstream>
#include <stack>
//#include "BT__How to Pretty Print a Binary Tree.h"
#include "Structs.h"s
using namespace std;

void save(TreeNode *root, ofstream &fout)
{
    if (!root) return;
    fout << root->val << " ";
    save(root->left, fout);
    save(root->right, fout);
}

TreeNode *load_recursive_helper(int low, int high, int &value, ifstream &fin)
{
    if (value < low || value > high) return NULL;
    TreeNode *newNode = new TreeNode(value);
    if (fin >> value)
    {
        newNode->left = load_recursive_helper(low, newNode->val, value, fin);
        newNode->right = load_recursive_helper(newNode->val, high, value, fin);
    }
    return newNode;
}

TreeNode *load_recursive(ifstream &fin)
{
    int value;
    if (fin >> value)
        return load_recursive_helper(INT_MIN, INT_MAX, value, fin);
    else
        return NULL;
}

TreeNode *load_iterative(ifstream &fin)
{
    stack<TreeNode *> stk;
    int value;
    TreeNode *root;
    while(fin >> value)
    {
        if (stk.empty())
        {
            root = new TreeNode(value);
            stk.push(root);
        }
        else
        {
            TreeNode *newNode = new TreeNode(value);
            if (value < stk.top()->val)
            {
                stk.top()->left = newNode;
                stk.push(newNode);
            }
            else
            {
                TreeNode *top;
                while (!stk.empty() && stk.top()->val < value)
                {
                    top = stk.top();
                    stk.pop();
                }
                top->right = newNode;
                stk.push(newNode);
            }
        }
    }
    return root;
}

/*
int main()
{
    // read
    ifstream fin;
    fin.open("C:\\Users\\Administrator\\Desktop\\input.txt");
    TreeNode *root = load_recursive(fin);
    printPretty(root, 1, 0, cout);
    fin.close();
    // write
    ofstream fout;
    fout.open("C:\\Users\\Administrator\\Desktop\\output.txt");
    save(root, fout);
    fout.close();
    return 0;
}
*/