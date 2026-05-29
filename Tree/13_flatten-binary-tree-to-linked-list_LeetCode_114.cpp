// google amazon microsoft meta bloomberg oracle anduril josh technology
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
    vector<int> vec;
    void solve(TreeNode* root){
        if(root == NULL) return;
        vec.push_back(root->val);
        solve(root->left);
        solve(root->right);
    }
    void solve2(TreeNode* root, int i){
        if(i >= vec.size()) return;
        TreeNode* curr = new TreeNode(vec[i]);
        root->right = curr;
        solve2(curr, i+1);
    }
    void flatten(TreeNode* root) {
        if(root == NULL) return;
        solve(root);
        root->left = NULL;
        root->right = NULL;
        solve2(root, 1);
    }
};
