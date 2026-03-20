/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// google amazon meta bloomberg micrososft visa capgemini
class Solution {
public:
    bool flag = true;
    int solve(TreeNode* root){
        if(root == NULL) return 0;
        int lefth = solve(root->left);
        int righth = solve(root->right);
        if(abs(lefth - righth) >1){
            flag = false;
        }
        return 1 + max(lefth,righth);
    }
    bool isBalanced(TreeNode* root) {
        solve(root);
        return flag;
    }
};
