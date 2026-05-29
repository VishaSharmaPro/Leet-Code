// google amazon microsoft meta bloomberg oracle andruil josh technology
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
    void solve(TreeNode* root){
        if(root == NULL) return;
        
        solve(root->left);                    // pehle left flatten karo
        solve(root->right);                   // phir right flatten karo
        
        if(root->left){
            TreeNode* temp = root->left;
            while(temp->right) temp = temp->right;  // left ka tail dhundo
            temp->right = root->right;        // right ko left ke tail se jodo
            root->right = root->left;         // left ko right mein lao
            root->left = NULL;                // left NULL karo
        }
    }
    void flatten(TreeNode* root) {
        solve(root);
    }
};
