/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* result = nullptr;
    
    int dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr) return 0;
        
        int left = dfs(root->left, p, q);
        int right = dfs(root->right, p, q);
        
        // Current node is one of p or q
        int current = (root->val == p->val || root->val == q->val) ? 1 : 0;
        
        // If any two of left, right, current are true, this is LCA
        if(left + right + current == 2) {
            result = root;
        }
        
        // Return whether we found p or q in this subtree
        return ( left + right + current > 0);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);
        return result;
    }
};
