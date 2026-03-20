/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// google amazon microsoft meta bloomberg linkedin x yandex apple
class Solution {
public:
    TreeNode* king = NULL;
    bool solve(TreeNode* root,TreeNode* p,TreeNode* q){
        if(root == NULL) return false;
        if(root == p || root == q){
            if(king == NULL) king = root;
            return true;
        }
        bool left = solve(root->left,p,q);
        bool right = solve(root->right,p,q);
        if(left && right){
            king = root;
        }
        return left || right;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        solve(root,p,q);
        return king;
    }
};
