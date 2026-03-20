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
// google amazon microsoft meta bloomberg linkedin avito yahoo apple accenture oracle uber qualcomm aristanetwork
class Solution {
public:
    int d = 0;
    void solve(int lev, TreeNode* root){
        if(root == NULL) return;
        d = max(d,lev);
        solve(lev+1,root->left);
        solve(lev+1,root->right);
    }
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        if(root->left == NULL && root->right == NULL) return 1;
        solve(1,root);
        return d;
    }
};
