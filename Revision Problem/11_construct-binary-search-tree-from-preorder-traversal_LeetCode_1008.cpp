 // google amazon microsoft meta bloomberg
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
class Solution {
public:
    void solve(int &i,TreeNode* root,vector<int>& preorder,int min,int max){
        if(i>=preorder.size()) return;
        if(preorder[i] < min || preorder[i] > max) return;
        if(preorder[i] < root->val){
            root->left = new TreeNode(preorder[i++]);
            solve(i,root->left, preorder, min, root->val);
            solve(i,root, preorder, root->val, max);  // right bhi check 
        }else{
            root->right = new TreeNode(preorder[i++]);
            solve(i,root->right, preorder, root->val, max);
        }
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode * root = new TreeNode(preorder[0]);
        int i = 1;
        solve(i,root,preorder,INT_MIN,INT_MAX);
        return root;
    }
};
