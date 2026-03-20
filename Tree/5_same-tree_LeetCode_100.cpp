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
// google amazon microsoft meta bloomberg adobe linkedin sap apple
class Solution {
public:
    bool flag = true;
    void solve(TreeNode* p,TreeNode* q){
        if(p == NULL && q == NULL){
            return;
        }
        if(p == NULL || q == NULL){
            flag = false;
            return;
        }
        if(p->val != q->val) flag = false; 
        solve(p->left,q->left);
        solve(p->right,q->right);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        solve(p,q);
        return flag;
    }
};
