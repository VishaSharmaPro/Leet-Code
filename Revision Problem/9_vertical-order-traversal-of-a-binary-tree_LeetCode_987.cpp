// google amazon microsoft meta uber bloomberg oracledoordash samsung deliveroo tiktok
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
    map<int,vector<pair<int,int>>> mp;
    void solve(int r,int c,TreeNode* root){
        if(root == nullptr) return;
        mp[c].push_back({r,root->val});
        solve(r+1,c-1,root->left);
        solve(r+1,c+1,root->right);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        solve(0,0,root);
        vector<vector<int>> vec;
        for(auto & it : mp){
            vector<pair<int,int>> temp = it.second;
            sort(temp.begin(),temp.end());
            vector<int> col;
            for(int i = 0;i<temp.size();i++){
                col.push_back(temp[i].second);
            }
            vec.push_back(col);
        }
        return vec;
    }
};

/*
vector<pair<int,int>> temp = it.second;
sort(temp.begin(),temp.end());

Sort kaise hota hai?
sort() on vector<pair<int,int>> by default:

Rule 1: Pehle first ke according sort karo
Rule 2: Agar first equal hai, toh second ke according sort karo
*/
