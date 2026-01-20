// company = Meta , microsfot , amazon , google ,oracle , uber , servicenow , bloomberg
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
    void preorder(TreeNode * root,int lev,vector<int> & res){
        if(root == NULL) return;
        if(res[lev] == -1) res[lev] = root->val;
        preorder(root->right,lev+1,res);
        preorder(root->left,lev+1,res);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res(101,-1);
        preorder(root,0,res);
        vector<int> ans;
        for(int i = 0;i<res.size();i++){
            if(res[i] != -1) ans.push_back(res[i]);
        }
        return ans;
    }
};
