/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Jul 11, 2013
 Problem:    Unique Binary Search Trees II
 Difficulty: Medium
 Source:     http://leetcode.com/onlinejudge#question_95
 Notes:
 Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.
 For example,
 Given n = 3, your program should return all 5 unique BST's shown below.
 1         3     3      2      1
  \       /     /      / \      \
   3     2     1      1   3      2
  /     /       \                 \
 2     1         2                 3

 Solution: 1. DFS directly. (from the Internet)
           2. DP + DFS. (my solution)
              a. Generate trees for 'n' from 1 to n. (DP)
              b. When generate trees for n = i, get the left and right subtrees 
                 by copying tree structures of dp[1...i-1]. (copy tree uses DFS)
*/

class Solution {
public:
    vector<TreeNode *> generateTrees(int n) {
        return generateTrees_1(n);
    }

    // solution 1
    vector<TreeNode *> generateTrees_1(int n) {
        return generateTreesRe(1, n);
    }

    vector<TreeNode*> generateTreesRe(int l, int r) {
        vector<TreeNode*> res;
        if (l > r) {
            res.push_back(NULL);
            return res;
        }
        for (int k = l; k <= r; k++) {
            vector<TreeNode*> leftTrees = generateTreesRe(l, k-1);
            vector<TreeNode*> rightTrees = generateTreesRe(k+1, r);
            for (size_t i = 0; i < leftTrees.size(); i++) {
                for (size_t j = 0; j < rightTrees.size(); j++) {
                    TreeNode* root = new TreeNode(k);
                    root->left = leftTrees[i];
                    root->right = rightTrees[j];
                    res.push_back(root);
                }
            }
        }
        return res;
    }

    // solution 2
    vector<TreeNode *> generateTrees_2(int n) {
        vector<TreeNode *> dp[n+1];
        dp[0] = vector<TreeNode *>(1, (TreeNode *)NULL);
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= i; ++j)
            {
                for (int m = 0; m < dp[j-1].size(); ++m)
                {
                    for (int k = 0; k < dp[i-j].size(); ++k)
                    {
                        TreeNode *root = new TreeNode(j);
                        CopyTree(dp[j-1][m], root->left, 0);
                        CopyTree(dp[i-j][k], root->right, j);
                        dp[i].push_back(root);
                    }
                }
            }
        }
        return dp[n];
    }

    void CopyTree(TreeNode *original, TreeNode *&newNode, int diff)
    {
        if (!original) return;
        newNode = new TreeNode(original->val + diff);
        CopyTree(original->left, newNode->left, diff);
        CopyTree(original->right, newNode->right, diff);
    }
};
