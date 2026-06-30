/*
Amazon (8), Google (3), Bloomberg (3), Microsoft (2), Meta (3), Adobe (3), TikTok (2), DoorDash (80), Salesforce (8), Oracle (7), Yandex (7), Apple (4), Uber (4), TCS (3), Goldman Sachs (3), Citadel (3), Datadog (3)
*/
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
int maxi = INT_MIN;
    int dfs(TreeNode* root){
        if(root == NULL) return 0;
        int leftsum = dfs(root->left);
        int rightsum = dfs(root->right);
        maxi = max({maxi,leftsum + rightsum + root->val,root->val,root->val + max(leftsum,rightsum)});
        return (root->val) + max({0,leftsum,rightsum});
    }
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return maxi;
    }
};
