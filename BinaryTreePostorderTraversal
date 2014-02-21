/*
 Author:     Matthew Jin, marthew777@gmail.com
 Date:       
 Problem:    Binary Tree Postorder Traversal 
 Difficulty: Easy
 Source:     http://oj.leetcode.com/problems/
 Notes:
 Given a binary tree, return the postorder traversal of its nodes' values.

 For example:
 Given binary tree {1,#,2,3},
    1
     \
      2
     /
    3
 return [3,2,1].

 Note: Recursive solution is trivial, could you do it iteratively?

 Solution: ...
*/
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> v;
        stack<TreeNode *> s;
        TreeNode *lastV=NULL, *node=root;
        while(node || !s.empty()){
            if(node){
                s.push(node);
                node=node->left;
            }
            else{
                TreeNode *peak=s.top();
                if(peak->right && lastV!=peak->right)
                    node=peak->right;
                else{
                    v.push_back(peak->val);s.pop();
                    lastV=peak;
                }
            }
        }
        return v;
    }
};
