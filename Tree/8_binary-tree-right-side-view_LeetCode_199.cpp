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
// google amazon microsoft meta bloomberg uber apple tiktok servicenow wix yandex walmart visa oracle
class Solution {
public:
    vector<int> ans;
    vector<int> check;
    void solve(TreeNode* root,int lev){
        if(root == NULL) return;
        if(lev >= check.size()){
            check.resize(lev+1,0);
        }
        if(check[lev] == 0){
            ans.push_back(root->val);
            check[lev] = 1;
        }
        solve(root->right,lev+1);
        solve(root->left,lev+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        solve(root,0);
        return ans;
    }
};
