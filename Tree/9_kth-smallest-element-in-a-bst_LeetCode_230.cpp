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
// google amazon microsoft blolomberg uber meta oralce linkedin
class Solution {
public:
    int var = 0;
    int ans = 0;
    void solve(TreeNode* root,int k){
        if(root == NULL) return;
        solve(root->left,k);
        var++;
        if(var == k){
            ans = root->val;
            return;
        }
        solve(root->right,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        solve(root,k);
        return ans;
    }
};
