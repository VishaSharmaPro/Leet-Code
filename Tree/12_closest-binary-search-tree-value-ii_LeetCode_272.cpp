// linkedin google amazon
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
// method 1
class Solution {
public:
    typedef pair<double,int> p;
    priority_queue<p,vector<p>,greater<p>> pq;
    void solve(TreeNode* root,double target){
        if(root == NULL) return;
        int val = root->val;
        double diff = abs(val-target);
        pq.push({diff,val});
        solve(root->left,target);
        solve(root->right,target);
    }
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        solve(root,target);
        vector<int> ans;
        while(k--){
            int val = pq.top().second;
            ans.push_back(val);
            pq.pop();
        }
        return ans;
    }
};

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

// method 2
class Solution {
public:
    typedef pair<double,int> p;
    priority_queue<p> pq;
    void solve(TreeNode* root,double target,int k){
        if(root == NULL) return;
        int val = root->val;
        double diff = abs(val-target);
        pq.push({diff,val});
        while(pq.size() > k) pq.pop();
        solve(root->left,target,k);
        solve(root->right,target,k);
    }
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        solve(root,target,k);
        vector<int> ans;
        while(!pq.empty()){
            int val = pq.top().second;
            ans.push_back(val);
            pq.pop();
        }
        return ans;
    }
};
