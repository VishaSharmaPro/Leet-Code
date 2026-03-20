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
// amazon meta bloomberg google microsoft  oracle millenium apple yandex salesforce uber ibm yahoo yandex goldman wix
class Solution {
public:
    TreeNode* prev = NULL;
    bool flag = true;
    void solve(TreeNode* root){
        if(root == NULL || !flag) return;
        solve(root->left);
        if(prev != NULL && root->val <= prev->val){
            flag = false;
            return;
        }
        prev = root;
        solve(root->right);
    }
    bool isValidBST(TreeNode* root) {
        if(root == NULL) return true;
        if(root->left == NULL && root->right == NULL) return true;
        solve(root);
        return flag;
    }
};
