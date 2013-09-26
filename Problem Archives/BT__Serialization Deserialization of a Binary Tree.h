/*
Usage:  Serialization/Deserialization of a Binary Tree
Author: Annie Kim
Date:   Aug 17, 2013
Problem Link:   http://leetcode.com/2010/09/serializationdeserialization-of-binary.html
*/

#include <iostream>
#include <fstream>
#include <stack>
#include <queue>
#include <vector>
#include <sstream>
//#include "BT__How to Pretty Print a Binary Tree.h"
#include "Structs.h"
using namespace std;

void writeBinaryTree(TreeNode *root, ofstream &fout)
{
    if (!root) return;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode *node = q.front();
        q.pop();
        if (!node)
        {
            fout << "# ";
        }
        else
        {
            fout << node->val << " ";
            q.push(node->left);
            q.push(node->right);
        }
    }
}

bool readNextToken(int &token, ifstream &fin, bool &isnumber)
{
    string s;
    if (fin >> s)
    {
        if (s == "#")
        {
            isnumber = false;
            return true;
        }
        else
        {
            isnumber = true;
            stringstream sstream;
            sstream << s;
            sstream >> token;
            return true;
        }
    }
    return false;
}

TreeNode *readBinaryTree(ifstream &fin)
{
    TreeNode *root = NULL;
    int value;
    bool isnumber;
    if (!readNextToken(value, fin, isnumber) || !isnumber) return NULL;
    else root = new TreeNode(value);

    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode *node = q.front();
        q.pop();
        if (!readNextToken(value, fin, isnumber))
            break;
        if (isnumber)
        {
            node->left = new TreeNode(value);
            q.push(node->left);
        }
        if (!readNextToken(value, fin, isnumber))
            break;
        if (isnumber)
        {
            node->right = new TreeNode(value);
            q.push(node->right);
        }
    }
    return root;
}

/*
int main()
{
    // read
    ifstream fin;
    fin.open("C:\\Users\\Administrator\\Desktop\\output.txt");
    TreeNode *root = readBinaryTree(fin);
    printPretty(root, 1, 0, cout);
    fin.close();
    // write
    printPretty(root, 1, 0, cout);
    ofstream fout;
    fout.open("C:\\Users\\Administrator\\Desktop\\input.txt");
    writeBinaryTree(root, fout);
    fout.close();
    
    return 0;
}
*/