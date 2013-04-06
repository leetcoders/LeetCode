/*
 Author:     Annie Kim, anniekim.pku@gmail.com
 Date:       Apr 6, 2013
 Problem:    Path Sum 2
 Difficulty: easy
 Source:     http://leetcode.com/onlinejudge#question_113
 Notes:
 Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

 For example:
 Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
 return
 [
   [5,4,11,2],
   [5,8,4,5]
 ]
 
 Solution: In addition to 'Path Sum', the recursion function needs one more parameter
           to store the root->leaf path.
 */

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    vector<vector<int> > res;
    
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<int> v;
        res.clear();
        pathSum(root, v, sum);
        return res;
    }
    
    void pathSum(TreeNode *root, vector<int> vec, int sum) {
        if (!root)
            return;
        if (root->left == NULL and root->right == NULL) // leaf node
        { 
            if (sum == root->val)
            {
                vec.push_back(root->val);
                res.push_back(vec);
            }
            return;
        }
        vec.push_back(root->val);
        pathSum(root->left, vec, sum - root->val);
        pathSum(root->right, vec, sum - root->val);
    }
};