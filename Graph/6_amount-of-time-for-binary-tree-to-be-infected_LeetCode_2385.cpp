// google amazon microsoft bloomberg adobe uber goldman blinkit flipkart
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
    int maxval = INT_MIN;
    void convert(TreeNode* root, int parent,unordered_map<int,vector<int>> &mp){
        if(root == NULL) return;
        maxval = max(maxval,root->val);
        if(parent != 0) mp[root->val].push_back(parent);
        if(root->left != NULL) mp[root->val].push_back(root->left->val);
        if(root->right != NULL) mp[root->val].push_back(root->right->val);
        convert(root->left,root->val,mp);
        convert(root->right,root->val,mp);
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int,vector<int>> mp;
        convert(root,0,mp);
        vector<bool> vis(maxval,false);
        queue<int> q;
        q.push(start);
        vis[start] = true;
        int step = 0;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int curr = q.front();
                q.pop();
                for(auto & ne : mp[curr]){
                    if(!vis[ne]){
                        q.push(ne);
                        vis[ne] = true;
                    }
                }
            }
            step++;
        }
        return step-1;
    }
};
