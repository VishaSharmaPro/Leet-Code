/*
Amazon (3), Google (2), Microsoft (2), Apple (2), Meta (6), LinkedIn (2), Salesforce (6), Bloomberg (5), Okta (4), Oracle (3), TikTok (3), Flipkart (2), Wix.
*/
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
    unordered_map<TreeNode*,vector<TreeNode*>> mp;
    void dfs(TreeNode* root){
        if(root == NULL) return;
        if(root->left != NULL){
            mp[root].push_back(root->left);
            mp[root->left].push_back(root);
        }
        if(root->right != NULL){
            mp[root].push_back(root->right);
            mp[root->right].push_back(root);
        } 
        dfs(root->left);
        dfs(root->right);
    }
    vector<int> ans;
    unordered_map<TreeNode*,bool> vis;
    void bfs(TreeNode* node,int k){
        queue<TreeNode*> q;
        q.push(node);
        vis[node] = true;
        while(!q.empty()){
            int sz = q.size();
            if(k == 0){
                while(sz--){
                    ans.push_back(q.front()->val);
                    q.pop();
                }
                return;
            }
            while(sz--){
                auto curr = q.front();
                q.pop();
                for(auto & ne : mp[curr]){
                    if(!vis[ne]){
                        vis[ne] = true;
                        q.push(ne);
                    }
                }
            }
            k--;
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        dfs(root);
        bfs(target,k);
        return ans;
    }
};
